#pragma once

#include <functional>
#include "../../../../Event/Core.hpp"


class OptionsMenu : public Core::IMenu
{
private:
	std::string whatWall;
	std::function<void()> OnSoundButton;
	std::function<void()> OffSoundButton;
	std::function<void()> backButton;

public:
	OptionsMenu(const std::string& whatWall,
				const std::function<void()>& OnSoundButton,
				const std::function<void()>& OffSoundButton,
				const std::function<void()>& backButton);

private:
	virtual void Init() override;

public:
	virtual bool MainLoop() override;
};