#include "OptionsMenu.h"

#include <iostream>


OptionsMenu::OptionsMenu(const std::string& whatWall,
						 const std::function<void()>& OnSoundButton,
						 const std::function<void()>& OffSoundButton,
						 const std::function<void()>& backButton)
	: IMenu(),
	whatWall(whatWall),
	OnSoundButton(OnSoundButton),
	OffSoundButton(OffSoundButton),
	backButton(backButton)
{
	Init();
}


void OptionsMenu::Init()
{
	this->user = Core::Color::DARK_RED;
	this->application = Core::Color::GREEN;

	wall.SetWall(whatWall);

	Core::BuildButton build;
	size_t y = 15;

	build.CreateButton();
	build.SetX(7).SetY(y);
	build.SetText("Sound ON");
	build.SetCommand(OnSoundButton);

	buttons.push_back(std::move(*build.GetButton().release()));

	build.CreateButton();
	build.SetX(5).SetY(y += 5);
	build.SetText("Sound OFF");
	build.SetCommand(OffSoundButton);

	buttons.push_back(std::move(*build.GetButton().release()));

	build.CreateButton();
	build.SetX(14).SetY(y += 5);
	build.SetText("Back");
	build.SetCommand(backButton);

	buttons.push_back(std::move(*build.GetButton().release()));
}


bool OptionsMenu::MainLoop()
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
			if (select == buttons.size() - 1)
			{
				return false;
			}
		}
	} while (key == nullptr || (key->GetKey() != Core::KeyBoard::Key::UP) &&
		                       (key->GetKey() != Core::KeyBoard::Key::DOWN));

	Core::Console::SetCursorPosition(0, 0);
	return true;
}