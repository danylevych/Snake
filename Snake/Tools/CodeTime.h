#pragma once
#ifndef _CODE_TIME_H_	
#define _CODE_TIME_H_

#include <chrono>
#include <iostream>

namespace CodeTime
{
	class Time
	{
	public:
		static double DeltaTime();

	private:
		static double previousTime;
		static double currentTime;
		static const int MILLISEC_IN_SEC = 1000;
	};
}

#endif // _CODE_TIME_H_