#include "../HEADERS/timer.h"
using namespace std;

Timer::Timer() {
}

void	Timer::start() {
	startTime = clock();
}
double Timer::end(const std::string& message, std::ostream& out) {
	endTime = clock();
	double result = (double)(endTime - startTime);
	out << message << "\n";
	out << result << "\n";
	return result;
}