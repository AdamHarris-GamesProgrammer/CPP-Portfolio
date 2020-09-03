#include <iostream>
#include <functional>
#include <optional>
#include <string>


//std::optional is in C++17 and later. Therefore a project using it needs to be made in C++17 or later.
std::optional<std::string> Print(bool b) {
	if (b) return "Printing Statement";
	return {};
}

int main() {
	//This line will print out two statements, the first statement will be the result of the Print method when true is passed in,
	//The second will be the result of the Print method when false is passed in, and if the value is empty it will return "Uninitialized"
	std::cout << "Print Method result when true: " << Print(true).value() 
			  << std::endl << "Print Method result when false: " 
		 	  << Print(false).value_or("Uninitialized") << std::endl;

	//std::optional can be stored as variables
	std::optional<std::string> optional1 = Print(true);

	//if a optional variable has a value it can be considered as true by the compiler
	if (optional1) {
		//this line is executed as optional1 has been assigned a value
		std::cout << "optional1 variable has a value" << std::endl;
	}
	else
	{
		//this line will not be executed as optional1 does have a value
		std::cout << "optional1 variable does not have a value" << std::endl;
	}
}