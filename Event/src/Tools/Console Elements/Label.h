#pragma once

#include <string>
#include <vector>

#include "../../Enums/Letter.h"

namespace Core
{
	class Label
	{
	private:
		int x;
		int y;
		std::vector<std::u16string> text;

	public:
		Label();
		Label(int x, int y, std::vector<std::u16string> text);

		Label(const Label& other) = default;
		Label(Label&& other) noexcept;

	public:
		Label& operator=(const Label& other) = default;
		Label& operator=(Label&& other) noexcept;

	public:
		~Label() = default;

	public:
		void SetX(int x);
		void SetY(int y);
		void SetText(const std::vector<std::u16string>& text);
		void SetText(const std::string& message, Fonts font = Fonts::EMPTY);

	public:
		int GetX() const;
		int GetY() const;
		std::vector<std::u16string> GetText() const;

	public:
		friend std::ostream& operator<<(std::ostream& out, const Label& label);
	};
}