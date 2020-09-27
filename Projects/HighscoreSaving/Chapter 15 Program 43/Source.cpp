#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ios>
#include<sstream>
#include <vector>
#include <limits>
#include <filesystem>


std::fstream& GotoLine(std::fstream& file, unsigned int num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}

int main() {
	int scores[10] = { 0 };
	std::string names[10];

	std::string menuInput;

	int userScore;


	int positionOfTab;
	std::string userName;

	//creates file
	std::fstream file("Scores.txt", std::fstream::out);


	for (auto & name : names) {
		name = "NO NAME\t";
	}

	for (const auto & name : names) {
		file << name;
	}
	file << std::endl;

	for (int score : scores) {
		file << score << "\t";
	}



	GotoLine(file, 1);
	std::string line1;
	std::getline(file, line1);


	std::istringstream iss(line1);
	std::string token;
	int i = 0;
	while (std::getline(iss, token, '\t')) {
		positionOfTab = token.find('\t');
		token.replace(positionOfTab, 1, " ");
		names[i] = token;
		i++;
	}

	GotoLine(file, 2);
	std::string line2;
	std::getline(file, line2);

	file.close();

	std::istringstream scoreStream(line2);
	std::string scoreToken;
	int j = 0;
	while (std::getline(scoreStream, scoreToken, '\t')) {
		scores[j] = stoi(scoreToken);
		j++;
	}


	do {
		//system("cls");
		std::cout << "HIGH SCORES" << std::endl;
		std::cout << "What would you like to do?\n1: Enter a score\n2: Display scores\n3: Exit\nPlease input you choice (1-3): ";
		std::cin >> menuInput;

		if (menuInput == "1") {
			std::cout << "Please enter a name for the score: ";
			std::cin >> userName;
			std::cout << "Please enter there score: ";
			std::cin >> userScore;

			if (scores[9] <= userScore) {
				scores[9] = userScore;
				names[9] = userName;

				for (int row = 0; row < 10; row++)
				{
					for (int col = 0; col < 10 - 1; col++)
					{
						if (scores[col] < scores[col + 1])
						{
							std::swap(names[col], names[col + 1]);
							std::swap(scores[col], scores[col + 1]);
						}
					}
				}

				std::fstream file("Scores.txt", std::fstream::out);
				for (const auto & name : names) {
					file << name << "\t";
				}
				file << std::endl;
				for (int score : scores) {
					file << score << "\t";
				}
			}
			else
			{
				break;
			}
		}
		else if (menuInput == "2") {
			if (names[0] == "NO NAME\t" && scores[0] == 0) {
				std::cout << "No scores found, returning to main menu" << std::endl;
			}
			else {
				std::cout << std::endl << "SCORES" << std::endl;
				int placement = 1;
				for (int i = 0; i < 10; i++) {
					std::cout << placement << ": " << names[i] << " |\tSCORED " << scores[i] << std::endl;
					placement++;
				}
			}
			
		}
		else if (menuInput == "3") {
			std::cout << "Thank you for using this program" << std::endl;
			file.close();
		}
		else {
			std::cout << "Invalid input. Please try again" << std::endl;
			system("pause");
		}
		std::cout << std::endl;
	} while (menuInput != "3");

}