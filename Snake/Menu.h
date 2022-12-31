#pragma once

#include <iostream>
#include <conio.h>
#include <codecvt>
#include <string>
#include <vector>

#include "../Snake/Tools/SetLogos/Wallpaper.h"
#include "../Snake/Tools/Tools.h"

class Menu
{
private:
#pragma region MENU POINTS
	std::vector<std::u16string> mainMenu
	{
		{ uR"( 
   █▀▀ ▀█▀ █▀█ █▀▄ ▀█▀   █▀▀ █▀█ █▄█ █▀▀
   ▀▀█  █  █▀█ █▀▄  █    █ █ █▀█ █ █ █▀▀
   ▀▀▀  ▀  ▀ ▀ ▀ ▀  ▀    ▀▀▀ ▀ ▀ ▀ ▀ ▀▀▀)"},


		{ uR"(      
         █   █▀▀ █ █ █▀▀ █   █▀▀
         █   █▀▀ ▀▄▀ █▀▀ █   ▀▀█
         ▀▀▀ ▀▀▀  ▀  ▀▀▀ ▀▀▀ ▀▀▀)"},

		{ uR"(
       █▀█ █▀█ ▀█▀ ▀█▀ █▀█ █▀█ █▀▀
       █ █ █▀▀  █   █  █ █ █ █ ▀▀█
       ▀▀▀ ▀    ▀  ▀▀▀ ▀▀▀ ▀ ▀ ▀▀▀)"},

		{ uR"(
▀█▀ █▀█ █▀▀ █▀█ █▀▄ █▄█ █▀█ ▀█▀ ▀█▀ █▀█ █▀█
 █  █ █ █▀▀ █ █ █▀▄ █ █ █▀█  █   █  █ █ █ █
▀▀▀ ▀ ▀ ▀   ▀▀▀ ▀ ▀ ▀ ▀ ▀ ▀  ▀  ▀▀▀ ▀▀▀ ▀ ▀)"},

		{ uR"(
              █▀▀ █ █ ▀█▀ ▀█▀
              █▀▀ ▄▀▄  █   █ 
              ▀▀▀ ▀ ▀ ▀▀▀  ▀ )"}
	};

	std::vector<std::u16string> levelMenu
	{
		{uR"(
           █▀▀ ▀█▀ █▄█ █▀█ █   █▀▀
           ▀▀█  █  █ █ █▀▀ █   █▀▀
           ▀▀▀ ▀▀▀ ▀ ▀ ▀   ▀▀▀ ▀▀▀)"},
		{uR"(
           █▄█ ▀█▀ █▀▄ █▀▄ █   █▀▀
           █ █  █  █ █ █ █ █   █▀▀
           ▀ ▀ ▀▀▀ ▀▀  ▀▀  ▀▀▀ ▀▀▀)"},
		{uR"(
               █ █ █▀█ █▀▄ █▀▄
               █▀█ █▀█ █▀▄ █ █
               ▀ ▀ ▀ ▀ ▀ ▀ ▀▀ )"},
		{uR"(
               █▀▄ █▀█ █▀▀ █ █
               █▀▄ █▀█ █   █▀▄
               ▀▀  ▀ ▀ ▀▀▀ ▀ ▀)"}
	};

	std::vector<std::u16string> optionsMenu
	{
		{uR"(
  █▀▄ █▀█ █▀▀ █ █ █▀▀ █▀▄ █▀█ █ █ █▀█ █▀▄
  █▀▄ █▀█ █   █▀▄ █ █ █▀▄ █ █ █ █ █ █ █ █
  ▀▀  ▀ ▀ ▀▀▀ ▀ ▀ ▀▀▀ ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀ 
             █▀▀ █▀█ █ █ █▀█ █▀▄
             ▀▀█ █ █ █ █ █ █ █ █
             ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀ 
		)"},

		{uR"(
             █▀▄ █▀█ █▀▀ █ █
             █▀▄ █▀█ █   █▀▄
             ▀▀  ▀ ▀ ▀▀▀ ▀ ▀
		)"}
	};

	std::vector<std::u16string> backgroundSoundMenu
	{
		{uR"(
       █▀█ █▀█    █▀▀ █▀█ █ █ █▀█ █▀▄
       █ █ █ █    ▀▀█ █ █ █ █ █ █ █ █
       ▀▀▀ ▀ ▀    ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀ )"},

		{uR"(
      █▀█ █▀▀ █▀▀   █▀▀ █▀█ █ █ █▀█ █▀▄
      █ █ █▀▀ █▀▀   ▀▀█ █ █ █ █ █ █ █ █
      ▀▀▀ ▀   ▀     ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀ )"},

		{uR"(
 █▀█ ▀█▀ █ █ █▀▀ █▀▄   █▀▀ █▀█ █ █ █▀█ █▀▄
 █ █  █  █▀█ █▀▀ █▀▄   ▀▀█ █ █ █ █ █ █ █ █
 ▀▀▀  ▀  ▀ ▀ ▀▀▀ ▀ ▀   ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀ )"},

		{uR"(
              █▀▄ █▀█ █▀▀ █ █
              █▀▄ █▀█ █   █▀▄
              ▀▀  ▀ ▀ ▀▀▀ ▀ ▀)"}
	};

