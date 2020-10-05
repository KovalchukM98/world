#!/bin/bash
rm main.o
g++ -c --std=c++17 main.cpp
g++ main.o --std=c++17 -lsfml-graphics -lsfml-window -lsfml-system
./a.out
