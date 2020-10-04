#include "Scene.h"



Scene::Scene() {
	is_game_over = true;
	window.create(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "My world");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(80);
};

Scene::~Scene() {
	window.close();
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

	float time;
	float delay = 0.5;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		move_objects();

		window.clear();

	    draw();

		window.display();
	}
}


void Scene::move_objects() {
	for (int i = 0; i < WINDOW_SIZE_X / size_x; ++i) {
		for (int j = 0; j < WINDOW_SIZE_Y / size_y; ++j) {
			if (field[i][j] != NULL) {
				field[i][j]->move(WINDOW_SIZE_X / size_x, WINDOW_SIZE_Y / size_y);
			}
		}
	}
}


	void Scene::draw() {
		for (int i = 0; i < WINDOW_SIZE_X / size_x; ++i) {
			for (int j = 0; j < WINDOW_SIZE_Y / size_y; ++j) {
				if (field[i][j] != NULL) {
					field[i][j]->draw(&window, size_x);
				}
			}
		}
	}

	void Scene::draw_field() {
		for (int i = 0; i < WINDOW_SIZE_X / 50; i++) {
			for (int j = 0; j < WINDOW_SIZE_Y / 50; j++) {
				if (field[i][j] != NULL) {
					// sf::RectangleShape rectangle;
					// rectangle.setPosition(i*60+15, j*40+15);
					// rectangle.setSize(sf::Vector2f(30, 10));
					// rectangle.setFillColor(sf::Color(250,0,0));
					// rectangle.setOutlineThickness(15.f);
					// rectangle.setOutlineColor(sf::Color(80,220,50));
					// window.draw(rectangle);
				}
			}
		}
	};

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

			//     case sf::Keyboard::Left:
			//     board->update(0);
			//     break;

			//     case sf::Keyboard::Right:
			//     board->update(1);
			//     break;

			//     default:
			//     break;
		}
	};

	void Scene::generate_field() {

		for (int i = 0; i < WINDOW_SIZE_X / size_x; ++i) {
			for (int j = 0; j < WINDOW_SIZE_Y / size_y; ++j) {
				if (rand() % 10 == 2) {
					field[i][j] = new Dog(i, j);
				}
				else
				if (rand() % 10 == 1) {
					field[i][j] = new Stone(i,j);
				}
				else
				{
					field[i][j] = NULL;
				}
			}
		}
	};



