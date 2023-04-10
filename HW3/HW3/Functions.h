#pragma once
#include <Box2D/Box2D.h>

void display(b2Body* snake);
void handleInput();
float* B2DtoSFML(b2Vec2 b2d);