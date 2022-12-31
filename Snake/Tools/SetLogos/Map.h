#pragma once

#include <fstream>
#include <vector>
#include <string>


class Map
{
private:
	std::string path;
	std::vector<std::string> field;

public:
	Map();
	Map(const std::string& path);
	Map(const Map& other);

	std::vector<std::string>& GetMap() { return field; }
	std::vector<std::string>& GetMap(const std::string& path);
	const std::string& GetPath() const { return path; }
	void SetFild(const std::string& path);
};