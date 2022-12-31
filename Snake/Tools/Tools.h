#pragma once

#pragma region ENUMERATIONS

namespace ENUM // Enumerations for game & menu
{
	enum class Key
	{
		ARROW = -32,
		UP = 72,
		DOWN = 80,
		LEFT = 75,
		RIGHT = 77,
		ENTER = 13
	};
	
	enum class Direction
	{
		STOP,
		UP,
		DOWN,
		RIGHT,
		LEFT,
		MAX_ELEMENT
	};

	enum class MainMenu
	{
		START_GAME,
		LEVEL,
		OPTIONS,
		INFORMATION,
		EXIT,
		MAX_ELEMENT
	};

	enum class LevelMenu
	{
		FIRST_LEVEL,
		SECOND_LEVEL,
		THEERD_LEVEL,
		BACK,
		MAX_ELEMENT
	};

	enum class SelectMenu
	{
		YES,
		NO,
		MAX_ELEMENT
	};

	enum class OptionsMenu
	{
		BACKGROUND_SOUND,
		BACK,
		MAX_ELEMENT
	};

	enum class BackgroundSoundMenu
	{
		ON_SOUND,
		OFF_SOUND,
		OTHER_SOUND,
		BACK,
		MAX_ELEMENT
	};

	enum class OtherBackgroundSound
	{
		FIRST_SOUND,
		SECOND_SOUND,
		THIRD_SOUND,
		BACK,
		MAX_ELEMENT
	};

	enum class Wallpapers
	{
		LOADING,
		MAIN,
		STATRT_GAME,
		LEVELS,
		OPTIONS,
		OP_BACKGROUND_SOUND,
		OP_OTHER_SOUND,
		INFORMATION,
		YES_OR_NO,
		NONE
	};

}
#pragma endregion ENUMERATIONS

#pragma region STRUCTURES

#include <string>
#include <vector>

struct StartInfo
{
	std::string level;
	std::wstring songPath;
	bool isSong = true;
};

struct Point
{
	int x;
	int y;
};

struct TextScore
{
	size_t lenghtStr = 6;

	std::vector<std::u16string> labelScore
	{
		{u"  ╔══╗╔══╗╔══╗╔═══╗╔═══╗ ╔╗ "},
		{u"  ║╔═╝║╔═╝║╔╗║║╔═╗║║╔══╝ ╚╝ "},
		{u"  ║╚═╗║║  ║║║║║╚═╝║║╚══╗    "},
		{u"  ╚═╗║║║  ║║║║║╔╗╔╝║╔══╝    "},
		{u"  ╔═╝║║╚═╗║╚╝║║║║║ ║╚══╗ ╔╗ "},
		{u"  ╚══╝╚══╝╚══╝╚╝╚╝ ╚═══╝ ╚╝ "}
	};

	std::vector<std::u16string> zero
	{
		{u" ╔══╗"},
		{u" ║╔╗║"},
		{u" ║║║║"},
		{u" ║║║║"},
		{u" ║╚╝║"},
		{u" ╚══╝"}
	};

	std::vector<std::u16string> one
	{
		{u"  ╔╗"},
		{u" ╔╝║"},
		{u" ╚╗║"},
		{u"  ║║"},
		{u"  ║║"},
		{u"  ╚╝"}
	};

	std::vector<std::u16string> two
	{
		{u" ╔══╗"},
		{u" ╚═╗║"},
		{u" ╔═╝║"},
		{u" ║╔═╝"},
		{u" ║╚═╗"},
		{u" ╚══╝"}
	};

	std::vector<std::u16string> three
	{
		{u" ╔══╗"},
		{u" ╚═╗║"},
		{u" ╔═╝║"},
		{u" ╚═╗║"},
		{u" ╔═╝║"},
		{u" ╚══╝"}
	};

	std::vector<std::u16string> four
	{
		{u" ╔╗╔╗"},
		{u" ║║║║"},
		{u" ║╚╝║"},
		{u" ╚═╗║"},
		{u"   ║║"},
		{u"   ╚╝"}
	};

	std::vector<std::u16string> five
	{
		{u" ╔══╗"},
		{u" ║╔═╝"},
		{u" ║╚═╗"},
		{u" ╚═╗║"},
		{u" ╔═╝║"},
		{u" ╚══╝"}
	};

	std::vector<std::u16string> six
	{
		{u" ╔══╗"},
		{u" ║╔═╝"},
		{u" ║╚═╗"},
		{u" ║╔╗║"},
		{u" ║╚╝║"},
		{u" ╚══╝"}
	};

	std::vector<std::u16string> seven
	{
		{u" ╔══╗"},
		{u" ╚═╗║"},
		{u"   ║║"},
		{u"   ║║"},
		{u"   ║║"},
		{u"   ╚╝"}
	};

	std::vector<std::u16string> eight
	{
		{u" ╔══╗"},
		{u" ║╔╗║"},
		{u" ║╚╝║"},
		{u" ║╔╗║"},
		{u" ║╚╝║"},
		{u" ╚══╝"}
	};

	std::vector<std::u16string> nine
	{
		{u" ╔══╗"},
		{u" ║╔╗║"},
		{u" ║╚╝║"},
		{u" ╚═╗║"},
		{u" ╔═╝║"},
		{u" ╚══╝"}
	};
};

void PrintScore(uint32_t score);

#pragma endregion STRUCTURES