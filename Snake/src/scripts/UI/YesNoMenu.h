#pragma once

#include <functional>
#include "../../../../Event/Core.hpp"


class YesNoMenu : public Core::IMenu
{
private:
	std::function<void()> noButton;
	std::function<void()> yesButton;
	
public:
	YesNoMenu(const std::function<void()>& yesButton, const std::function<void()>& noButton);

private:
	virtual void Init() override;

public:
	virtual bool MainLoop() override;
};
