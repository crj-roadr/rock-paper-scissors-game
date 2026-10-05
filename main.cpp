#include <iostream>
#include <ctime>

int getUserChoice();
int getComputerChoice();
void showChoice(std::string player, std::string computer);
void chooseWinner(std::string player, std::string computer);

int main() {
    int userChoice = 0;
    int computerChoice = 0;

    std::string options[] = {"Rock", "Paper", "Scissors"};

    std::cout << "*** Rock Paper Scissors ***\n\n";
    std::cout << "1. Rock\n";
    std::cout << "2. Paper\n";
    std::cout << "3. Scissors\n";

    userChoice = getUserChoice();

    if (userChoice > 2 || userChoice < 0) {
        std::cerr << "Invalid choice. Please choose one of the following options: 1, 2, and 3.\n";
        return 1;
    }
    
    computerChoice = getComputerChoice();

    showChoice(options[userChoice], options[computerChoice]);
    chooseWinner(options[userChoice], options[computerChoice]);
    
    return 0;
}

int getUserChoice() {
    int choice = 0;
    std::cout << "Choose between the options in the menu above: ";
    std::cin >> choice;

    choice -= 1;
    
    return choice;
}

int getComputerChoice() {
    srand(time(NULL));
    int choice = rand() % 3;
    return choice;
}

void showChoice(std::string player, std::string computer) {
    std::cout << "You chose " << player << '\n';
    std::cout << "Computer chose " << computer << '\n';
}

void chooseWinner(std::string player, std::string computer) {
    if (player == "Rock" && computer == "Scissors" || player == "Paper" && computer == "Rock" || player == "Scissors" && computer == "Paper") {
        std::cout << "YOU WIN!\n";
    }
    else if (player == "Rock" && computer == "Paper" || player == "Paper" && computer == "Scissors" || player == "Scissors" && computer == "Rock") {
        std::cout << "YOU LOSE!\n";
    }
    else {
        std::cout << "IT IS A TIE!\n";
    }
}