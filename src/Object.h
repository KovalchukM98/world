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
	int get_range() {
		return range;
	}

	std::string get_name() {
		return name;
	}

	void give_turn() {
		turn = true;
	}

	Object() : range(0), name("Object") {}

	~Object() {}
	virtual void draw(sf::RenderWindow* window, int size) = 0;

	virtual std::pair<int, int> move(Object*** map, int max_x, int max_y) = 0;

	bool is_Alive;

	virtual bool is_dead() {
		return false;
	}

protected:
	bool turn;
	int range;
	int power;
	int x;
	int y;
	std::string name;
};