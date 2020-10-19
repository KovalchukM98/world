#pragma once
#include "Alive.h"

class Sheep : public Alive{
public:
	Sheep(int my_x, int my_y);

	//int get_range();

	void draw(sf::RenderWindow* window, int size) override;
	
	std::pair<int,int> move(Object*** map ,int max_x, int max_y) override;
private:
	std::pair<int,int> direction;
	bool horizontal;
};