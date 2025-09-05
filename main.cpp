/*
Tomas Carranza Echaniz
9/5/25
This program selects a random number from 0 to 100, and then the user has to guess the number until they
get it right. The program will guide the player, saying if the guess was too high or low. Once the correct
number has been guessed, the program will print a congratulation message and the amount of attempts it
took the user to guess correctly. The user can also choose to play again if they want.

3 RULES OF C++:
 - No global variables
 - No strings
 - Include <iostream>, not stdio, and use new and delete instead of malloc and free
*/

#include <iostream> //import necessary namespaces
using namespace std;

//helper function for clearing all inputted text
void CinIgnoreAll() {
	cin.clear(); //clears error flags
	cin.ignore(255, '\n'); //ignores all text up to the new line
}

//the main loop
int main() {
	//the program greets the user
	cout << "Salutations I am Randy the random number sage.\n\n";

	//the game loop (for playing again) will keep going until the user inputs 'n' at the end
	char keepPlaying = 'y';
	while (keepPlaying == 'y') {
		//seed the random number generator using the time
		srand(time(NULL));
		//rand selects a number from 0 to 2147483647, and then the modulus operator converts that to 0 to 100 (101 is excluded)
		int secretNum = rand() % 101;
		//how many attempts it took the user to guess the right number
		int attempts = 0;
		//the number that the user guesses
		int guess;

		//the loop continues until the player is no longer incorrect
		bool incorrect = true;
		while (incorrect) {
			//prompts the user to guess a number
			cout << "Guess my secret number from 0 to 100!\n> ";
			//gets an input from the player
			cin >> guess;

			//if the player entered the wrong type (not an int)
			if (!cin) {
				//reminds the player to guess integers only
				cout << "\nPlease guess only integers.\n";
			}
			else {
				//gives feedback based on how the user's guess compares to the secret number 
				if (guess < secretNum) {
					cout << "\nThat number is too low.\n";
				}
				else if (guess > secretNum) {
					cout << "\nThat number is too high.\n";
					//if the user guessed the right number, we falsify incorrect to break out of the loop
				}
				else {
					incorrect = false;
				}
				//increments the attempt counter since the user just guessed something
				attempts++;
			}
			//clears any faulty or extra inputs (entering a number followed by some text doesn't raise any errors)
			CinIgnoreAll();
		}
		//congratulation message
		cout << "\nWELL DONE! That number is my secret number.";
		cout << "\nIt took you " << attempts << " guess";
		//only prints "es" if there was more than one guess in order to be gramatically correct
		if (attempts > 1) {
			cout << "es";
		}
		cout << ".\n";

		//repeats the play again question until the user gives a valid response
		bool invalidResponse = true;
		while (invalidResponse) {
			cout << "Would you like to play again? (y/n)\n>";
			cin >> keepPlaying;
			//only y and n are valid responses, and if the user inputs n, the game loop will break due to its condition
			//technically, you can input any word as long as it starts with y or n
			if (keepPlaying == 'y' || keepPlaying == 'n') {
				invalidResponse = false;
				cout << "\n"; //used for formatting in case the user says yes
			}
			else { //error message
				cout << "\nPlease answer either y or n.\n";
			}
			//clears the input in case the user inputted more than 1 letter, so the game doesn't get confused and use the extra input when playing again
			CinIgnoreAll();
		}
	}
	//farewell message
	cout << "I bid thee farewell.";
}