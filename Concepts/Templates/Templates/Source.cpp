#include <iostream>

//Templates act as a way to create a function that can take different types of parameters. 
//For instance a Print method you'd need one for int, float, strings this is a lot of repetitive code and can look unclean
//These functions get created and compiled when it is needed, this can produce a slight amount of overhead
//Templates are harder to debug as it is only created when it is called, so if a variable was mispelled when you are creating it the compiler wont tell you until you utilise the template

template<typename T>
void Print(T value) {
	std::cout << value << std::endl;
}



int main() {
	Print(6);
	Print(6.5f);
	Print(6.5898989898);
	Print("Hello");

	__debugbreak();
	return 0;
}