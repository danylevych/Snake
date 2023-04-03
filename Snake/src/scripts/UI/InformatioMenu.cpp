#include "InformatioMenu.h"

#include <iostream>


InformatioMenu::InformatioMenu(const std::string& whatWall, const std::function<void()>& backButton)
	: IMenu(),
	whatWall(whatWall),
	backButton(backButton)
{
	Init();
}


void InformatioMenu::Init()
{
	this->user = Core::Color::DARK_RED;
	this->application = Core::Color::GREEN;

	wall.SetWall(whatWall);

	Core::BuildButton build;

	build.CreateButton();
	build.SetX(14).SetY(25);
	build.SetText("Back");
	build.SetCommand(backButton);

	buttons.push_back(std::move(*build.GetButton().release()));
}

bool InformatioMenu::MainLoop()
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