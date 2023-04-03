#include "Game.h"

#include <iostream>
#include <string>
#include <thread>

#include "../../../Event/Core.hpp"

#include "Tools/Paths.h"
#include "Objects/Snake.h"
#include "Objects/Apple.h"


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
	Core::Console::SetCursorPosition(0, 0); // Sets cursor on start position.

	field.clear();
	Core::FileManager::ReadFile(levelPath, field);

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
	Core::Event event;
	if (Core::EventManager::PollKeyEvent(event))
	{
		auto key = Core::EventManager::ParseKeyEvent(event);
		if (key)
		{
			switch (key->GetKey())
			{
			case Core::KeyBoard::Key::UP:
				dir == ENUM::Direction::DOWN ? dir : dir = ENUM::Direction::UP;
				break;

			case Core::KeyBoard::Key::DOWN:
				dir == ENUM::Direction::UP ? dir : dir = ENUM::Direction::DOWN;
				break;

			case Core::KeyBoard::Key::LEFT:
				dir == ENUM::Direction::RIGHT ? dir : dir = ENUM::Direction::LEFT;
				break;

			case Core::KeyBoard::Key::RIGHT:
				dir == ENUM::Direction::LEFT ? dir : dir = ENUM::Direction::RIGHT;
				break;

			case Core::KeyBoard::Key::ESC:
				dir = ENUM::Direction::STOP;
				break;
			}
		}
	}
}

void Game::Logic(double deltaTime)
{
	// Snake eaten apple.
	if (snake->head->x == apple.GetApplePos().x && snake->head->y == apple.GetApplePos().y)
	{
		// Playing eating sound.
		std::thread th{ Core::AudioManager::PlayAudio, Paths::eatingSound, false };

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

		Core::AudioManager::PlayAudio(Paths::hitSound);
		Core::FileManager::ReadFile(Paths::gameOverMenu, field);

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

	Core::Clock time;
	while (gameStatus)
	{
		Core::Time delta = time.DeltaTime();
		Update(levelPath);
		Input();
		Logic(delta.AsSeconds());
	}
}

#pragma endregion PUBLIC SECTION