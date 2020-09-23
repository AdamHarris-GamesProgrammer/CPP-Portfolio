#include <conio.h>
#include <fstream>

namespace BasicString {
	//This function prints a line break as a shorthand to writing one myself
	void PrintBreak() {
		_putch('\n');
	}

	void PrintFixed(const char* message, int width, bool lineBreak = true) {
		int n = 0;

		//This loop uses pointer arithmetic to get the next value of the message array
		for (; *message != 0; message++) { //0 in ASCII is NULL making it the ideal character for termination
			_putch(*message);
			n++;
		}

		for (; n < width; n++)
		{
			_putch(' ');
		}

		if (lineBreak) PrintBreak();
	}

	//This function prints a message based on a array of chars
	void Print(const char* message, bool lineBreak = true)
	{
		//This loop uses pointer arithmetic to get the next value of the message array
		for (; *message != 0; message++) { //0 in ASCII is NULL making it the ideal character for termination
			_putch(*message);
		}

		if (lineBreak) PrintBreak();
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

	void StrCopy(const char* pSrc, char* pDst, int maxBufferSize) {
		int n = 0;
		for (; *pSrc != 0 && (n + 1 < maxBufferSize); pSrc++, pDst++, n++)
		{
			*pDst = *pSrc;
		}
		//Adds the null terminator on the end
		*pDst = 0;
	}
}

class Database {
private:
	class Entry {
		public:
			Entry() = default;
			Entry(const char* name, int value) : value(value) {
				BasicString::StrCopy(name, this->name, sizeof(this->name));
			}

			void Print() {
				//formats the names nicely
				BasicString::PrintFixed(name, nameBufferSize ,false);

				//prints a separator
				BasicString::Print("|", false);
				for (int n = 0; n < value; n++)
				{
					//prints a equal sign for every point a person has
					BasicString::Print("=", false);
				}
				//line break
				BasicString::PrintBreak();
			}

			void SerializeData(std::ofstream& out) {
				//writes the name to the file
				out.write(name, sizeof(name));
				//writes the points a char to the file
				out.write(reinterpret_cast<const char*>(&value), sizeof(value));
			}
			void DeserializeData(std::ifstream& in) {
				in.read(name, sizeof(name));
				in.read(reinterpret_cast<char*>(&value), sizeof(value));
			}

		private:
			//gives 11 bytes of memory to each name, allowing for a max name size of 10 characters with a null terminator byte at the end
			static constexpr int nameBufferSize = 11;

			//array of chars for the name
			char name[nameBufferSize];

			//The points that a person has
			int value;
	};

public:
	void AddEntry(const char* name, int points) {
		if (currentEntry < maxNumberEntries) {
			//Creates a new entry object with the name and point values defined 
			entries[currentEntry++] = { name, points };
		}
		else
		{
			BasicString::Print("Exceeding maximum amount of entries in database");
		}
	}
	void SaveData(const char* fileName) {
		//creates a output file stream in binary mode
		std::ofstream outFile(fileName, std::ios::binary);

		//writes the current entry to the file as a const char*
		outFile.write(reinterpret_cast<const char*>(&currentEntry), sizeof(currentEntry));
		for (int i = 0; i < currentEntry; i++)
		{
			//serializes the data for each entry
			entries[i].SerializeData(outFile);
		}
		
	}
	void LoadData(const char* fileName) {
		std::ifstream inFile(fileName, std::ios::binary);
		//reads the data from the infile and reinterprets it as a char pointer 
		inFile.read(reinterpret_cast<char*>(&currentEntry), sizeof(currentEntry));
		for (int i = 0; i < currentEntry; i++)
		{
			//deserializes the data for each entry
			entries[i].DeserializeData(inFile);
		}
	}

	void DisplayData() {
		for (int i = 0; i < currentEntry; i++) {
			entries[i].Print();
		}
	}

private:
	//Allows a maximum of 16 entries in the database

	//A static constexpr means that all Database objects will share the same maxNumberEntries value and it will not change after compilation
	static constexpr int maxNumberEntries = 16;
	Entry entries[maxNumberEntries];
	int currentEntry = 0;

};

using namespace BasicString;

int main() {
	Database data;

	int userChoice = 0;

	do {
		BasicString::Print("What would you like to do (1-5): ");
		BasicString::Print("1: Save a file\n2: Load a File\n3: Add Data to Current Set\n4: Print Current Data\n5: Exit\nPlease enter your input: ", false);

		char buffer[256];
		char buffer2[256];
		BasicString::Read(buffer, 2);
		BasicString::Print("");
		userChoice = BasicString::StrToInt(buffer);

		if (userChoice == 0) {
			BasicString::Print("Please enter valid input");
		}
		else if (userChoice == 1) {
			BasicString::Print("Enter a filename: ", false);
			BasicString::Read(buffer, sizeof(buffer));
			
			BasicString::PrintBreak();

			data.SaveData(buffer);
		}
		else if (userChoice == 2) {
			BasicString::Print("Enter a filename: ", false);
			BasicString::Read(buffer, sizeof(buffer));
			
			BasicString::PrintBreak();

			data.LoadData(buffer);
		}
		else if (userChoice == 3) {
			BasicString::Print("Enter the persons name: ", false);
			BasicString::Read(buffer, 11);

			BasicString::Print("\nEnter the persons score: ", false);
			BasicString::Read(buffer2, 12);
		
			BasicString::PrintBreak();

			data.AddEntry(buffer, BasicString::StrToInt(buffer2));
		}
		else if (userChoice == 4) {
			data.DisplayData();
		}
		else if (userChoice == 5) {
			BasicString::Print("Goodbye.");
		}
	} while (userChoice != 5);

	return 0;
}