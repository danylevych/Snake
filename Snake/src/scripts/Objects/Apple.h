#pragma once

#include <ctime>
#include "Snake.h"
#include "../Tools/Tools.h"


class Apple
{
private:
	Point apple;

	void GeneratePosition()
	{
		std::srand(static_cast<unsigned>(time(nullptr)));

		apple.x = std::rand() % (WINDOW_WIDTH - 2) + 1;
		apple.y = std::rand() % (WINDOW_HEIGHT - 6) + 1;
	}
	
public:
	Apple(const Point& point)
		: apple(point)
	{	}

	void GenerateNewApple(const Snake& snakePos, size_t size)
	{
		GeneratePosition();

		for (size_t i = 0; i < size; i++)
		{
			if (apple.x == snakePos[i].x && apple.y == snakePos[i].y)
			{
				GeneratePosition();
			}
		}
	}

	Point GetApplePos() const { return apple; }
};