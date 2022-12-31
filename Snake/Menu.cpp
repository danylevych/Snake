#include "Menu.h"

#include "../Snake/Tools/SetLogos/Wallpaper.h"
#include "../Snake/Tools/Console.h"
#include "../Snake/Tools/Tools.h"
#include "../Snake/Tools/FileManager/FileManager.h"
#include "../Snake/Objects/Snake.h"
#include "Game.h"

#include <conio.h>
#include <thread>
#include <iostream>
#include <fstream>
#include <codecvt> // For using std::wstring_convert
#include <iomanip>
#include <Windows.h>


void Menu::Clear() const
{
	system("cls");
}


void Menu::PrintLogo(const std::vector<std::string>& logo)
{
	for (const auto& ele : logo)
	{
		std::cout << ele << std::endl;
	}
}

bool Menu::YesOrNo(const Wallpaper& wall, int setCoursorX, int setCoursorY)
{
	char key;
	int select = static_cast<int>(ENUM::SelectMenu::NO);

	std::wstring_convert< std::codecvt_utf8<char16_t>, char16_t> converter;
	
	PrintLogo(wall.GetWallpaer());

	while (true)
	{
		SetConsoleCursor(setCoursorX, setCoursorY);

		// This loop print "YES" & "NO" in vertical orientation.
		for (size_t i = 0; i < selectMenu.size(); i++)
		{
			if (i % 2 != 0)
			{
				if (select == 1) { U_COLOR }
				else { A_COLOR }

				std::cout << converter.to_bytes(selectMenu[i]) << std::endl; A_COLOR
			}
			else
			{
				if (select == 0) { U_COLOR }
				else { A_COLOR }
				std::cout << "     " << converter.to_bytes(selectMenu[i]) << "\t  "; U_COLOR
			}
		}

		do
		{
			key = _getch();
		} while (key != static_cast<int>(ENUM::Key::ARROW) && key != static_cast<int>(ENUM::Key::ENTER));

		FileManager::SoundPlay(LR"(Sound\ButtonPress\ArrowSound.mp3)");
		if (key == static_cast<int>(ENUM::Key::ARROW))
		{
			key = _getch();
			switch (key)
			{
			case static_cast<int>(ENUM::Key::LEFT):
				(select == static_cast<int>(ENUM::SelectMenu::NO)) ? select-- : select = static_cast<int>(ENUM::SelectMenu::NO);
				break;

			case static_cast<int>(ENUM::Key::RIGHT):
				(select == static_cast<int>(ENUM::SelectMenu::YES)) ? select++ : select = static_cast<int>(ENUM::SelectMenu::YES);
				break;
			}
		}
		else if (key == static_cast<int>(ENUM::Key::ENTER))
		{
			switch (select)
			{
			case static_cast<int>(ENUM::SelectMenu::NO):
				Clear();
				return false;

			case static_cast<int>(ENUM::SelectMenu::YES):
				Clear();
				return true;
			}
		}
	}

}

void Menu::PrintButton(int press, const std::vector<std::u16string> typeMenu)
{
	std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;

	for (size_t i = 0, size = typeMenu.size(); i < size; i++)
	{
		if (i == press) { U_COLOR; }
		else { A_COLOR; }
		std::cout << converter.to_bytes(typeMenu[i]) << std::endl;
		A_COLOR;
	}
}



void Menu::BackgroundSoundOption()
{
	char key;
	int press = static_cast<int>(ENUM::BackgroundSoundMenu::BACK);

	Wallpaper wall(ENUM::Wallpapers::OP_BACKGROUND_SOUND);

	while (true)
	{
		PrintLogo(wall.GetWallpaer());
		PrintButton(press, backgroundSoundMenu);

		auto result = ArrowButton<ENUM::BackgroundSoundMenu>(press, key);

		if (key == static_cast<int>(ENUM::Key::ENTER))
		{
			bool userChoose;
			switch (result)
			{
			case ENUM::BackgroundSoundMenu::ON_SOUND: // Play background song if its off
				Clear();
				userChoose = YesOrNo(wall, 0, 20);
				if (!isSong && userChoose)
				{
					FileManager::OpenOrCloseSound(songPath, true);
					FileManager::SoundPlay((songPath + L" repeat"));
					isSong = true;
				}
				break;

			case ENUM::BackgroundSoundMenu::OFF_SOUND: // Off background song if its play
				Clear();
				userChoose = YesOrNo(wall, 0, 20);
				if (isSong && userChoose)
				{
					FileManager::OpenOrCloseSound(songPath, false);
					isSong = false;
				}
				break;

			case ENUM::BackgroundSoundMenu::OTHER_SOUND:
				Clear();
				SelectSoundMenu();
				break;

			case ENUM::BackgroundSoundMenu::BACK:
				return;
			}
		}
	}
}

