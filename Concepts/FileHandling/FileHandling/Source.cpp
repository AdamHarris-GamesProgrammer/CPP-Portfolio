//Conio is supported by most compilers but not all
#include <conio.h>

#include <fstream>

namespace BasicString {
	//This function prints a message based on a array of chars
	void Print(const char* message, bool lineBreak = true)
	{
		//This loop uses pointer arithmetic to get the next value of the message array
		for (; *message != 0; message++) { //0 in ASCII is NULL making it the ideal character for termination
			_putch(*message);
		}

		if (lineBreak) _putch('\n');
	}

	//This function reads input from the user and stores it in the char* buffer that is passed in. 
	void Read(char* buf, int maxSize)
	{
		const char* const pEnd = buf + maxSize;

		//This for loop does two things every increment, setting c equal to the input and increment the buffer pointer
		//This for loop will continue to read input from the user until they press the enter key or until the buffer is larger then the max size
		for (char c = _getch(); c != 13 && buf + 1 < pEnd; c = _getch(), buf++) {
			*buf = c;
			_putch(c); //outputs what the user is typing to the user making it easier to use. 
		}

		//Adds the null terminator to the end of the string
		*buf = 0;
	}

	void ReverseString(char* buffer) {
		char* bufferEnd = buffer;
		for (; *bufferEnd != 0; bufferEnd++);
		//Decrements bufferEnd to accommodate for the null terminator
		bufferEnd--;

		for (; buffer < bufferEnd; buffer++, bufferEnd--) {
			//creates a temp variable to hold the value at the current buffer place
			const char temp = *buffer;
			//swaps the buffer value to the buffer end value
			*buffer = *bufferEnd;
			//sets the buffer end value to the temp value, resulting in the two values being switched
			*bufferEnd = temp;
		}
	}

	int StrToInt(const char* startPoint)
	{
		//scan to start point
		const char* endPoint = startPoint;

		//Increments the endpoint pointer until it meets a invalid character or the null terminator
		for (; *endPoint >= '0' && *endPoint <= '9'; endPoint++);

		//decrements the endPoint pointer to accommodate for the null terminator
		endPoint--;


		int value = 0;
		int place = 1;

		//convert place values and accumulate value
		for (; endPoint >= startPoint; endPoint--) {
			value += (*endPoint - '0') * place;
			place *= 10;
		}

		return value;
	}

	void IntToStr(int val, char* buffer, int size)
	{
		char* const pStart = buffer;
		char* const pEnd = buffer + size;
		for (; val > 0 && (buffer + 1 < pEnd); val /= 10, buffer++) {
			*buffer = '0' + val % 10; //get the lowest digit value and convert it to ASCII and store in buffer
		}

		//Adds the null terminator to the end of the buffer
		*buffer = 0;

		ReverseString(pStart);
	}
}

using namespace BasicString;

int main()
{
	//ifstream is a input file stream
	std::ifstream inFile("LoadTest.txt");

	if (inFile) {
		BasicString::Print("LoadTest.txt has been loaded");
	}
	else
	{
		BasicString::Print("LoadTest.txt has failed to load");
		return -1;
	}

	//moves the get pointer to position 7
	inFile.seekg(7);

	//moves the get pointer to 2 bytes after the current position
	inFile.seekg(2, std::ios_base::cur);

	//moves the get pointer to 3 bytes before the current position
	inFile.seekg(-3, std::ios_base::cur);

	//gets the length of the get pointer in the file
	inFile.seekg(0, std::ios_base::end);
	const int length = inFile.tellg();
	BasicString::Print("[File Size]: ", false);
	char buffer[256];
	BasicString::IntToStr(length, buffer, 256);
	BasicString::Print(buffer, false);
	BasicString::Print(" bytes");

	inFile.seekg(0, std::ios_base::beg);

	//inFile.get() gets the next character in the stream
	for(char c = inFile.get(); inFile.good(); c = inFile.get()) {
		_putch(c);
	}
	_putch('\n');

	if (inFile.bad()) {
		BasicString::Print("Error: LoadTest.txt");
	}
	else if (inFile.eof()) {
		BasicString::Print("Successfully reached end of file");
	}
	else
	{
		BasicString::Print("Error encountered");
	}

	std::ofstream outFile("out.txt");

	for (char c = _getch(); c != 13; c = _getch()) {
		outFile.put(c);
		_putch(c); //outputs what the user is typing to the user making it easier to use. 
	}

	//seek p
	outFile.seekp(0, std::ios_base::beg);

	//This line means the program will continue until the user hits a keyboard button
	while (!_kbhit());

	return 0;
}