#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
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
        cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
        cin >> choice;
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
        cout << "It's a tie!" << endl;
    } else {
        switch (player1) {
            case Choice::ROCK:
                if (player2 == Choice::SCISSORS) {
                    cout << "Rock crushes Scissors. Player 1 wins!" << endl;
                } else {
                    cout << "Paper covers Rock. Player 2 wins!" << endl;
                }
                break;
            case Choice::PAPER:
                if (player2 == Choice::ROCK) {
                    cout << "Paper covers Rock. Player 1 wins!" << endl;
                } else {
                    cout << "Scissors cuts Paper. Player 2 wins!" << endl;
                }
                break;
            case Choice::SCISSORS:
                if (player2 == Choice::PAPER) {
                    cout << "Scissors cuts Paper. Player 1 wins!" << endl;
                } else {
                    cout << "Rock crushes Scissors. Player 2 wins!" << endl;
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

        cout << "Human chose: ";
        switch (humanChoice) {
            case Choice::ROCK:
                cout << "Rock" << endl;
                break;
            case Choice::PAPER:
                cout << "Paper" << endl;
                break;
            case Choice::SCISSORS:
                cout << "Scissors" << std::endl;
                break;
        }
        std::cout << "Computer chose: ";
        switch (computerChoice) {
            case Choice::ROCK:
                cout << "Rock" << endl;
                break;
            case Choice::PAPER:
                cout << "Paper" <<endl;
                break;
            case Choice::SCISSORS:
                cout << "Scissors" <<endl;
                break;
        }
        determineWinner(humanChoice, computerChoice);

        cout << "Play again? (y/n): ";
        cin >> response;
    } while (response == 'y');

    return 0;
}