#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Object.h"
class Alive : public Object {
public:
	~Alive() {};
	Alive(){
		is_Alive = true;
		dead = false;
		hunger = 0;
		max_hunger = 10;
	}

	void give_turn(){
		turn = true;
	}

	bool is_dead(){
		return dead;
	}

	bool feed(){
		hunger = 0;
		return true;
	}

protected:
	bool dead;		// является ли трупом. по этой переменной удаляем голодных или побитых
	int hunger;        //количество тиков без еды
	int max_hunger;    // предел
};