#pragma once
#include <Windows.h>

#pragma region SELECT CONSOLE COLOR

extern HANDLE hConsole;
#define GET_CONSOLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define A_COLOR SetConsoleTextAttribute(hConsole, 10); // Green - Application Console Color
#define U_COLOR  SetConsoleTextAttribute(hConsole, 4); // Red - User Console Color
#define S_COLOR  SetConsoleTextAttribute(hConsole, 2); // Dark Green - Seccess Console Color

#pragma endregion SELECT CONSOLE COLOR

#pragma region SHOW CONSOLE CURSOR

extern void ShowConsoleCursor(bool showFlag); // Hide console cursore.
extern void SetConsoleCursor(int x, int y);   // Set console cursore in position.

#pragma endregion SHOW CONSOLE CURSOR

#pragma region HIDE CONSOLE SCROLLBAR

extern void HideScrollbar();

#pragma endregion CONSOLE SCROLLBAR

#pragma region WINDOW SIZE

#define WINDOW_WIDTH 43 
#define WINDOW_HEIGHT 30

extern void WindowSize(int width, int height);

#pragma endregion WINDOW SIZE