void Menu::SelectSoundMenu()
{
	char key;
	int press = static_cast<int>(ENUM::OtherBackgroundSound::BACK);

	std::wstring path = songPath;
	Wallpaper wall(ENUM::Wallpapers::OP_OTHER_SOUND);

	while (true)
	{
		SetConsoleCursor(0, 0);

		PrintLogo(wall.GetWallpaer());
		PrintButton(press, otherSong);

		auto result = ArrowButton<ENUM::OtherBackgroundSound>(press, key);

		if (key != static_cast<int>(ENUM::Key::ENTER) && press != static_cast<int>(ENUM::OtherBackgroundSound::BACK))
		{
			if (isSong)
			{
				FileManager::OpenOrCloseSound(songPath, false);
			}

			FileManager::OpenOrCloseSound(path, false);

			switch (result)
			{
			case ENUM::OtherBackgroundSound::FIRST_SOUND:
				path = LR"(Sound\BackgroundSong\BackgroundSong1.mp3)";;
				break;

			case ENUM::OtherBackgroundSound::SECOND_SOUND:
				path = LR"(Sound\BackgroundSong\BackgroundSong2.mp3)";;
				break;

			case ENUM::OtherBackgroundSound::THIRD_SOUND:
				path = LR"(Sound\BackgroundSong\BackgroundSong3.mp3)";;
				break;
			}

			FileManager::OpenOrCloseSound(path, true);
			FileManager::SoundPlay(path);

		}
		else if (result == ENUM::OtherBackgroundSound::BACK)
		{
			FileManager::OpenOrCloseSound(path, false);
		}

		if (key == static_cast<int>(ENUM::Key::ENTER))
		{
			if (press != static_cast<int>(ENUM::OtherBackgroundSound::BACK))
			{
				Clear();
				if (YesOrNo(Wallpaper(ENUM::Wallpapers::YES_OR_NO), 0, 24))
				{
					// Setting path for song, and play its if its playing.
					songPath = path;
					if (isSong)
					{
						FileManager::OpenOrCloseSound(songPath, true);
						FileManager::SoundPlay(songPath + L" repeat");
					}
				}
			}
			else
			{
				if (isSong)
				{
					FileManager::OpenOrCloseSound(songPath, true);
					FileManager::SoundPlay(songPath + L" repeat");
				}
				return;
			}
		}
	}
}


void Menu::Loading()
{
	GET_CONSOLE;
	A_COLOR;

	FileManager::OpenOrCloseSound(LR"(Sound\Loading.mp3)");
	FileManager::SoundPlay(LR"(Sound\Loading.mp3)");

	Wallpaper wall(ENUM::Wallpapers::LOADING);

	Sleep(20);
	for (const auto& ele : wall.GetWallpaer())
	{
		std::cout << ele;
		Sleep(60);
	}
	Sleep(60);

	FileManager::OpenOrCloseSound(LR"(Sound\Loading.mp3)", false);
	Clear();
}


