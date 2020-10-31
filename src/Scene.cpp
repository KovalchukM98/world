#include "Scene.h"

using namespace std;

Scene::Scene() {
	is_game_over = true;
	window.create(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "My world");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(80);

	max_x = WINDOW_SIZE_X / size_x;
	max_y = WINDOW_SIZE_Y / size_y;

	field = new Object * *[max_x];
	for (int i = 0; i < max_x; ++i) {
		field[i] = new Object * [max_y];
	}
	all_food = 80;
	step = 0;
};

Scene::~Scene() {
	window.close();
	clear(field, max_x, max_y);
};

void Scene::start() {
	is_game_over = false;
	generate_field();

	// sf::SoundBuffer buffer;
	// sf::Sound music;
	// if (!music.openFromFile("training.wav")){
	//     return;
	// }
	// music.play();

	float timer = 0;
	float delay = 1.0f;
	while (window.isOpen())
	{
		move_objects();

		check_food();

		window.clear();

		draw();

		window.display();
		while (timer < delay) {
			timer = clock.getElapsedTime().asSeconds();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed ||
					(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
					window.close();
			}
		}
		clock.restart();
		timer = 0;
	}

}

Object*** Scene::get_vision(int range, int x, int y) {
	Object*** vision = NULL;
	int vis_size = range * 2 + 1;
	vision = new Object * *[vis_size];
	for (int i = 0; i < vis_size; ++i) {
		vision[i] = new Object * [vis_size];
		for (int j = 0; j < vis_size; ++j) {
			vision[i][j] = NULL;
		}
	}

	for (int i = x - range, i1 = 0; i1 < vis_size; ++i, ++i1) {
		for (int j = y - range, j1 = 0; j1 < vis_size; ++j, ++j1) {
			if (i < 0 || j < 0 || i > max_x - 1 || j > max_y - 1) {
				vision[i1][j1] = NULL;
			}
			else {
				vision[i1][j1] = field[i][j];
			}
		}
	}
	int temp_left = range;
	int temp_right = range + 1;
	for (int i = 0; i < range; ++i) {
		for (int j = 0; j < temp_left; ++j) {
			vision[i][j] = NULL;
		}
		for (int j = temp_right; j < vis_size; ++j) {
			vision[i][j] = NULL;
		}
		++temp_right;
		--temp_left;
	}

	temp_right = range;
	temp_left = range;
	for (int i = vis_size - 1; i > range; --i) {
		for (int j = 0; j < temp_left; ++j) {
			vision[i][j] = NULL;
		}
		for (int j = vis_size - 1; j > temp_right; --j) {
			vision[i][j] = NULL;
		}
		++temp_right;
		--temp_left;
	}

	return vision;
}

bool Scene::action(Object** agressor, Object** defender) {
	if(*agressor == *defender){
		return false;
	}
	if (*defender == NULL) {
		*defender = *agressor;
		*agressor = NULL;
		return true;
	}
	else{
		if((*agressor)->get_name() == "Wolf" && (*defender)->get_name() == "Food") {
			hidden_food.push_back(*defender);
			*defender = *agressor;
			*agressor = NULL;
			return true;
		}
		else if((*agressor)->get_name() == (*defender)->get_name()) {
			Object* tmp = *agressor;
			*agressor = *defender;
			*defender = tmp;
			return true;
		}
		else{
			delete* defender;
			(*agressor)->feed();
			*defender = *agressor;
			*agressor = NULL;
			return true;
		}
	}
	return false;
}

