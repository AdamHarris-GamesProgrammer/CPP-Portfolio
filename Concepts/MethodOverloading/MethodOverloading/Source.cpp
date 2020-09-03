#include <iostream>

//Methods can be overloaded, for example the method below Print(string) can take a string but what if I wanted to print a floating point value, I would need a separate method. 
//However with method overloading I can create a method with the same name but different parameter types and the compiler will automatically pick the correct option for the parameter I pass in
void Print(std::string value) {
	std::cout << value << std::endl;
}
void Print(int value) {
	std::cout << value << std::endl;
}
void Print(float value) {
	std::cout << value << std::endl;
}
void Print(double value) {
	std::cout << value << std::endl;
}
void Print(char value) {
	std::cout << value << std::endl;
}

int main() {
	//The compiler will decide what method is best based on the parameter I pass in
	Print("Hello World");
	Print(5);
	Print(3.4f);
	Print(3.42432);
	Print('A');

	return 0;
}

//Although method overloading is useful it can get incredibly messy if used in a case like this where the method is doing the same thing regardless of paramater type.
//A better option would be to use a Template
