//3 RULES OF C++:
// - No global variables
// - No strings
// - Include <iostream>, not stdio, and use new and delete instead of malloc and free

#include <iostream>

using namespace std;

int main() {
	char keepPlaying = 'y';
	while (keepPlaying == 'y') {
		srand(time(NULL));
		int secretNum = rand() % 100;
		int attempts = 0;
		int guess;

		while (true) {
			cout << "Guess my secret number from 0 to 100!\n> ";
			cin >> guess;

			if (guess < secretNum) {
				cout << "Rare. That number is too low.\n";
			} else if (guess > secretNum) {
				cout << "Burnt. That number is too high.\n";
			} else {
				break;
			}
		}
		cout << "WELL DONE! That number is my secret number!\n";
		cout << "Would you like to play again? (y/n)\n>";
		cin >> keepPlaying;
	}
	cout << "GOODBYE!";
}