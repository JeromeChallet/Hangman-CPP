#include <iostream>
#include <ctime>
#include <string>
#include <iterator>

using namespace std;

/*
1. the player is allowed 8 mistakes
2. the answer comes from a group of predefined random words
3. tell the player how many incorrect guesses he has left if done a mistake
4. constantly show the player the word he is guessing
5. tell the player the letter has already typed in it happens
6. give the option to play again or end the game at any time
*/

int main(){
    char guessLetter;

    cout << "Welcome to Hangman. Good Luck!\n";

    cout << "Enter your guess: ";
    cin >> guessLetter;

    return 0;
}