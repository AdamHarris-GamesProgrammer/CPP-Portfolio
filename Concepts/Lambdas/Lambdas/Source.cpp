#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void ForEach(const std::vector<int>& values, void (*func)(int)) {
	for (int value : values) func(value);
}

void ForEach(const std::vector<int>& values, std::function<void(int)>& func) {
	for (int value : values) func(value);
}

void StringTest(std::string str, void (*func)(std::string)) {
	func(str);
}

void StringLength(std::string value) {
	std::cout << value << " is " << value.length() << " characters long" << std::endl;
}

//This function is used to pass in two values 
int Calculate(int numA, int numB, int(*function)(int, int)) {
	int result = function(numA, numB);
	return result;
}

//This function is used to add numA and numB together
int Add(int numA, int numB) {
	return numA + numB;
}

//This function is used to subtract numB from numA
int Subtract(int numA, int numB) {
	return numA - numB;
}

//This function is used to multiple numA by numB
int Multiply(int numA, int numB) {
	return numA * numB;
}

//This function is used to divide numA by numB
int Divide(int numA, int numB) {
	return numA / numB;
}

int main() {
	std::vector<int> values = { 1,2,5,4,2,3 };

	//ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
	//ForEach(values, [](int value) { std::cout << "Value plus 3: " << value + 3 << std::endl; });
	//ForEach(values, [](int value) { std::cout << "Value minus 5: " << value - 5 << std::endl; });
	//ForEach(values, [](int value) { 
	//	value *= 2; value -= 3; 
	//	if (value > 5) { std::cout << value << " is greater than 5" << std::endl; }
	//	else if (value == 5) { std::cout << value << " is equal to 5" << std::endl; }
	//	else { std::cout << value << " is less than 5" << std::endl; } 
	//});
	//StringTest("Hello World", [](std::string value) { std::cout << value << std::endl; });
	//StringTest("Hello Jackie!", StringLength);

	std::cout << Calculate(5, 3, Add) << std::endl;
	std::cout << Calculate(5, 3, Subtract) << std::endl;
	std::cout << Calculate(5, 3, Multiply) << std::endl;
	std::cout << Calculate(6, 3, Divide) << std::endl;


	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
	std::cout << *it << std::endl;

	it = std::find_if(values.begin(), values.end(), [](int value) { return value / 2 == 1; });
	std::cout << *it << std::endl;

	it = std::find_if(values.begin(), values.end(), [](int value) { return value * 2 == 6; });
	std::cout << *it << std::endl;


	std::cin.get();

	return 0;
}

//A lambda is used instead of a function pointer
//it is a way to define a function without having to declare a function 
//