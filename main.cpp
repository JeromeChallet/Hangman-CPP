#include <iostream>
#include <ctime>
#include <string>
#include <iterator>
#include <vector>

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
    string userInput;
    string hint;
    string answer;
    bool winning = false;
    int numberOfguessesMade = 0;
    vector<char> vectorAnswer;
    vector<char>::iterator iteratorAnswer;

    srand(static_cast<unsigned int>(time(0)));
    string answersWithHintsArray[][2]={{"safari", "you go there to see animals"}, {"restaurant","you go there to eat"}, {"cinema","you get to see movies there"}, {"family","you're supposed to count on them"}, {"supermarket","you buy food there"}};
    const int nbOfAnswers = sizeof(answersWithHintsArray) / sizeof(answersWithHintsArray[0]);
    const int randomNumber = rand() % nbOfAnswers;
    answer = answersWithHintsArray[randomNumber][0];
    hint = answersWithHintsArray[randomNumber][1];
    const int answerSize = answer.size();

    cout << "answer size: " << answerSize << endl;
    cout << "answer: " << answer << endl;
    cout << "hint" << hint << endl;

    for (int i = answerSize; i < answerSize; ++i)
      {
      vectorAnswer.push_back(answer[i]);
          cout << vectorAnswer[i] <<endl;
    }

    cout << "Welcome to Hangman. Good Luck!\n";
    cout << "Enter quit to quit the game\n";


    do {
        cout << "Enter your guess: ";
        cin >> userInput;
    }while (userInput != "quit" || numberOfguessesMade > 7 || winning != true);

    cout << "thank you for playing";
    return 0;
}