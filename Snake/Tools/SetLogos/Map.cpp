#include "Map.h"

#include "../FileManager/FileManager.h"

Map::Map()
	: path("NoPath"), field()
{	}

Map::Map(const std::string& path)
	: path(path)
{
	FileManager::ReadLevel(path, field);
}

Map::Map(const Map& other)
	: path(other.path), field(other.field)
{	}


std::vector<std::string>& Map::GetMap(const std::string& path)
{
	FileManager::ReadLevel(path, field);
	return field;
}

void Map::SetFild(const std::string& path)
{
	FileManager::ReadLevel(path, field);
}