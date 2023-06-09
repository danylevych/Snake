#include "Label.h"

#include <fstream>
#include <codecvt>
#include "../Console.h"
#include "../../Exception/EventException.h"
#include "../../Managers/File Manager/FileManager.h"

namespace Core
{
	Label::Label()
		: x(0), y(0),
		text()
	{	}

	Label::Label(int x, int y, std::vector<std::u16string> text)
		: x(x), y(y),
		text(text)
	{	}

	Label::Label(Label&& other) noexcept
	{
		x = other.x;
		y = other.y;
		text = std::move(other.text);

		other.x = 0;
		other.y = 0;
	}

	Label& Label::operator=(Label&& other) noexcept
	{
		if (this != &other)
		{
			x = other.x;
			y = other.y;
			text = std::move(other.text);

			other.x = 0;
			other.y = 0;
		}

		return *this;
	}

	void Label::SetX(int x) { this->x = x; }
	void Label::SetY(int y) { this->y = y; }
	

	void Label::SetText(const std::vector<std::u16string>& text) { this->text = text; }

	void Label::SetText(const std::string& message, Fonts font)
	{
		text.clear();
		FileManager::ReadTextForElement((font == Fonts::EMPTY ? R"(..\Event\data\Fonts\EmptyFont.txt)" :
			R"(..\Event\data\Fonts\FullFont.txt)"),
			message, text, (font == Fonts::EMPTY ? 6 : 3));
	}
	
	int Label::GetX() const { return x; }
	int Label::GetY() const { return y; }
	std::vector<std::u16string> Label::GetText() const { return text; }

	std::ostream& operator<<(std::ostream& out, const Label& label)
	{
		std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> convert;

		int temp = label.y;
		for (const auto& elem : label.text)
		{
			Console::SetCursorPosition(label.x, temp++);
			out << convert.to_bytes(elem);
		}

		return out;
	}
}