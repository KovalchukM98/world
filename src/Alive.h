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
	}

	void give_turn(){
		turn = true;
	}

protected:
	
};