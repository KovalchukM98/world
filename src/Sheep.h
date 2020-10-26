#pragma once
#include "Alive.h"

class Sheep : public Alive{
public:
	Sheep(int my_x, int my_y);

	//int get_range();

	void draw(sf::RenderWindow* window, int size) override;
	
	std::pair<int,int> move(Object*** map ,int max_x, int max_y) override;

	std::pair<int, int> default_move(Object*** vision, int max_x, int max_y);

	std::pair<int, int> food_search(Object*** map, int max_x, int max_y);

	std::pair<int, int> wolf_search(Object*** vision, int max_x, int max_y);
private:
	std::pair<int,int> direction;
	bool horizontal;
	bool hungry;
	bool danger;
};