#pragma once
#include "Alive.h"

class Wolf : public Alive{
public:
	Wolf(int my_x, int my_y);

	~Wolf(){};

	//int get_range();

	void draw(sf::RenderWindow* window, int size) override;

	std::pair<int,int> try_to_hunt(Object*** map ,int max_x, int max_y);

	std::pair<int,int> default_move(Object*** vision , int max_x, int max_y);
	
	std::pair<int,int> move(Object*** map ,int max_x, int max_y) override;
private:
	std::pair<int,int> direction;
	bool horizontal;
	bool hunt;
};