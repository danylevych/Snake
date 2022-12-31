#include "Game.h"

#include <iostream>
#include <string>
#include <thread>
#include <conio.h>

#include "../Snake/Tools/SetLogos/Map.h"
#include "../Snake/Objects/Snake.h"
#include "../Snake/Objects/Apple.h"
#include "../Snake/Tools/Console.h"
#include "../Snake/Tools/CodeTime.h"
#include "../Snake/Tools/FileManager/FileManager.h"

#pragma region PRIVATE SECTION

void Game::PrintField()
{
	for (const auto& ele : field)
	{
		std::cout << ele << std::endl;
	}
}

bool Game::SnakeInField(const Point& position)
{
	// Because only if snake have size that = 4, its can touch tail.
	if (snake->Size() >= 4)							
		if (field[position.y][position.x] == 'o')
			return true;

	if (field[position.y][position.x] == '-')
		return true;
	else if (field[position.y][position.x] == '|')
		return true;
	else if (field[position.y][position.x] == '\\')
		return true;
	else if (field[position.y][position.x] == '/')
		return true;

	return false;
}

void Game::Update(const std::string& levelPath)
{
	SetConsoleCursor(0, 0); // Sets cursor on start position.

	field = Map(levelPath).GetMap();

	// Setting snake's head and tail, and apple on their position.
	field[apple.GetApplePos().y][apple.GetApplePos().x] = '@';
	field[snake->head->y][ snake->head->x] = 'O';

	for (size_t i = 1; i < snake->Size(); i++)
	{
		field[(*snake)[i].y][(*snake)[i].x] = 'o';
	}

	PrintField();
	std::cout << "\nSCORE:  " << score << std::endl;
}

void Game::Input()
{
	if (_kbhit())
	{
		char kay = _getch();
		if (kay == static_cast<int>(ENUM::Key::ARROW))
		{
			kay = _getch();

			switch (kay)
			{
			case static_cast<int>(ENUM::Key::UP):
				dir == ENUM::Direction::DOWN ? dir : dir = ENUM::Direction::UP;
				break;

			case static_cast<int>(ENUM::Key::DOWN):
				dir == ENUM::Direction::UP ? dir : dir = ENUM::Direction::DOWN;
				break;

			case static_cast<int>(ENUM::Key::LEFT):
				dir == ENUM::Direction::RIGHT ? dir : dir = ENUM::Direction::LEFT;
				break;

			case static_cast<int>(ENUM::Key::RIGHT):
				dir == ENUM::Direction::LEFT ? dir : dir = ENUM::Direction::RIGHT;
				break;
			}
		}
		else if (kay == 'P' || kay == 'p') // Game pause.
		{
			dir = ENUM::Direction::STOP;
		}
	}
}

void Game::Logic(double deltaTime)
{
	// Snake eaten apple.
	if (snake->head->x == apple.GetApplePos().x && snake->head->y == apple.GetApplePos().y)
	{
		// Playing eating sound.
		std::thread th{ FileManager::SoundPlay, LR"(Sound\Eating_fruit.wav)" };

		// Pushing new element on snake's end.
		snake->PushTail((*snake)[snake->Size() - 1]);

		do
		{
			apple.GenerateNewApple(*snake, snake->Size());
		} while (field[apple.GetApplePos().y][apple.GetApplePos().x] == '|' || field[apple.GetApplePos().y][apple.GetApplePos().x] == '-'
			  || field[apple.GetApplePos().y][apple.GetApplePos().x] == '\\' || field[apple.GetApplePos().y][apple.GetApplePos().x] == '/');

		score += 10;
		th.detach();
	}

	snake->Move(dir, deltaTime);

	// If snake touch border fields or its touch its tail.
	if (SnakeInField(*snake->head))
	{
		system("cls");
		field.clear();

		FileManager::SoundPlay(LR"(Sound\Hit.wav)");
		FileManager::ReadLogo(R"(Pictures\Logos\GameOver.txt)", field);

		gameStatus = false;

		PrintField();
		PrintScore(score);

		system("pause");
		return;
	}
}

#pragma endregion PRIVATE SECTION


#pragma region PUBLIC SECTION

Game::Game(Snake* snake)
	: snake(snake), apple(Point{})
{	}

void Game::StartGame(const std::string& levelPath)
{
	apple.GenerateNewApple(*snake, snake->Size());

	CodeTime::Time time;
	while (gameStatus)
	{
		Update(levelPath);
		Input();
		Logic(time.DeltaTime());
	}
}

#pragma endregion PUBLIC SECTION