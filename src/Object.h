#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Object {
public:
	virtual void draw(sf::RenderWindow* window, int size) = 0;
	void move() {};

protected:
	int range;
	int power;
	int x;
	int y;
};