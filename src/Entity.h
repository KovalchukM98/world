#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Object.h"

class Entity : public Object {
public:

	Entity(){
		range = 0;
		is_Alive = false;
	}

	// std::pair<int, int> move(int max_x, int max_y) override;

protected:

};