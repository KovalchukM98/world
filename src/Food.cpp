#include "Food.h"

Food::Food(int my_x, int my_y) : Entity() {
	x = my_x;
	y = my_y;
}

std::pair<int, int> Food::move(Object*** map, int max_x, int max_y) {
	int a = 0, b = 0;
	return std::pair<int, int>(a, b);
};

void Food::draw(sf::RenderWindow* window, int size) {
	int start_x = size * x;
	int start_y = size * y;
	sf::Texture food;
	food.loadFromFile("food.png");
	sf::Sprite foodsp;
	foodsp.setTexture(food);
	foodsp.setPosition(start_x, start_y);
	window->draw(foodsp);

};