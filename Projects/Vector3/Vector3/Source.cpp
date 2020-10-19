#include "Vector3.h"
#include <iostream>

int main() {
	Vector3 a(1.0f, 2.0f, 3.0f);
	Vector3 b(4.0f, 5.0f, 6.0f);

	Vector3 c = a.CrossProduct(b);
	c.Display();

	float dotProduce = a.DotProduct(b);
	std::cout << "Dot Product: " << dotProduce << std::endl;

	Vector3 d = a.Normalization();
	d.Display();

	float magnitude = a.Magnitude();
	std::cout << "Magnitude: " << magnitude << std::endl;

	float distance = a.Distance(b);
	std::cout << "Distance: " << distance << std::endl;

	return 0;
}