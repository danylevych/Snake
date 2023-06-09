#pragma once

#include <string>
#include <vector>

#include "Objects/Snake.h"
#include "Objects/Apple.h"

#include "../../../Event/src/Tools/Console Elements/Label.h"

class Game
{
private:
	Snake* snake;
	Apple apple;

	std::vector<std::u16string> field; // Game field.

	Core::Label scoreText;
	uint32_t score = 0;

	bool gameStatus = true;
	ENUM::Direction dir = ENUM::Direction::STOP;

public:
	Game(Snake* snake);
	void StartGame(const std::string& levelPath);

private:
	void PrintField();
	void GenerateApple();
	bool IsColision(const Point& position, bool isSnake = true); // Checks if Snake doesn't touch fields border or itself.

	void Update(const std::string& levelPath);
	void Input();
	void Logic(double deltaTime);
};