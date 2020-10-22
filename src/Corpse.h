#pragma once
#include "Entity.h"

class Corpse : public Entity {
public:
	Corpse(int my_x, int my_y);

	void draw(sf::RenderWindow* window, int size) override;

	std::pair<int, int> move(Object*** map ,int max_x, int max_y) override;
	
	bool is_rotten(){
		return to_delete;
	}

protected:

private:
	int timer;
	bool to_delete;
	sf::RenderWindow* window;
};