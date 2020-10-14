#include "Wolf.h"
#include <utility>

Wolf::Wolf(int my_x, int my_y) : Alive() {
	x = my_x;
	y = my_y;
	range = 1;
	if(rand()%2 == 0){
		direction.first = 1;
		horizontal = true;
	} else{
		direction.first = -1;
		horizontal = false;
	}
	if(rand()%2 == 0){
		direction.second = 1;
	} else{
		direction.second = -1;
	}
	turn = true;
}

int Wolf::get_range(){
	return range;
}

std::pair<int,int> Wolf::try_to_hunt(Object*** map , int max_x, int max_y){
	std::pair<int,int> coords;
	coords.first = x;
	coords.second = y;
	hunt = false;

	for(int i = -1; i < 2; ++i){
		if( x+i < 0 || x+i >= max_x || x+i == x){
			continue;
		}
		if(map[x+i][y] != NULL){
			if(map[x+i][y]->is_Alive){
				hunt = true;
				coords.first = x+i;
				coords.second = y;
			}
		}
	}

	for(int i = -1; i < 2; ++i){
		if( y+i < 0 || y+i >= max_y || y+i == y){
			continue;
		}
		if(map[x][y+i] != NULL){
			if(map[x][y+i]->is_Alive){	
				hunt = true;
				coords.first = x;
				coords.second = y+i;
			}
		}
	}
	// if(hunt){
		// std::cout << "gonna kill " << coords.first << " " << coords.second << std::endl;
	// }
	return coords;
}

std::pair<int,int> Wolf::move(Object*** map , int max_x, int max_y){
	std::pair<int,int> coords;
	coords.first = x;
	coords.second = y;
	if(turn == false){
		return coords;
	}

	// std::cout << "try_to_hunt " << std::endl;
	coords = try_to_hunt(map, max_x, max_y);
	if(hunt){
		turn = false;
		hunt = false;
		x = coords.first;
		y = coords.second;
		// std::cout<<"--------------------"<<std::endl;
		return coords;
	}
	// std::cout << "hunt failed " << std::endl;

	int new_x;
	int new_y;
	int repeat = 0;

	while(repeat < 2){
		new_x = x + direction.first*range;
		new_y = y + direction.second*range;
		if(new_x >= 0 && new_x < max_x){
			if(map[new_x][y] == NULL && horizontal == true){
				coords.first = new_x;
				x = new_x;
				turn = false;
				return coords;
			} else{
				if(horizontal == true){
					direction.first *= -1;
					horizontal = false;
				}
			}
		} else{
			direction.first *= -1;
			horizontal = false;
		}
		if(new_y >= 0 && new_y < max_y){
			if(map[x][new_y] == NULL && horizontal == false){
				coords.second = new_y;
				y = new_y;
				turn = false;
				return coords;
			} else{
				if(horizontal == false){
					direction.second *= -1;
					horizontal = true;
				}
			}
		} else{
			direction.second *= -1;
			horizontal = true;
		}
		repeat++;
	}
	return coords;
}

void Wolf::draw(sf::RenderWindow* window, int size){

	int start_x = size * x;
	int start_y = size * y;
	sf::CircleShape shape;
	shape.setFillColor(sf::Color::Black);
	shape.setRadius(size / 3);
	shape.setPosition(start_x+size/4, start_y+size/4);
	window->draw(shape);
}