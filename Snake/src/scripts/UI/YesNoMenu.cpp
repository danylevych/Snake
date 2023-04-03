#include "YesNoMenu.h"

#include <iostream>
#include "../Tools/Paths.h"

YesNoMenu::YesNoMenu(const std::function<void()>& yesButton, const std::function<void()>& noButton)
	: IMenu(),
	noButton(noButton),
	yesButton(yesButton)
{
	Init();
}


void YesNoMenu::Init()
{
	this->user = Core::Color::DARK_RED;
	this->application = Core::Color::GREEN;

	wall.SetWall(Paths::yesOrNoMenu);

	Core::BuildButton build;

	build.CreateButton();
	build.SetX(4).SetY(23);
	build.SetText("Yes");
	build.SetCommand(yesButton);

	buttons.push_back(std::move(*build.GetButton().release()));

	build.CreateButton();
	build.SetX(30).SetY(23);
	build.SetText("No");
	build.SetCommand(noButton);

	buttons.push_back(std::move(*build.GetButton().release()));
}

bool YesNoMenu::MainLoop()
{
	Core::Event event;
	Core::KeyEvent* key = nullptr;

	std::cout << *this;

	do
	{
		Core::EventManager::PollKeyEvent(event);
		key = Core::EventManager::ParseKeyEvent(event);

		if (key != nullptr &&
			((key->GetKey() == Core::KeyBoard::Key::LEFT) ||
			 (key->GetKey() == Core::KeyBoard::Key::RIGHT)))
		{
			IMenu::CheckUserInput(event);
		}
		else if (key != nullptr && key->GetKey() == Core::KeyBoard::Key::ENTER)
		{
			buttons[select].SetIsPressed(true);
			return false;
		}


	} while (key == nullptr || (key->GetKey() != Core::KeyBoard::Key::LEFT) &&
							   (key->GetKey() != Core::KeyBoard::Key::RIGHT));

	Core::Console::SetCursorPosition(0, 0);

	return true;
}