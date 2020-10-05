#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Object.h"
#include "Entity.h"
#include "Alive.h"
#include "Stone.cpp"
#include "Dog.cpp"



const int WINDOW_SIZE_X = 1000;
const int WINDOW_SIZE_Y = 1000;
const short size_x = 50;
const short size_y = 50;

class Scene {
public:
	Scene();
	~Scene();
	void start();
private:
	void move_objects();
	void draw();
	// void draw_field();
	void check_event();
	void check_key(sf::Event event);
	void generate_field();
	Object*** get_vision(int range, int x, int y);
	void clear(Object*** arr, int x, int y);

	int max_x;
	int max_y;

	Object*** field;
	bool is_game_over;
	sf::Clock clock;
	float timer;
	sf::RenderWindow window;
};