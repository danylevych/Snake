#pragma once

#include <vector>
#include "../Tools/Tools.h"

class Snake
{
private:
	std::vector<Point> snake;

	double passedDistance = 0;
	int cellsToPass = 1;
	int speed = 8; // Cell per second.

	bool DoNeedToMove(double deltaTime);

public:
	Point* head;

	Point& operator[](int index)
	{
		return snake[index];
	}
	const Point& operator[](int index) const
	{
		return snake[index];
	}

	Snake(int x, int y);
	size_t Size() const { return snake.size(); }
	void Move(const ENUM::Direction& dir, float deltaTime);
	void PushTail(const Point& point);
};