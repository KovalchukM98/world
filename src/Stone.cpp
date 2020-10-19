#include "Stone.h"

Stone::Stone(int my_x, int my_y) : Entity() {
	x = my_x;
	y = my_y;
}

std::pair<int, int> Stone::move(Object*** map,int max_x, int max_y){
	int a = 0, b = 0;
	return std::pair<int, int>(a,b);
};

void Stone::draw(sf::RenderWindow* window, int size) {
	int start_x = size * x;
	int start_y = size * y;
	sf::Texture stone;
	stone.loadFromFile("stone_v1.png");
	sf::Sprite stonesp;
	stonesp.setTexture(stone);
	stonesp.setPosition(start_x, start_y);
	window->draw(stonesp);
	
};