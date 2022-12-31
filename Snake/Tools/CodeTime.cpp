#include "CodeTime.h"

#include <ctime>

double CodeTime::Time::previousTime = 0;
double CodeTime::Time::currentTime = std::clock();

double CodeTime::Time::DeltaTime()
{
	previousTime = currentTime;
	currentTime = std::clock();
	return (currentTime - previousTime) / MILLISEC_IN_SEC;
}