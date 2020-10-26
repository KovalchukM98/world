#include "Sheep.h"
#include <utility>

Sheep::Sheep(int my_x, int my_y) : Alive() {
	x = my_x;
	y = my_y;
	range = 1;
	max_hunger = 20;
	name = "Sheep";
	if (rand() % 2 == 0) {
		direction.first = 1;
		horizontal = true;
	}
	else {
		direction.first = -1;
		horizontal = false;
	}
	if (rand() % 2 == 0) {
		direction.second = 1;
	}
	else {
		direction.second = -1;
	}
	turn = true;
}

std::pair<int, int> Sheep::food_search(Object*** vision, int max_x, int max_y) {
	std::pair<int, int> coords;
	coords.first = x;
	coords.second = y;
	hungry = false;

	int vis_size = range * 2 + 1;
	int center = range;

	for (int i = -1; i < 2; ++i) {
		if (x + i < 0 || x + i >= max_x || x + i == x) {
			continue;
		}
		if (vision[center + i][center] != NULL) {
			if (vision[center + i][center]->get_name() == "Food") {
				hungry = true;
				coords.first = x + i;
				coords.second = y;
				return coords;
			}
		}
	}

	for (int j = -1; j < 2; ++j) {
		if (y + j < 0 || y + j >= max_y || y + j == y) {
			continue;
		}
		if (vision[center][center + j] != NULL) {
			if (vision[center][center + j]->get_name() == "Food") {
				hungry = true;
				coords.first = x;
				coords.second = y + j;
				return coords;
			}
		}
	}
	return coords;
}

std::pair<int, int> Sheep::wolf_search(Object*** vision, int max_x, int max_y) {
	std::pair<int, int> coords;
	coords.first = x;
	coords.second = y;
	danger = false;

	int vis_size = range * 2 + 1;
	int center = range;

	for (int i = -1; i < 2; ++i) {
		if (x + i < 0 || x + i >= max_x || x + i == x || y + i < 0 || y + i >= max_y) {
			continue;
		}
		if (vision[center + i][center] != NULL) {
			if (vision[center + i][center]->get_name() == "Wolf" && vision[center + i][center]->is_dead() == false) {
				danger = true;
				if (vision[center][center + i] == NULL) {
					coords.first = x;
					coords.second = y + i;
					return coords;
				}
			}
		}
	}

	for (int j = -1; j < 2; ++j) {
		if (y + j < 0 || y + j >= max_y || y + j == y || x + j < 0 || x + j >= max_x) {
			continue;
		}
		if (vision[center][center + j] != NULL) {
			if (vision[center][center + j]->get_name() == "Wolf" && vision[center][center + j]->is_dead() == false) {
				danger = true;
				if (vision[center + j][center] == NULL) {
					coords.first = x + j;
					coords.second = y;
					return coords;
				}
			}
		}
	}
	return coords;
}

std::pair<int, int> Sheep::default_move(Object*** vision, int max_x, int max_y) {
	std::pair<int, int> coords;
	coords.first = x;
	coords.second = y;

	int vis_size = range * 2 + 1;
	int center = range;
	int new_x;
	int new_y;
	int repeat = 0;

	while (repeat < 2) {
		new_x = x + direction.first;
		new_y = y + direction.second;
		if (new_x >= 0 && new_x < max_x) {
			if (vision[center + direction.first][center] == NULL && horizontal == true) {
				coords.first = new_x;
				x = new_x;
				turn = false;
				return coords;
			}
			else {
				if (horizontal == true) {
					direction.first *= -1;
					horizontal = false;
				}
			}
		}
		else {
			direction.first *= -1;
			horizontal = false;
		}
		if (new_y >= 0 && new_y < max_y) {
			if (vision[center][center + direction.second] == NULL && horizontal == false) {
				coords.second = new_y;
				y = new_y;
				turn = false;
				return coords;
			}
			else {
				if (horizontal == false) {
					direction.second *= -1;
					horizontal = true;
				}
			}
		}
		else {
			direction.second *= -1;
			horizontal = true;
		}
		repeat++;
	}
	return coords;
}

std::pair<int, int> Sheep::move(Object*** vision, int max_x, int max_y) {
	std::pair<int, int> coords;
	coords.first = x;
	coords.second = y;

	if (turn == false) {
		return coords;
	}

	if (hunger == max_hunger) {
		dead = true;
		return coords;
	}

	coords = wolf_search(vision, max_x, max_y);
	if (danger) {
		turn = false;
		danger = false;
		x = coords.first;
		y = coords.second;
		++hunger;
		return coords;
	}

	coords = food_search(vision, max_x, max_y);
	if (hungry) {
		turn = false;
		hungry = false;
		x = coords.first;
		y = coords.second;
		return coords;
	}

	coords = default_move(vision, max_x, max_y);
	++hunger;

	return coords;
}

void Sheep::draw(sf::RenderWindow* window, int size) {
	int start_x = size * x;
	int start_y = size * y;
	sf::Texture Sheep;
	Sheep.loadFromFile("wolf_v2.png");
	sf::Sprite Sheepsp;
	Sheepsp.setTexture(Sheep);
	Sheepsp.setPosition(start_x + size / 4, start_y + size / 4);
	window->draw(Sheepsp);
}