#include "Corpse.h"

Corpse::Corpse(int my_x, int my_y) : Entity() {
	x = my_x;
	y = my_y;
	name = "Corpse";
	timer = 5;
	to_delete = false;
}

std::pair<int, int> Corpse::move(Object*** map,int max_x, int max_y){
	int a = 0, b = 0;
	return std::pair<int, int>(a,b);
};

void Corpse::draw(sf::RenderWindow* window, int size) {
	int start_x = size * x;
	int start_y = size * y;
	sf::Texture stone;

	sf::RectangleShape rectangle;
    rectangle.setPosition(start_x + (size/4), start_y + (size/2));
    rectangle.setSize(sf::Vector2f(size/2, size/2));
    rectangle.setFillColor(sf::Color(200,200,200));
    window->draw(rectangle);
	sf::CircleShape circle;
	circle.setRadius(size/4);
	circle.setPosition(start_x+(size/4), start_y + size/4);
	circle.setFillColor(sf::Color(200,200,200));
	window->draw(circle);

	sf::Font font;
	sf::Text text;
	text.setString("Rip");
	text.setCharacterSize(5);
	text.setColor(sf::Color::Black);
	text.setPosition(start_x + (size/4) + 2, start_y + (size/2));
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
	window->draw(text);

	timer--;
	if(timer == 0){
		to_delete = true;
	}
};