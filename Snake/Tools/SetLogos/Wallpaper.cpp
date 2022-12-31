#include "Wallpaper.h"

#include <ostream>
#include <vector>
#include <string>

#include "../Tools.h"
#include "../FileManager/FileManager.h"

const std::string Wallpaper::loadingWall      = R"(Pictures\Logos\Loading.txt)";
const std::string Wallpaper::mainWall         = R"(Pictures\Logos\Logo.txt)";
const std::string Wallpaper::startGameWall    = R"(Pictures\Logos\LogoStartGame.txt)";
const std::string Wallpaper::levelsWall       = R"(Pictures\Logos\LogoLevel.txt)";
const std::string Wallpaper::optionWall       = R"(Pictures\Logos\LogoOption.txt)";
const std::string Wallpaper::opBackSoundWall  = R"(Pictures\Logos\BackroundSoundOption.txt)";
const std::string Wallpaper::opOtherSoundWall = R"(Pictures\Logos\BackroundSoundSelect.txt)";
const std::string Wallpaper::infoWall         = R"(Pictures\Logos\InformationLogo.txt)";
const std::string Wallpaper::yesOrNoWall      = R"(Pictures\Logos\YesOrNoLogo.txt)";
											   

void Wallpaper::SelectPath(const ENUM::Wallpapers& which)
{
	switch (which)
	{
	case ENUM::Wallpapers::LOADING:
		path = loadingWall;
		break;

	case ENUM::Wallpapers::MAIN:
		path = mainWall;
		break;

	case ENUM::Wallpapers::STATRT_GAME:
		path = startGameWall;
		break;

	case ENUM::Wallpapers::LEVELS:
		path = levelsWall;
		break;

	case ENUM::Wallpapers::OPTIONS:
		path = optionWall;
		break;

	case ENUM::Wallpapers::OP_BACKGROUND_SOUND:
		path = opBackSoundWall;
		break;

	case ENUM::Wallpapers::OP_OTHER_SOUND:
		path = opOtherSoundWall;
		break;

	case ENUM::Wallpapers::INFORMATION:
		path = infoWall;
		break;

	case ENUM::Wallpapers::YES_OR_NO:
		path = yesOrNoWall;
		break;
	}
}

Wallpaper::Wallpaper(const ENUM::Wallpapers& which)
	: which(which)
{
	SelectPath(which);
	FileManager::ReadLogo(path, wallpapers);
}

void Wallpaper::operator=(const Wallpaper& other)
{
	if (this != &other)
	{
		which = other.which;
		path = other.path;
		wallpapers = other.wallpapers;
	}
}

void Wallpaper::RefreshWallpaper(const ENUM::Wallpapers& newWall)
{
	which = newWall;
	SelectPath(which);
	FileManager::ReadLogo(path, wallpapers);
}
