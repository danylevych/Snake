#include "FileManager.h"

#include "FileExeption.h"

#include <string>
#include <fstream>
#include <codecvt>
#include <iostream>
#include <Windows.h>

#pragma comment(lib, "winmm.lib") // So that you can start the mp3 file

void FileManager::ReadLogo(const std::string& path, std::vector<std::string>& buf)
{
	std::ifstream in;
	std::string str;

	try
	{
		in.open(path);

		if (!in.is_open())
		{
			throw FileExeption("Error opening fail!", __func__, path);
		}

		while (!in.eof())
		{
			str = "";
			std::getline(in, str);
			buf.push_back(str);
		}

		in.close();
	}
	catch (const FileExeption& exe)
	{
		std::cerr << exe.WhatHappend() << std::endl;
		std::cerr << "Path: " << exe.Path() << std::endl;
		std::cerr << "In function: " << exe.Where() << std::endl;
		in.close();
		std::exit(-1);
	}
}

void FileManager::ReadLevel(const std::string& path, std::vector<std::string>& field)
{
	std::ifstream in;

	try
	{
		in.open(path);

		if (!in.is_open())
		{
			throw FileExeption("Error reading level!", __func__, path);
		}

		std::string temp;
		while (!in.eof())
		{
			temp = "";
			std::getline(in, temp);
			field.push_back(temp);
		}
		in.close();
	}
	catch (const FileExeption& exe)
	{
		std::cerr << exe.WhatHappend() << std::endl;
		std::cerr << "Path: " << exe.Path() << std::endl;
		std::cerr << "In function: " << exe.Where() << std::endl;
		in.close();
		std::exit(-1);
	}

}

bool FileManager::ReadStartInfo(const std::string& path, StartInfo& st)
{
	std::ifstream in;
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

	in.open(path);
	if (!in.is_open())
	{
		return false;
	}
	
	std::vector<std::string> values;
	values.reserve(3);

	while (!in.eof())
	{
		std::string temp;
		in >> temp;
		values.push_back(temp);
	}

	st = { StartInfo { values[0].data(), converter.from_bytes(values[1]).data(), static_cast<bool>(std::atoi(values[2].data())) } };

	in.close();
	
	return true;
}

void FileManager::WriteStartInfo(const std::string& path, const StartInfo& st)
{
	std::ofstream out(path);
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

	out << st.level << "\n" << converter.to_bytes(st.songPath) << "\n" << st.isSong << std::endl;
	out.close();
}

void FileManager::SoundPlay(const std::wstring& path)
{
	mciSendString(std::wstring(L"play " + path).data(), nullptr, 0, nullptr);
}

void FileManager::OpenOrCloseSound(const std::wstring& path, bool open)
{
	// If value variable open is true, then .mp3 file will open, else close 
	if (open)
	{
		mciSendString(std::wstring(L"open " + path).data(), nullptr, 0, nullptr);
	}
	else
	{
		mciSendString(std::wstring(L"close " + path).data(), nullptr, 0, nullptr);
	}
}