void Menu::MainMenu()
{
	GET_CONSOLE;

	char key;
	int press = 0;

	Wallpaper wall(ENUM::Wallpapers::MAIN);

	if (isSong) // Playing song.
	{
		FileManager::OpenOrCloseSound(songPath, true);
		FileManager::SoundPlay(songPath + L" repeat");
	}

	while (true)
	{
		A_COLOR;

		SetConsoleCursor(0, 0);

		PrintLogo(wall.GetWallpaer());
		std::cout << std::endl;

		PrintButton(press, mainMenu);

		auto result = ArrowButton<ENUM::MainMenu>(press, key);

		if (key == static_cast<int>(ENUM::Key::ENTER))
		{
			switch (result)
			{
			case ENUM::MainMenu::START_GAME:
				Clear();
				StartGame();
				break;

			case ENUM::MainMenu::LEVEL:
				Clear();
				LevelMenu();
				break;

			case ENUM::MainMenu::OPTIONS:
				Clear();
				OptionMenu();
				break;

			case ENUM::MainMenu::INFORMATION:
				Clear();
				InformatoimMenu();
				break;

			case ENUM::MainMenu::EXIT:
				Clear();
				if (YesOrNo(Wallpaper(ENUM::Wallpapers::YES_OR_NO), 0, 24))
				{
					// Writing start info for next start.
					FileManager::WriteStartInfo(R"(StartInfo.bin)", StartInfo{ level.data(), songPath.data(), isSong });
					std::exit(0);
				}
				break;
			}
		}

	}
}

void Menu::StartGame()
{
	while (true)
	{
		if (YesOrNo(Wallpaper(ENUM::Wallpapers::STATRT_GAME), 0, 24))
		{
			Clear();

			// Set snake in center. And tie up for Game.
			Snake snake{ WINDOW_WIDTH / 2 + 1, WINDOW_HEIGHT / 2 };
			Game game{ &snake };

			game.StartGame(level);
			Clear();
		}
		else
		{
			Clear();
			return;
		}

	}
}

void Menu::LevelMenu()
{
	char key;
	int press = 3;

	Wallpaper wall(ENUM::Wallpapers::LEVELS);

	while (true)
	{
		A_COLOR;

		SetConsoleCursor(0, 0);
		PrintLogo(wall.GetWallpaer());

		PrintButton(press, levelMenu);

		auto result = ArrowButton<ENUM::LevelMenu>(press, key);

		if (key == static_cast<int>(ENUM::Key::ENTER))
		{
			bool userChoose;
			switch (result)
			{
			case ENUM::LevelMenu::FIRST_LEVEL:
				Clear();
				userChoose = YesOrNo(Wallpaper(ENUM::Wallpapers::YES_OR_NO), 0, 24);
				if (userChoose) { level = (R"(Pictures\Levels\SimpleLevel.txt)"); }
				break;

			case ENUM::LevelMenu::SECOND_LEVEL:
				Clear();
				userChoose = YesOrNo(Wallpaper(ENUM::Wallpapers::YES_OR_NO), 0, 24);
				if (userChoose) { level = R"(Pictures\Levels\MiddleLevel.txt)"; }
				break;

			case ENUM::LevelMenu::THEERD_LEVEL:
				Clear();
				userChoose = YesOrNo(Wallpaper(ENUM::Wallpapers::YES_OR_NO), 0, 24);
				if (userChoose) { level = R"(Pictures\Levels\HardLevel.txt)"; }
				break;

			case ENUM::LevelMenu::BACK:
				Clear();
				return;
			}
		}
	}
}

void Menu::OptionMenu()
{
	char key;
	int press = static_cast<int>(ENUM::OptionsMenu::BACK);
	Wallpaper wall(ENUM::Wallpapers::OPTIONS);

	while (true)
	{
		A_COLOR;

		SetConsoleCursor(0, 0);

		PrintLogo(wall.GetWallpaer());
		PrintButton(press, optionsMenu);

		auto result = ArrowButton<ENUM::OptionsMenu>(press, key);

		if (key == static_cast<int>(ENUM::Key::ENTER))
		{
			switch (result)
			{
			case ENUM::OptionsMenu::BACKGROUND_SOUND:
				BackgroundSoundOption();
				break;

			case ENUM::OptionsMenu::BACK:
				Clear();
				return;
			}
		}
		Clear();
	}
}

void Menu::InformatoimMenu()
{
	char key;
	Wallpaper wall(ENUM::Wallpapers::INFORMATION);

	PrintLogo(wall.GetWallpaer());
	PrintButton(0, infoMenu);

	do
	{
		key = _getch();
	} while (key != static_cast<int>(ENUM::Key::ENTER));
	Clear();
}