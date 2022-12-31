#pragma once

#include <ostream>
#include <vector>
#include <tuple>
#include <string>
#include <utility>
#include "../Tools.h"


class Wallpaper
{
private:
	std::vector<std::string> wallpapers;
	ENUM::Wallpapers which;
	std::string path;

	void SelectPath(const ENUM::Wallpapers& which);

public:	
	const static std::string loadingWall;
	const static std::string mainWall;
	const static std::string startGameWall;
	const static std::string levelsWall;
	const static std::string optionWall;
	const static std::string opBackSoundWall;
	const static std::string opOtherSoundWall;
	const static std::string infoWall;
	const static std::string yesOrNoWall;


	Wallpaper() : which(ENUM::Wallpapers::NONE), wallpapers()
	{	}
	Wallpaper(const ENUM::Wallpapers& which);
	Wallpaper(const Wallpaper& other) : which(other.which), wallpapers(other.wallpapers), path(other.path)
	{	}

	void operator= (const Wallpaper& other);

	void RefreshWallpaper(const ENUM::Wallpapers& newWall);

	const std::vector<std::string>& GetWallpaer() const { return wallpapers; }

	const std::tuple<ENUM::Wallpapers, std::string, std::vector<std::string>> GetAllInfo()
	{
		return std::make_tuple(which, path, wallpapers); 
	}
};