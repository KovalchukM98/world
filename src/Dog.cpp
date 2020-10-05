#include "Dog.h"

Dog::Dog(int my_x, int my_y) : Alive() {
	x = my_x;
	y = my_y;
	range = 1;
}

int Dog::get_range(){
	return range;
}

std::pair<int,int>Dog::move(int max_x, int max_y){
	
}
void Dog::draw(sf::RenderWindow* window, int size){

	int start_x = size * x;
	int start_y = size * y;
	sf::CircleShape shape;
	shape.setFillColor(sf::Color::Red);
	shape.setRadius(size / 4);
	shape.setPosition(start_x, start_y);
	window->draw(shape);
}