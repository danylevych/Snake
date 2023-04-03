#include <Windows.h>

#include <iostream>
#include <conio.h>

#include "../../Event/Core.hpp"
#include "scripts/UI/Menu.h"
#include "scripts/Tools/Tools.h"
#include "scripts/Tools/Paths.h"


int main()
{
	/*
		 _ \   _ \    \ \  / _ \  |  |   \ \      / _ \   \ | __ __|    _ \ |       \ \ \  /     __|    \     \  |  __| __ \
		|  | (   |     \  / (   | |  |    \ \ \  / (   | .  |    |      __/ |      _ \ \  /     (_ |   _ \   |\/ |  _|    _/
		___/ \___/      _| \___/ \__/      \_/\_/ \___/ _|\_|   _|     _|  ____| _/  _\ _|     \___| _/  _\ _|  _| ___|  _)
	*/

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	Core::Console::SetTitle(L"SNAKE");
	Core::Console::ConsoleSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	Core::Console::ScrollbarVisible(false);
	Core::Console::CursorVisible(false);

	
	try
	{
		MainMenu menu;
		while (menu.MainLoop());

		std::vector<std::string> strs;
		if (Core::FileManager::ReadFileS(Paths::startInfo, strs))
		{
			MainMenu menu{ strs[0], static_cast<bool>(std::stoi(strs[1])) };
			while (menu.MainLoop());
		}
		else
		{
			MainMenu menu;
			while (menu.MainLoop());
		}
	} 
	catch (...)
	{
		std::cerr << "Something wrong" << std::endl;
	}

	return 0;
}