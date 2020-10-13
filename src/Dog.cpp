#include "Dog.h"

Dog::Dog(int my_x, int my_y) : Alive() {
	x = my_x;
	y = my_y;
	range = 1;
	direction.first = 1;
	direction.second = 1;
	turn = true;
	horizontal = true;
}

int Dog::get_range(){
	return range;
}

std::pair<int,int> Dog::move(Object*** map , int max_x, int max_y){
	std::cout << "range = " << range << std::endl;
	std::pair<int,int> coords;
	coords.first = x;
	coords.second = y;
	if(turn == false){
		return coords;
	}

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
				std::cout << "step" << std::endl;
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
				std::cout << "step: " << std::endl;
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
	// for(int i = x-range; i <= x+range; ++i){
	// 	for(int j = y-range; j <= y+range; ++j){
	// 		std::cout << i << " " << j << std::endl;
	// 		if( i >= max_x || i < 0 || j >= max_y || j < 0){
	// 			continue;
	// 		}
	// 		else if( abs(x-i) + abs(y-j) > range){
	// 			continue;
	// 		}
	// 		else if( map[i][j] == NULL ){
	// 			coords.first = i;
	// 			coords.second = j;
	// 			x = i;
	// 			y = j;
	// 			std::cout << "step: " << std::endl;
	// 			return coords;
	// 		}
	// 	}
	// }
	return coords;
}

void Dog::draw(sf::RenderWindow* window, int size){

	int start_x = size * x;
	int start_y = size * y;
	sf::CircleShape shape;
	shape.setFillColor(sf::Color::Red);
	shape.setRadius(size / 4);
	shape.setPosition(start_x, start_y);
	window->draw(shape);
}