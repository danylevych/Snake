#pragma once

#include <string>
#include <vector>
#include "../Tools.h"

class FileManager
{
public:
	static void ReadLogo(const std::string& path, std::vector<std::string>& buf);
	static void ReadLevel(const std::string& path, std::vector<std::string>& field);
	static bool ReadStartInfo(const std::string& path, StartInfo& st);
	static void WriteStartInfo(const std::string& path, const StartInfo& st);
	static void SoundPlay(const std::wstring& path);
	static void OpenOrCloseSound(const std::wstring& path, bool open = true);
	
};