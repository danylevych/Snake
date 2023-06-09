#include "Game.h"

#include <iostream>
#include <string>
#include <thread>

#include "../../../Event/Core.hpp"

#include "Tools/Paths.h"
#include "Objects/Snake.h"
#include "Objects/Apple.h"

#include <codecvt>

#pragma region PRIVATE SECTION

void Game::GenerateApple()
{
	do
	{
		apple.GenerateNewApple(*snake, snake->Size());
	} while (IsColision(apple.GetApplePos()));
}

void Game::PrintField()
{
	std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> codnverter;

	for (const auto& item : field)
	{
		std::cout << codnverter.to_bytes(item) << std::endl;
	}
}

bool Game::IsColision(const Point& position, bool isSnake)
{
	// Checking colision for the snake.
	if (isSnake)
	{
		// Because only if snake have size that = 4, its can touch tail.
		if (snake->Size() >= 4)
		{
			if (field[position.y][position.x] == U'o')
			{
				return true;
			}
		}
	}

	switch (field[position.y][position.x]) 
	{
	case U'═':
	case U'║':
	case U'╔':
	case U'╚':
	case U'╗':
	case U'╝':
	case U'╦':
	case U'╩':
	case U'╣':
	case U'╠':
		return true;
	}

	return false;
}

void Game::Update(const std::string& levelPath)
{
	Core::Console::SetCursorPosition(0, 0); // Sets cursor on start position.
	
	field.clear();
	Core::FileManager::ReadFile(levelPath, field);

	if (!apple)
	{
		GenerateApple();
	}

	// Setting snake's head and tail, and apple on their position.
	field[apple.GetApplePos().y][apple.GetApplePos().x] = U'●';
	field[snake->head->y][ snake->head->x] = U'O';

	for (size_t i = 1; i < snake->Size(); i++)
	{
		field[(*snake)[i].y][(*snake)[i].x] = U'o';
	}

	PrintField();
	std::cout << scoreText;
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
		std::thread { Core::AudioManager::PlayAudio, Paths::eatingSound, false }.detach();

		// Pushing new element on snake's end.
		snake->PushTail((*snake)[snake->Size() - 1]);

		GenerateApple();

		score += 10;
		scoreText.SetText("score: " + std::to_string(score), Core::Fonts::FULL);
	}

	snake->Move(dir, deltaTime);

	// If snake touch border fields or its touch its tail.
	if (IsColision(*snake->head))
	{
		system("cls");
		field.clear();

		std::thread{ Core::AudioManager::PlayAudio, Paths::hitSound, false }.detach();
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
{
	scoreText.SetY(27);
	scoreText.SetText("score: 0", Core::Fonts::FULL);
}

void Game::StartGame(const std::string& levelPath)
{
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