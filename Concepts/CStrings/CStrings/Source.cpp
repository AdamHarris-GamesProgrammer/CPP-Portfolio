//Conio is supported by most compilers but not all
#include <conio.h>

//This function prints a message based on a array of chars
void Print(const char* message) 
{
	//This loop uses pointer arithmetic to get the next value of the message array
	for (; *message != 0; message++) { //0 in ASCII is NULL making it the ideal character for termination
		_putch(*message);
	}
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



int Fibonacci(int n) {
	//variables required for algorithm
	int previousVal = 1;
	int secondPreviousVal = 0;
	int total = 0;

	//the first two results of a Fibonacci sequence are 0 and 1 therefore just return n - 1
	if (n <= 2) return n - 1;

	for (int i = 2; i < n; i++) {
		total = secondPreviousVal + previousVal;

		secondPreviousVal = previousVal;
		previousVal = total;
	}

	return total;
}



int main() 
{
	//This does not output the number 15 this instead outputs corresponding ASCII glyph. In this case it is a question mark in a box
	//_putch(15);

	//65 is A
	//_putch(65);

	//Hello world in ASCII
	//These lines output a collection of chars to spell Hello World
	/*_putch(72);
	_putch(101);
	_putch(108);
	_putch(108);
	_putch(111);
	_putch(32);
	_putch(87);
	_putch(111);
	_putch(114);
	_putch(108);
	_putch(100);*/

	//Alternatively you can use the char literal ''
	//This line will tell the compiler to get the ASCII value of H
	//_putch('\n');
	//_putch('H');
	//\n means new line
	//_putch('\n');

	//Print("Hello World\n");

	//This is known as a C-String it is just a array of characters where 0 represents the end of the string 
	//const char msg[] = { 'H', 'e', 'l', 'l', 'o', '\n', 0 };
	//Print(msg);
	
	//The "" operators can create a array of chars with a  automatic added null terminator at the end, saves time and effort
	//This array may look like it has a size of 6 chars but it actually has a size of 8 due to the null terminator
	//const char msg2[] = "Hello!\n";
	//Print(msg2);

	//You can use a escape operator to put a double quote into a string
	//This outputs Hello "World"
	//const char msg3[] = "Hello \"World\"\n";
	//Print(msg3);

	//As these variables are not const they can be manipulated after initialization
	//char msg4[] = "Hello";
	//char msg5[] = "World";

	//for example making the first character a hash symbol
	//msg4[0] = '#';
	//Print(msg4);


	//This line gets a character that the user types and then stores it in the variable c
	//char c = _getch();
	//This prints the value of c which is the character the user inputed.
	//_putch(c);

	//This gets the users name and stores it in a buffer that can be up to 128 characters long
	//Print("Type your name: "); 
	//char inbuf[128];
	//Read(inbuf, 128);
	//Print("\nYour name is: ");
	//Print(inbuf);

	////This block of code gets the user to enter a number for the amount of hello messages they would like and then converts the string into a int and outputs that amount of hellos. 
	//Print("How many Hellos would you like? ");
	//char numBuffer[128];
	//Read(numBuffer, 128);
	//int num = StrToInt(numBuffer);
	//for (int i = 0; i < num; i++) {
	//	Print("Hello! ");
	//}


	Print("What number of Fibonacci sequence would you like? ");
	char numBuffer[128];
	Read(numBuffer, 128);
	int fibValue = Fibonacci(StrToInt(numBuffer));
	
	IntToStr(fibValue, numBuffer, 128);

	Print("\n");
	Print("Fibonacci value is: ");
	Print(numBuffer);



	//This line means the program will continue until the user hits a keyboard button
	while (!_kbhit());


	return 0;
}