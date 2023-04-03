#pragma once

#include <functional>
#include "../../../../Event/Core.hpp"


class LevelMenu : public Core::IMenu
{
private:
	std::string whatWall;
	std::function<void()> simpleButton;
	std::function<void()> middleButton;
	std::function<void()> hardButton;
	std::function<void()> backButton;

public:
	LevelMenu(const std::string& whatWall,
			  const std::function<void()>& simpleButton,
			  const std::function<void()>& middleButton,
			  const std::function<void()>& hardButton,
			  const std::function<void()>& backButton);

private:
	virtual void Init() override;

public:
	virtual bool MainLoop() override;
};
