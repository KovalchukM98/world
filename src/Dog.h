#pragma once
#include "Alive.h"

class Dog : public Alive{
public:
	Dog(int my_x, int my_y);

	int get_range();

	void draw(sf::RenderWindow* window, int size) override;
	
	std::pair<int,int> move(int max_x, int max_y) override;
};