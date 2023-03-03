#pragma once
#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

using namespace std;

void applyForces(b2Body* snake);
void display(b2Body* snake, b2Vec2* target, int score);
void intro();
void moveTarget(b2Vec2* target);