void Scene::move_objects() {
	for (int i = 0; i < max_x; ++i) {
		for (int j = 0; j < max_y; ++j) {
			if (field[i][j] != NULL) {
				if (field[i][j]->is_Alive) {
					Object*** vision = get_vision(field[i][j]->get_range(), i, j);
					std::pair<int, int>coords = field[i][j]->move(vision, max_x, max_y);
					for (int k = 0; k < (field[i][j]->get_range()) * 2 + 1; ++k) {
						delete[] vision[k];
					}
					delete[] vision;

					if (field[i][j]->is_dead() == true) {
						delete field[i][j];
						corpses.push_back(Corpse(i, j));
						field[i][j] = NULL;
					}
					action(&field[i][j], &field[coords.first][coords.second]);
				}
			}
		}
	}

	for (int i = 0; i < max_x; ++i) {
		for (int j = 0; j < max_y; ++j) {
			if (field[i][j] != NULL) {
				if (field[i][j]->is_Alive) {
					field[i][j]->give_turn();
				}
			}
		}
	}
}


void Scene::draw() {
	for (int i = 0; i < hidden_food.size();){
		if(field[hidden_food[i]->get_x()][hidden_food[i]->get_y()] == NULL) {
			field[hidden_food[i]->get_x()][hidden_food[i]->get_y()] = hidden_food[i];
			hidden_food.erase(hidden_food.begin()+i);
		}
		else{
			hidden_food[i]->draw(&window, size_x);
			++i;
		}
	}

	for (int i = 0; i < max_x; ++i) {
		for (int j = 0; j < max_x; ++j) {
			sf::Texture grass;
			grass.loadFromFile("grass.png");
			sf::Sprite grasssp;
			grasssp.setTexture(grass);
			grasssp.setPosition(i * size_x, j * size_y);
			window.draw(grasssp);
			if (field[i][j] != NULL) {
				field[i][j]->draw(&window, size_x);
			}
		}
	}

	for (int i = 0; i < corpses.size();)
	{
		if (corpses[i].is_rotten()) {
			corpses.erase(corpses.begin() + i);
		}
		else {
			corpses[i].draw(&window, size_x);
			++i;
		}
	}

	/*for (std::vector<Corpse>::iterator it = corpses.begin(); it != corpses.end();) {
		if ((*it).is_rotten()) {
			corpses.erase(it);
		}
		else {
			(*it).draw(&window, size_x);
			++it;
		}
	}*/

}

void Scene::check_event() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			is_game_over = true;
			break;

		case sf::Event::KeyPressed:
			check_key(event);
			break;
		}
	}
};

void Scene::check_key(sf::Event event) {
	switch (event.key.code) {
	case sf::Keyboard::Escape:
		window.close();
		is_game_over = true;
		break;
	}
};

void Scene::generate_field() {
	bool wolf = false;
	sheep_count = 0;
	food_count = 0;
	for (int i = 0; i < max_x; ++i) {
		for (int j = 0; j < max_y; ++j) {
			if (rand() % 10 == 2) {
				if (rand() % 3 == 1) {
					field[i][j] = new Lake(i, j);
				}
				else {
					field[i][j] = new Stone(i, j);
				}
			}
			else
				if (rand() % 10 == 1) {
					field[i][j] = new Sheep(i, j); sheep_count++;
				}
				else
				{
					if (wolf == false) {
						wolf = true;
						field[i][j] = new Wolf(i, j);
					}
					else
						field[i][j] = NULL;
				}
		}
	}

	for (int i = 0; i < max_x; ++i) {
		for (int j = 0; j < max_y; ++j) {
			if (field[i][j] == NULL && rand() % 3 == 0) {
				field[i][j] = new Food(i, j);
				food_count++;
			}
		}
	}

};

void Scene::check_food() {
	food_count = 0;
	for (int i = 0; i < max_x; ++i) {
		for (int j = 0; j < max_y; ++j) {
			if (field[i][j] != NULL) {
				if (field[i][j]->get_name() == "Food") ++food_count;
			}
		}
	}
	if (food_count < all_food)
	{
		for (int i = 0; i < max_x; ++i) {
			for (int j = 0; j < max_y; ++j) {
				if (rand() % sheep_count == 1 && field[i][j] == NULL) {
					field[i][j] = new Food(i, j);
					++food_count;
				}
				if (food_count == all_food) break;
			}
		}
	}

}

void Scene::clear(Object*** arr, int x, int y) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			delete arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
}
