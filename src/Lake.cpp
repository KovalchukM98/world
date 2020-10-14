#include "Lake.h"

Lake::Lake(int my_x, int my_y) : Entity() {
	x = my_x;
	y = my_y;
}

std::pair<int, int> Lake::move(Object*** map,int max_x, int max_y){};

void Lake::draw(sf::RenderWindow* window, int size) {
	int start_x = size * x;
	int start_y = size * y;
	sf::RectangleShape shape;
    shape.setPosition(start_x+2, start_y+2);
    shape.setSize(sf::Vector2f(size-5, size-5));
	shape.setFillColor(sf::Color(0,0,180));
	window->draw(shape);
	
};