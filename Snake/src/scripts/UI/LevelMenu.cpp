#include "LevelMenu.h"

#include <iostream>


LevelMenu::LevelMenu(const std::string& whatWall,
					 const std::function<void()>& simpleButton,
					 const std::function<void()>& middleButton,
					 const std::function<void()>& hardButton,
					 const std::function<void()>& backButton)
	: IMenu(),
	whatWall(whatWall),
	simpleButton(simpleButton),
	middleButton(middleButton),
	hardButton(hardButton),
	backButton(backButton)
{
	Init();
}


void LevelMenu::Init()
{
	this->user = Core::Color::DARK_RED;
	this->application = Core::Color::GREEN;

	wall.SetWall(whatWall);

	Core::BuildButton build;
	size_t y = 14;

	build.CreateButton();
	build.SetX(9).SetY(y);
	build.SetText("Simple");
	build.SetCommand(simpleButton);

	buttons.push_back(std::move(*build.GetButton().release()));

	build.CreateButton();
	build.SetX(9).SetY(y += 4);
	build.SetText("Middle");
	build.SetCommand(middleButton);

	buttons.push_back(std::move(*build.GetButton().release()));

	build.CreateButton();
	build.SetX(13).SetY(y += 4);
	build.SetText("Hard");
	build.SetCommand(hardButton);

	buttons.push_back(std::move(*build.GetButton().release()));

	build.CreateButton();
	build.SetX(13).SetY(y += 4);
	build.SetText("Back");
	build.SetCommand(backButton);

	buttons.push_back(std::move(*build.GetButton().release()));
}

bool LevelMenu::MainLoop()
{
	Core::Event event;
	Core::KeyEvent* key = nullptr;

	std::cout << *this;

	do
	{
		Core::EventManager::PollKeyEvent(event);
		key = Core::EventManager::ParseKeyEvent(event);

		if (key != nullptr &&
			((key->GetKey() == Core::KeyBoard::Key::UP) ||
			 (key->GetKey() == Core::KeyBoard::Key::DOWN)))
		{
			IMenu::CheckUserInput(event);
		}
		else if (key != nullptr && key->GetKey() == Core::KeyBoard::Key::ENTER)
		{
			buttons[select].SetIsPressed(true);
			return false;
		}
	} while (key == nullptr || (key->GetKey() != Core::KeyBoard::Key::UP) &&
							   (key->GetKey() != Core::KeyBoard::Key::DOWN));
	
	Core::Console::SetCursorPosition(0, 0);

	return true;
}