#include <iostream>

#include <cstdlib> 

#include <ctime>   

const int Rock = 1;
const int Paper = 2;
const int Scissors = 3;

int getUserChoice();
int getComputerChoice();
void determineWinner(int userChoice, int compChoice);
void displayChoice(int choice);

int main() {
    srand(time(0)); // Random number generation

    int userChoice, compChoice;

    do {
        userChoice = getUserChoice();
        if (userChoice == 4) {
            std::cout << "bye!" << std::endl;
            break;
        }

        compChoice = getComputerChoice();

        std::cout << "\nYou selected: ";
        displayChoice(userChoice);

        std::cout << "The computer selected: ";
        displayChoice(compChoice);

        determineWinner(userChoice, compChoice);

        std::cout << "\nGame Menu\n---------\n1) Rock\n2) Paper\n3) Scissors\n4) Quit\nEnter your choice: ";
    } while (true);

    return 0;
}

int getUserChoice() {
    int choice;
    std::cout << "\nGame Menu\n---------\n1) Rock\n2) Paper\n3) Scissors\n4) Quit\nEnter your choice: ";
    std::cin >> choice;

    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        return getUserChoice();
    }

    return choice;
}

int getComputerChoice() {
    return rand() % 3 + 1; // Generate a random number between 1 and 3
}

void determineWinner(int userChoice, int compChoice) {
    if (userChoice == compChoice) {
        std::cout << "It is a tie!\n";
    } else if (
        (userChoice == Rock && compChoice == Scissors) ||
        (userChoice == Scissors && compChoice == Paper) ||
        (userChoice == Paper && compChoice == Rock)
    ) {
        std::cout << "Congratulations you win! ";
    } else {
        std::cout << "Computer win! ";
    }

    if (userChoice == Rock && compChoice == Scissors) {
        std::cout << "Rock smashes scissors.\n";
    } else if (userChoice == Scissors && compChoice == Paper) {
        std::cout << "Scissors cuts paper.\n";
    } else if (userChoice == Paper && compChoice == Rock) {
        std::cout << "Paper wraps rock.\n";
    } else if (userChoice == Scissors && compChoice == Rock) {
        std::cout << "Rock smashes scissors.\n";
    } else if (userChoice == Paper && compChoice == Scissors) {
        std::cout << "Scissors cuts paper.\n";
    } else if (userChoice == Rock && compChoice == Paper) {
        std::cout << "Paper wraps rock.\n";
    }
}

void displayChoice(int choice) {
    switch (choice) {
        case Rock:
            std::cout << "Rock\n";
            break;
        case Paper:
            std::cout << "Paper\n";
            break;
        case Scissors:
            std::cout << "Scissors\n";
            break;
        default:
            std::cout << "Invalid choice\n";
            break;
    }
}

