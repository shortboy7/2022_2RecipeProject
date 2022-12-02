#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include <string>
#include <iostream>

class Timer{
private:
	clock_t startTime;
	clock_t endTime;
public:
	Timer();
	double end(const std::string& message = "time", std::ostream& out = std::cout);
};
#endif