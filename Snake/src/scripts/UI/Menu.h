#pragma once

#include "../../../../Event/Core.hpp"


class MainMenu : public Core::IMenu
{
private:
	bool isSong;
	std::wstring songPath;
	mutable std::string level;

public:
	MainMenu();
	MainMenu(const std::string& level, bool isSong);

private:
	void Loading();
	virtual void Init() override;
	
public:
	virtual bool MainLoop() override;
};