#include "Console.h"

HANDLE hConsole{};

#pragma region SHOW CONSOLE CURSOR

inline void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; 
	SetConsoleCursorInfo(out, &cursorInfo);
}

inline void SetConsoleCursor(int x, int y)
{
    COORD position = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, position);
}

#pragma endregion SHOW CONSOLE CURSOR

#pragma region HIDE CONSOLE SCROLLBAR

inline void HideScrollbar()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
   
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
    
    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;
    
    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;
    
    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;
    
    int Status = SetConsoleScreenBufferSize(hOut, newSize);
    if (Status == 0)
    {
        exit(Status);
    }
    
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
}

#pragma endregion CONSOLE SCROLLBAR

#pragma region WINDOW SIZE

inline void WindowSize(int width = WINDOW_WIDTH, int height = WINDOW_HEIGHT)
{
    HANDLE wHnd;
    SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };
    COORD bufferSize = { width, height };
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

#pragma endregion WINDOW SIZE