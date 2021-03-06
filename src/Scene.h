#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Object.h"
#include "Entity.h"
#include "Alive.h"
#include "Stone.h"
#include "Sheep.h"
#include "Lake.h"
#include "Wolf.h"
#include "Food.h"
#include "Corpse.h"

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
	bool action(Object** agressor, Object** defender);
	void check_event();
	void check_key(sf::Event event);
	void generate_field();
	Object*** get_vision(int range, int x, int y);
	void check_food();
	void clear(Object*** arr, int x, int y);
	int sheep_count;
	int max_x;
	int max_y;
	int food_count;
	int all_food;
	int step;

	Object*** field;
	std::vector<Corpse> corpses;
	std::vector<Object*> hidden_food;



	bool is_game_over;

	sf::Clock clock;
	float timer;
	sf::RenderWindow window;
};