#include <iostream>
#include <string>

struct personDetails {
	std::string name;
	std::string telephoneNumber;
	int age;

	void PrintDetails() {
		std::cout << "NAME: " << name << std::endl;
		std::cout << "AGE: " << age << std::endl;
		std::cout << "TELEPHONE NUMBER: " << telephoneNumber << std::endl;
	}
};

int main() {
	personDetails adam;

	std::cout << "Please enter the persons name: ";
	std::cin >> adam.name;
	std::cout << "Please enter the persons age: ";
	std::cin >> adam.age;
	std::cout << "Please enter the persons telephone number: ";
	std::cin >> adam.telephoneNumber;

	adam.PrintDetails();
	return 0;
}
