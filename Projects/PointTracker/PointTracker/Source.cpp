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

class Database {
public:
	Database() {}
	Database(char* name, int points)
	{
		mName = name;
		mPoints = points;
	}

	char* GetName() { return mName; }
	int GetPoints() { return mPoints; }

	void SetName(char* name) { mName = name; }
	void SetPoints(int value) { mPoints = value; }

private:
	char* mName;
	int mPoints;

};

using namespace BasicString;

int main() {
	Database entries[10];

	int userChoice = 0;
	int currentEntry = 0;

	do {
		BasicString::Print("What would you like to do (1-5): ");
		BasicString::Print("1: Save a file\n2: Load a File\n3: Add Data to Current Set\n4: Print Current Data\n5: Exit\nPlease enter your input: ", false);

		char buffer[100];
		BasicString::Read(buffer, 2);
		BasicString::Print("");
		userChoice = BasicString::StrToInt(buffer);

		switch (userChoice) {
		case 0:
			BasicString::Print("Please enter valid input");
			break;
		case 1:
			BasicString::Print("Enter a filename: ", false);
			{

				BasicString::Read(buffer, 100);

				const char* fileName = buffer;
				std::ofstream outFile(fileName);


				for (auto& index : entries) {
					if (index.GetName() == "") break;

					outFile.put(*index.GetName());
					outFile.put(('\n'));
					outFile.put(index.GetPoints());
					outFile.put(('\n'));
				}
			}

			break;
		case 2:

			break;
		case 3:
			BasicString::Print("Enter the persons name: ", false);
			BasicString::Read(buffer, 10);
			entries[currentEntry].SetName(buffer);
			BasicString::Print("\nEnter the persons score: ");
			BasicString::Read(buffer, 3);
			entries[currentEntry].SetPoints(BasicString::StrToInt(buffer));
			
			currentEntry++;

			if (currentEntry >= 10) {
				BasicString::Print("Exceeding bar chart max size, will overwrite 1st element");
			}

			break;
		case 4:

			break;
		case 5:

			break;
		}

	} while (userChoice != 5);
}