#pragma once
#include "Entity.h"


class Food : public Entity {
public:
	Food(int my_x, int my_y);

	void draw(sf::RenderWindow* window, int size) override;

	std::pair<int, int> move(Object*** map, int max_x, int max_y) override;

protected:

private:
	sf::RenderWindow* window;
};