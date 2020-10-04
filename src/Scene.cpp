#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

int WINDOW_SIZE_X = 1000;
int WINDOW_SIZE_Y = 1000;

class Scene{
public:
	Scene(){
        is_game_over = true;
        window.create(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "My world");
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(80);
    };

	~Scene(){
        window.close();
    };
    //test//
	void start(){
        is_game_over = false;
        generate_field();

        // sf::SoundBuffer buffer;
        // sf::Sound music;
        // if (!music.openFromFile("training.wav")){
        //     return;
        // }
        // music.play();
        
        float time;
        float delay = 0.5;
		while (!is_game_over)
    	{
            check_event();
            time = clock.getElapsedTime().asSeconds();
            timer += time;
            if(timer >= delay){
                //....
            }
            //.....
    	}

        
	};

private:

    void draw(){}

    void draw_field(){
        for(int i = 0 ; i < WINDOW_SIZE_X/50 ; i++){
            for(int j = 0 ; j < WINDOW_SIZE_Y/50 ; j++){
                if(field[i][j] == true){
                    // sf::RectangleShape rectangle;
                    // rectangle.setPosition(i*60+15, j*40+15);
                    // rectangle.setSize(sf::Vector2f(30, 10));
                    // rectangle.setFillColor(sf::Color(250,0,0));
                    // rectangle.setOutlineThickness(15.f);
                    // rectangle.setOutlineColor(sf::Color(80,220,50));
                    // window.draw(rectangle);
                }
            }
        }
    }

    void check_event(){
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type){
                case sf::Event::Closed:
                is_game_over = true;
                break;

                case sf::Event::KeyPressed:
                check_key(event);
                break;
            }
        }
    }

    void check_key(sf::Event event){
        switch(event.key.code){
            case sf::Keyboard::Escape:
            window.close();
            is_game_over = true;
            break;

            case sf::Keyboard::Left:
            board->update(0);
            break;

            case sf::Keyboard::Right:
            board->update(1);
            break;

            default:
            break;
        }
    }

    void generate_field(){
        // bricks_num = 0;
        // for(int i = 0 ; i < 600/60 ; i++){
        //     for(int j = 0 ; j < 600/40 ; j++)
        //         if(rand() % 2 == 1){
        //             bricks_num++;
        //             field[i][j] = true;
        //         }
        //         else
        //             field[i][j] = false;
        // }
    }

	sf::RenderWindow window;

    bool field[WINDOW_SIZE_X/50]WINDOW_SIZE_Y/50];
    bool is_game_over;
    sf::Clock clock;
    float timer;
};
