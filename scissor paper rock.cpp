#include <iostream>
#include <ctime>
#include <cstdlib>

// Enum for game choices
enum class Choice { ROCK, PAPER, SCISSORS };

// Class for a game player
class Player {
public:
    virtual Choice getChoice() = 0;
};

// Class for a human player
class HumanPlayer : public Player {
public:
    Choice getChoice() override {
        int choice;
        std::cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                return Choice::ROCK;
            case 2:
                return Choice::PAPER;
            case 3:
                return Choice::SCISSORS;
            default:
                std::cerr << "Invalid choice. Defaulting to Rock." << std::endl;
                return Choice::ROCK;
        }
    }
};

// Class for a computer player
class ComputerPlayer : public Player {
public:
    Choice getChoice() override {
        // Generate a random choice
        int random = rand() % 3;
        switch (random) {
            case 0:
                return Choice::ROCK;
            case 1:
                return Choice::PAPER;
            case 2:
                return Choice::SCISSORS;
        }
    }
};

// Function to determine the winner
void determineWinner(Choice player1, Choice player2) {
    if (player1 == player2) {
        std::cout << "It's a tie!" << std::endl;
    } else {
        switch (player1) {
            case Choice::ROCK:
                if (player2 == Choice::SCISSORS) {
                    std::cout << "Rock crushes Scissors. Player 1 wins!" << std::endl;
                } else {
                    std::cout << "Paper covers Rock. Player 2 wins!" << std::endl;
                }
                break;
            case Choice::PAPER:
                if (player2 == Choice::ROCK) {
                    std::cout << "Paper covers Rock. Player 1 wins!" << std::endl;
                } else {
                    std::cout << "Scissors cuts Paper. Player 2 wins!" << std::endl;
                }
                break;
            case Choice::SCISSORS:
                if (player2 == Choice::PAPER) {
                    std::cout << "Scissors cuts Paper. Player 1 wins!" << std::endl;
                } else {
                    std::cout << "Rock crushes Scissors. Player 2 wins!" << std::endl;
                }
                break;
        }
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    HumanPlayer human;
    ComputerPlayer computer;

    char response;
    do {
        Choice humanChoice = human.getChoice();
        Choice computerChoice = computer.getChoice();

        std::cout << "Human chose: ";
        switch (humanChoice) {
            case Choice::ROCK:
                std::cout << "Rock" << std::endl;
                break;
            case Choice::PAPER:
                std::cout << "Paper" << std::endl;
                break;
            case Choice::SCISSORS:
                std::cout << "Scissors" << std::endl;
                break;
        }
        std::cout << "Computer chose: ";
        switch (computerChoice) {
            case Choice::ROCK:
                std::cout << "Rock" << std::endl;
                break;
            case Choice::PAPER:
                std::cout << "Paper" << std::endl;
                break;
            case Choice::SCISSORS:
                std::cout << "Scissors" << std::endl;
                break;
        }
        determineWinner(humanChoice, computerChoice);

        std::cout << "Play again? (y/n): ";
        std::cin >> response;
    } while (response == 'y');

    return 0;
}