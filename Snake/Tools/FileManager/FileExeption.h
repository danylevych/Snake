#pragma once

#include <string>

class FileExeption
{
private:
	std::string whatHappend;
	std::string where;
	std::string path;

public:
	FileExeption(const std::string& whatHappend)
		: whatHappend(whatHappend)
	{	}

	FileExeption(const std::string& whatHappend, std::string where, std::string path)
		: whatHappend(whatHappend), where(where), path(path)
	{	}

	const std::string& WhatHappend() const { return whatHappend; }
	const std::string& Where() const { return where; }
	const std::string& Path() const { return path; }
};