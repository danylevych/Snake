#pragma once

#define WINDOW_WIDTH 43 
#define WINDOW_HEIGHT 30

#pragma region ENUMERATIONS

namespace ENUM // Enumerations for game & menu
{
	enum class Direction
	{
		STOP,
		UP,
		DOWN,
		RIGHT,
		LEFT,
		MAX_ELEMENT
	};
}
#pragma endregion ENUMERATIONS

#pragma region STRUCTURES

#include <string>
#include <vector>

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