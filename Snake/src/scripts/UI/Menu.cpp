#include "Menu.h"


#include <codecvt>
#include <iostream>

#include "YesNoMenu.h"
#include "LevelMenu.h"
#include "OptionsMenu.h"
#include "InformatioMenu.h"

#include "../Game.h"
#include "../Objects/Snake.h"
#include "../Tools/Paths.h"


MainMenu::MainMenu()
	: IMenu(),
	level(Paths::simpleLevel),
	songPath(Paths::backgroundSound),
	isSong(true)
{
	Loading();
	Core::Console::Clear();
	Init();
}

MainMenu::MainMenu(const std::string& level, bool isSong)
	: IMenu(),
	level(level),
	songPath(Paths::backgroundSound),
	isSong(isSong)
{
	Loading();
	Core::Console::Clear();
	Init();
}


void MainMenu::Init()
{
	this->user = Core::Color::DARK_RED;
	this->application = Core::Color::GREEN;

	if (isSong)
	{
		Core::AudioManager::OpenAudio(songPath);
		Core::AudioManager::PlayAudio(songPath, true);
	}

	std::function<void()> backButton{ []() { Core::Console::Clear(); } };

	wall.SetWall(Paths::mainMenu);
	

	Core::BuildButton build;
	size_t y = 9;

	build.CreateButton();
	build.SetX(12).SetY(y);
	build.SetText("Start");
	build.SetCommand(
		[=]()
		{
			Core::Console::Clear();
			YesNoMenu userChose
			{
				[=]()
				{
					Core::Console::Clear();

					Snake snake{ WINDOW_WIDTH / 2 + 1, WINDOW_HEIGHT / 2 };
					Game game{ &snake };
					game.StartGame(level);

					Core::Console::Clear();
				},
				backButton
			};
		
			while (userChose.MainLoop());
			Core::Console::Clear();
		});

	buttons.push_back(std::move(*build.GetButton().release()));

	build.CreateButton();
	build.SetX(10).SetY(y += 4);
	build.SetText("Levels");
	build.SetCommand(
		[backButton = backButton, &level = (this->level)]()
		{
			LevelMenu levelMenu
			{
				Paths::levelsMenu,
				[&]() {	level = Paths::simpleLevel;	},
				[&]() { level = Paths::middleLevel; },
				[&]() { level = Paths::hardLevel; },
				backButton
			};

			while (levelMenu.MainLoop());
			Core::Console::Clear();
		});

	buttons.push_back(std::move(*build.GetButton().release()));


	build.CreateButton();
	build.SetX(8).SetY(y += 4);
	build.SetText("Options");
	build.SetCommand(
		[&songPath = this->songPath, &isSong = this->isSong, backButton = backButton]()
		{
			OptionsMenu optionMenu
			{
				Paths::optionMenu,
				[&]()
				{
					if (!isSong)
					{
						Core::AudioManager::OpenAudio(songPath);
						Core::AudioManager::PlayAudio(songPath, true);
						isSong = true;
					}
				},
				[&]()
				{
					if (isSong)
					{
						Core::AudioManager::CloseAudio(songPath);
						isSong = false;
					}
				},
				backButton
			};
			
			while (optionMenu.MainLoop());
			Core::Console::Clear();
		});

	buttons.push_back(std::move(*build.GetButton().release()));


	build.CreateButton();
	build.SetX(14).SetY(y += 4);
	build.SetText("Info");
	build.SetCommand(
		[backButton = backButton]()
		{
			InformatioMenu infoMenu
			{
				Paths::infoMenu,
				backButton
			};
		
			while (infoMenu.MainLoop());
		});

	buttons.push_back(std::move(*build.GetButton().release()));


	build.CreateButton();
	build.SetX(14).SetY(y += 4);
	build.SetText("Exit");
	build.SetCommand(
		[&, backButton = backButton]()
		{
			YesNoMenu userChose
			{
				[&]()
				{
					Core::FileManager::WriteFile(Paths::startInfo, std::vector<std::string>{ level.data(), std::to_string(isSong)});
					Core::Console::Clear();
					std::exit(0);
				},
				backButton
			};
			while (userChose.MainLoop());
		});

	buttons.push_back(std::move(*build.GetButton().release()));
}

void MainMenu::Loading()
{
	auto wallpaper = Core::Wallpaper(Paths::loadingMenu).GetWallpaper();

	Core::AudioManager::OpenAudio(Paths::loadingSound);
	Core::AudioManager::PlayAudio(Paths::loadingSound);

	Sleep(20);

	Core::Console::SetTextColor(Core::Color::GREEN);
	std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> convert;

	for (auto elem = wallpaper.cbegin(), end = wallpaper.cend(); elem != end; ++elem)
	{
		if (elem == end - 1)  // The last item in wallpaper.
		{
			std::cout << convert.to_bytes(*elem);
		}
		else 
		{
			std::cout << convert.to_bytes(*elem) << std::endl;
		}
		Sleep(60);
	}
	Sleep(60);

	Core::AudioManager::CloseAudio(Paths::loadingSound);
	Core::Console::Clear();
}

bool MainMenu::MainLoop()
{
	Core::Console::SetCursorPosition(0, 0);

	Core::Event event;
	Core::KeyEvent* key = nullptr;
	
	std::cout << *this;

	do
	{
		Core::EventManager::PollKeyEvent(event);
		IMenu::CheckUserInput(event);
		key = Core::EventManager::ParseKeyEvent(event);

		if (key)
		{
			Core::Console::SetCursorPosition(0, 0);
			std::cout << *this;
		}
	} while (key == nullptr || (key->GetKey() != Core::KeyBoard::Key::UP) &&
							   (key->GetKey() != Core::KeyBoard::Key::DOWN));

	return true;
}