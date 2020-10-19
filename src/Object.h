#pragma once
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Object {
public:
	int get_range(){
		return range;
	}

	void give_turn(){
		turn = true;
	}
	Object() {
		range = 0;
	};
	~Object() {};
	virtual void draw(sf::RenderWindow* window, int size) = 0;

	virtual std::pair<int,int> move(Object*** map ,int max_x, int max_y) = 0;

	bool is_Alive;

protected:
	bool turn;
	int range;
	int power;
	int x;
	int y;
};