	std::vector<std::u16string> otherSong
	{
		{uR"(
            █▀▀ ▀█▀ █▀▄ █▀▀ ▀█▀   
            █▀▀  █  █▀▄ ▀▀█  █    
            ▀   ▀▀▀ ▀ ▀ ▀▀▀  ▀    
        )"},
        
        { uR"(
          █▀▀ █▀▀ █▀▀ █▀█ █▀█ █▀▄
          ▀▀█ █▀▀ █   █ █ █ █ █ █
          ▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀ 
        )" },
        
        { uR"(
            ▀█▀ █ █ ▀█▀ █▀▄ █▀▄   
             █  █▀█  █  █▀▄ █ █   
             ▀  ▀ ▀ ▀▀▀ ▀ ▀ ▀▀    
		)" },

		{ uR"(
              █▀▄ █▀█ █▀▀ █ █
              █▀▄ █▀█ █   █▀▄
              ▀▀  ▀ ▀ ▀▀▀ ▀ ▀
		)" }
	};

	std::vector<std::u16string> infoMenu
	{
			{ uR"(
              █▀▄ █▀█ █▀▀ █ █
              █▀▄ █▀█ █   █▀▄
              ▀▀  ▀ ▀ ▀▀▀ ▀ ▀)" }
	};

	std::vector<std::u16string> selectMenu
	{
		{u"██ ██ ███ ███"}, {u"█  █ ████"},
		{u" ███  █   █  "}, {u"██ █ █  █"},
		{u"  █   ███ ███"}, {u"█ ██ █  █"},
		{u"  █   █     █"}, {u"█  █ █  █"},
		{u"  █   ███ ███"}, {u"█  █ ████"},

	};
#pragma endregion MENU POINTS

	bool isSong;
	std::wstring songPath;
	std::string level;

	void Clear() const;
	bool YesOrNo(const Wallpaper& wall, int setCoursorX, int setCoursorY);
	void PrintButton(int press, const std::vector<std::u16string> typeMenu); // Print current button in U_COLOR
	void PrintLogo(const std::vector<std::string>& logo);

	void BackgroundSoundOption();
	void SelectSoundMenu();

	void StartGame();
	void LevelMenu();
	void OptionMenu();
	void InformatoimMenu();

	template <typename Enum>
	friend Enum ArrowButton(int& press, char& kay);

public:
	Menu() 
		: level(R"(Pictures\Levels\SimpleLevel.txt)"), songPath(LR"(Sound\BackgroundSong\BackgroundSong1.mp3)"), isSong(true)
	{	}
	Menu(const std::string& level, const std::wstring& songPath, bool isSong = true) 
		: level(level), songPath(songPath), isSong(isSong)
	{	}

	void Loading();
	void MainMenu();

	void operator()(const std::string& level = R"(Pictures\Levels\SimpleLevel.txt)", 
		const std::wstring& songPath = LR"(Sound\BackgroundSong\BackgroundSong1.mp3)", bool isSong = true)
	{
		this->level = level;
		this->songPath = songPath;
		this->isSong = isSong;
	}

	void operator()(const std::shared_ptr<char[]>& level, const std::shared_ptr<wchar_t[]>& songPath, bool isSong = true)
	{
		this->level = level.get();
		this->songPath = songPath.get();
		this->isSong = isSong;
	}
};


/*	This function I created, beause many of methods in Menu class
* use the key arrow. First argument - current select on different
* menu. Second argument - current button press.
*/
template<typename Enum>
inline Enum ArrowButton(int& press, char& key)
{
	do
	{
		key = _getch();
	} while (key != static_cast<int>(ENUM::Key::ARROW) && key != static_cast<int>(ENUM::Key::ENTER));

	if (key == static_cast<int>(ENUM::Key::ARROW))
	{
		key = _getch();
		if (key == static_cast<int>(ENUM::Key::UP))
		{
			press > 0 ? press-- : press = static_cast<int>(Enum::MAX_ELEMENT) - 1;
		}
		else if (key == static_cast<int>(ENUM::Key::DOWN))
		{
			press < static_cast<int>(Enum::MAX_ELEMENT) - 1 ? press++ : press = 0;
		}
	}

	return static_cast<Enum>(press);
}