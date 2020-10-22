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
	}

	void give_turn(){
		turn = true;
		hunger = 0;
	}

	bool is_dead(){
		return dead;
	}

protected:
	bool dead;		// является ли трупом. по этой переменной удаляем голодных или побитых
	int hunger;        //количество тиков без еды
	int max_hunger;    // предел
};