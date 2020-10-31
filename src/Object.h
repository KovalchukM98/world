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
	Object() : range(0), name("Object") {}

	~Object() {}

	int get_range() {
		return range;
	}

	std::string get_name() {
		return name;
	}

	void give_turn() {
		turn = true;
	}

	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}

	virtual bool feed(){
		return true;
	};

	virtual void draw(sf::RenderWindow* window, int size) = 0;

	virtual std::pair<int, int> move(Object*** map, int max_x, int max_y) = 0;

	virtual bool is_dead() {
		return false;
	}

	bool is_Alive;

protected:
	bool turn;
	int range;
	int power;
	int x;
	int y;
	std::string name;
};