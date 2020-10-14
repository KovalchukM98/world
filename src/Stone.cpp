#include "Stone.h"

Stone::Stone(int my_x, int my_y) : Entity() {
	x = my_x;
	y = my_y;
}

std::pair<int, int> Stone::move(Object*** map,int max_x, int max_y){

};

void Stone::draw(sf::RenderWindow* window, int size) {
	int start_x = size * x;
	int start_y = size * y;
	sf::CircleShape shape;
	shape.setFillColor(sf::Color(180,180,180));
	shape.setRadius(size/2);
	shape.setPosition(start_x, start_y);
	window->draw(shape);
	
};