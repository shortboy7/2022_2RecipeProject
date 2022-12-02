#include "../HEADERS/timer.h"
using namespace std;

Timer::Timer() {
	startTime = clock();
}

double Timer::end(const std::string& message, std::ostream& out) {
	endTime = clock();
	double result = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	out << message << "\n";
	out << result << "\n";
	return result;
}