#include "Lake.h"

Lake::Lake(int my_x, int my_y) : Entity() {
	x = my_x;
	y = my_y;
}

std::pair<int, int> Lake::move(Object*** map,int max_x, int max_y){
	int a = 0, b = 0;
	return std::pair<int, int>(a, b);
};

void Lake::draw(sf::RenderWindow* window, int size) {
	int start_x = size * x;
	int start_y = size * y;

	sf::Texture lake;
	lake.loadFromFile("lake.png");
	sf::Sprite lakesp;
	lakesp.setTexture(lake);
	lakesp.setPosition(start_x + 2, start_y + 2);
	window->draw(lakesp);
};