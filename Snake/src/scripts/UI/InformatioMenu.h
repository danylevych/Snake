#pragma once

#include <functional>
#include "../../../../Event/Core.hpp"


class InformatioMenu : public Core::IMenu
{
private:
	std::string whatWall;
	std::function<void()> backButton;

public:
	InformatioMenu(const std::string& whatWall, const std::function<void()>& backButton);

private:
	virtual void Init() override;

public:
	virtual bool MainLoop() override;
};