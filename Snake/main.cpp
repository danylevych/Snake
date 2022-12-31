#include <Windows.h>

#include "Menu.h"
#include "../Snake/Tools/Console.h"
#include "../Snake/Tools/FileManager/FileManager.h"


int main()
{
	/*
		 _ \   _ \    \ \  / _ \  |  |   \ \      / _ \   \ | __ __|    _ \ |       \ \ \  /     __|    \     \  |  __| __ \
		|  | (   |     \  / (   | |  |    \ \ \  / (   | .  |    |      __/ |      _ \ \  /     (_ |   _ \   |\/ |  _|    _/
		___/ \___/      _| \___/ \__/      \_/\_/ \___/ _|\_|   _|     _|  ____| _/  _\ _|     \___| _/  _\ _|  _| ___|  _)
	*/

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	WindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	HideScrollbar();
	ShowConsoleCursor(false);

	Menu menu;

	StartInfo st;
	if (FileManager::ReadStartInfo("StartInfo.bin", st))
	{
		menu(st.level, st.songPath, st.isSong);
	}
	else
	{
		menu();
	}
	
	menu.Loading();
	menu.MainMenu();

	return 0;
}