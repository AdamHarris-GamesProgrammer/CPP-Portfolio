#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int playerScore = 0;
	int computerScore = 0;

	std::string playerMove;
	std::string computerMove;

	int computerMoveNumber;


	std::cout << "Welcome to Rock Paper Scissors" << std::endl;
	do 
	{
		bool bValid = false;
		do {
			std::cout << "Please enter one of the following\n" <<
				"- Rock\n- Paper\n- Scissors\nPlease choose: ";
			std::cin >> playerMove;
			
			for (int i = 0; i < playerMove.length(); i++) {
				if (playerMove[i] >= 97 && playerMove[i] <= 122) {
					playerMove[i] = playerMove[i] - 32;
				}
			}

			if (playerMove == "ROCK" || playerMove == "PAPER" || playerMove == "SCISSORS") {
				bValid = true;
			}
			else {
				bValid = false;
			}
		} while (!bValid);

		computerMoveNumber = rand() % 3;
		switch (computerMoveNumber)
		{
		case 0:
			computerMove = "ROCK";
			break;
		case 1:
			computerMove = "PAPER";
			break;
		case 2:
			computerMove = "SCISSORS";
			break;
		}

		std::cout << "Computer plays " << computerMove << std::endl;

		if (playerMove == computerMove)
		{
			std::cout << "You both draw" << std::endl;
		}
		else if (playerMove == "ROCK" && computerMove == "SCISSORS") {
			std::cout << "You win this round!" << std::endl;
			playerScore++;
		}
		else if (playerMove == "PAPER" && computerMove == "ROCK") {
			std::cout << "You win this round!" << std::endl;
			playerScore++;
		}
		else if(playerMove == "SCISSORS" && computerMove == "PAPER")
		{
			std::cout << "You win this round!" << std::endl;
			playerScore++;
		}
		else {
			std::cout << "Computer wins this round!" << std::endl;
			computerScore++;
		}

		std::cout << "You need " << 3 - playerScore << " to win" << std::endl;
		std::cout << "The computer needs " << 3 - computerScore << " to win" << std::endl;
		std::cout << "******************************************************" << std::endl;
	} while (playerScore != 3 && computerScore != 3);

	if (playerScore == 3) {
		std::cout << "Congratulations you won!" << std::endl;
	}
	else {
		std::cout << "You lost to a computer, better luck next time!" << std::endl;
	}

	std::cout << "Your Score: " << playerScore << std::endl;
	std::cout << "Computer Score: " << computerScore << std::endl;
}
