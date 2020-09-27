#include <iostream>

int main() {
	//defines a new type called data based off the integer
	typedef int date;

	enum Months
	{
		January = 1, 
		Feburary,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

	date todaysDate = 15;

	Months currentMonth = April;

	std::cout << todaysDate << "/" << currentMonth << "/2020" << std::endl;

	return 0;
}