#pragma once
#include "Entity.h"




class Stone : public Entity {
public:
	Stone(int my_x, int my_y);

	void draw(sf::RenderWindow* window, int size) override;
	void move();
protected:

private:
	sf::RenderWindow* window;
};