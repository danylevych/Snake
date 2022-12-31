#pragma once

#include <string>
#include <vector>

#include "../Snake/Objects/Snake.h"
#include "../Snake/Objects/Apple.h"


class Game
{
private:
	Snake* snake;
	Apple apple;

	std::vector<std::string> field; // Game field.
	uint32_t score = 0;

	bool gameStatus = true;
	ENUM::Direction dir = ENUM::Direction::STOP;

	void PrintField();
	bool SnakeInField(const Point& position); // Checks if Snake doesn't touch fields border or itself.

	void Update(const std::string& levelPath);
	void Input();
	void Logic(double deltaTime);

public:
	Game(Snake* snake);
	void StartGame(const std::string& levelPath);
};