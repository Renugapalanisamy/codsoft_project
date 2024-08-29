#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    cout << "\n\t\t----------------Welcome to number guessing game--------------"<<endl;
    cout << "\n\t\t-------------->>You will have to guess a number between 1 to 100";
    cout << "\n\t\t-------------->>Let's start the game."<<endl;
    srand(time(0));
    int number = (rand() % 100) + 1;

    cout << "You have a total of 5 chances to guess the correct number.\n";
    int chance = 5;
    int guess;

    for(int i=1;i<=5;i++) {
        cout << "ENTER GUESS (1-100): ";
        cin >> guess;

        if (guess == number) {
            cout << "You won!" << endl;
            break;
        } else {
            if (guess > number)
            {
                cout << "Guess lower!" << endl;
            } else
            {
                cout << "Guess higher!" << endl;
            }
        }

        chance--;

        if (chance > 0) {
            cout << "You have " << chance << " chances left." << endl;
        } else {
            cout << "Sorry, your chances have run out. The correct number was: " << number << endl;
            cout << "Thanks for playing. Have a nice day!" << endl;
        }
    }

    return 0;
}
