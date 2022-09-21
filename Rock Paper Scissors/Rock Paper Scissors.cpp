#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main() {

	int auxOption, userOption, pcOption;
	bool isGameStart = true, isOptionSelect;
	string options[3] = { "Scissors", "Paper", "Rock" };

	do {

		srand(time(NULL));
		pcOption = rand() % 3;

		cout << "-- GAME STARTED --\n\n";
		cout << "Chosee a option:\n\nScissors -> Type 1\nPaper -> Type 2\nRock -> Type 3\n\n";

		isOptionSelect = false;

		while (!isOptionSelect) {
			if (!(cin >> auxOption)) {
				cin.clear();
				cin.ignore();
				cout << "\nEnter a valid option\n\n";
			}
			else {
				if (1 > auxOption || auxOption > 3) {
					cout << "\nEnter a valid option\n\n";
				}
				else {
					userOption = --auxOption;
					isOptionSelect = true;
				}
			}
		}

		cout << "\nYou chose: " << options[userOption];
		cout << "\nThe PC chose: " << options[pcOption];

		if (userOption == pcOption) {
			cout << "\n\nTIE!";
		}
		else {
			switch (userOption + pcOption) {
			case 1:
				cout << "\n\nScissors wins against paper";
				(options[userOption] == "Scissors") ? cout << "\n\nYOU WIN!" : cout << "\n\nYOU LOSE!";
				break;
			case 2:
				cout << "\n\nRock wins against scissors";
				(options[userOption] == "Rock") ? cout << "\n\nYOU WIN!" : cout << "\n\nYOU LOSE!";
				break;
			case 3:
				cout << "\n\nPaper wins against rock";
				(options[userOption] == "Paper") ? cout << "\n\nYOU WIN!" : cout << "\n\nYOU LOSE!";
				break;
			}
		}

		cout << "\n\nPlay a new game?\n\nYes -> Type 0\nNo -> Type 1\n\n";

		isOptionSelect = false;

		while (!isOptionSelect) {
			if (!(cin >> auxOption)) {
				cin.clear();
				cin.ignore();
				cout << "\nEnter a valid option\n\n";
			}
			else {
				if (0 > auxOption || auxOption > 1) {
					cout << "\nEnter a valid option\n\n";
				}
				else {
					(auxOption == 0) ? isGameStart : isGameStart = false;
					isOptionSelect = true;
					cout << "\n";
				}
			}
		}

	} while (isGameStart);

	cout << "-- FINISHED GAME --\n\n";
}
