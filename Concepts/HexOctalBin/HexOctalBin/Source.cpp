#include <iostream>

int main() {
	int number;

	std::cout << "What number would you like to convert: ";
	std::cin >> number;

	std::cout << "Number in base 10: " << number << std::endl;
	std::cout << "Number in base 16: " << std::hex << number << std::endl;
	std::cout << "Number in base 8: " << std::oct << number << std::endl;

}