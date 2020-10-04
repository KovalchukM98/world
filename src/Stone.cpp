#include "Stone.h"

Stone::Stone(int my_x, int my_y) {
	x = my_x;
	y = my_y;
}

 Stone::move() {};

void Stone::draw(sf::RenderWindow* window, int size) {

	int start_x = size * x;
	int start_y = size * y;
	sf::CircleShape shape;
	shape.setFillColor(sf::Color::White);
	shape.setRadius(size/2);
	shape.setPosition(start_x, start_y);
	window->draw(shape);
	
};