#include "Snake.h"

Snake::Snake(int x, int y)
	: snake{ Point{x, y} }
{
	head = &snake[0];
}

void Snake::Move(const ENUM::Direction& dir, float deltaTime)
{
	if (dir == ENUM::Direction::STOP || !DoNeedToMove(deltaTime))
	{
		return;
	}

	// Pull the tail to the head.
	for (size_t i = snake.size() - 1; i >= 1; i--)
	{
		snake[i] = snake[i - 1];
	}

	switch (dir)
	{
	case ENUM::Direction::UP:
		head->y--;
		break;
	case ENUM::Direction::DOWN:
		head->y++;
		break;
	case ENUM::Direction::RIGHT:
		head->x++;
		break;
	case ENUM::Direction::LEFT:
		head->x--;
		break;
	case ENUM::Direction::STOP:
		break;
	}
}

void Snake::PushTail(const Point& point)
{
	snake.push_back( Point{ point } );
	head = &snake[0];
}

bool Snake::DoNeedToMove(double deltaTime)
{
	passedDistance += speed * deltaTime;

	if (passedDistance >= cellsToPass)
	{
		cellsToPass++;
		return true;
	}

	return false;
}