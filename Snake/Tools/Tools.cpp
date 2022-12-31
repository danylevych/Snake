#include "Tools.h"

#include <iostream>
#include <codecvt>
#include <deque>

void PrintScore(uint32_t score)
{
	std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
	TextScore scoreText;
	std::deque<uint32_t> scoreNum;

	do
	{
		scoreNum.push_front(score % 10);
		score /= 10;
	} while (score);


	for (size_t i = 0; i < scoreText.lenghtStr; i++)
	{
		std::cout << converter.to_bytes(scoreText.labelScore[i]);
		std::cout << "\b";

		for (auto iter = scoreNum.begin(); iter != scoreNum.end(); ++iter)
		{
			switch (*iter)
			{
			case 0:
				std::cout << converter.to_bytes(scoreText.zero[i]);
				break;

			case 1:
				std::cout << converter.to_bytes(scoreText.one[i]);
				break;

			case 2:
				std::cout << converter.to_bytes(scoreText.two[i]);
				break;

			case 3:
				std::cout << converter.to_bytes(scoreText.three[i]);
				break;

			case 4:
				std::cout << converter.to_bytes(scoreText.four[i]);
				break;

			case 5:
				std::cout << converter.to_bytes(scoreText.five[i]);
				break;

			case 6:
				std::cout << converter.to_bytes(scoreText.six[i]);
				break;

			case 7:
				std::cout << converter.to_bytes(scoreText.seven[i]);
				break;

			case 8:
				std::cout << converter.to_bytes(scoreText.eight[i]);
				break;

			case 9:
				std::cout << converter.to_bytes(scoreText.nine[i]);
				break;
			}
		}
		std::cout << std::endl;
	}
}