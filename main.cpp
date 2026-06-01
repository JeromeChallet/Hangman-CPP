#include <iostream>
#include <ctime>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cctype>

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
    char guess;
    int numberOfTries = 0;
    const int numberOfLives = 8;
    vector<char> vectorAnswer;
    vector<char> vectorEmptyAnswer;
    vector<char> vectorLettersTyped;
    vector<char>::iterator iteratorAnswer;
    vector<char>::iterator iteratorEmptyAnswer;
    vector<char>::iterator iteratorLettersTyped;
    srand(static_cast<unsigned int>(time(0)));
    string answersWithHintsArray[][2]={{"safari", "you go there to see animals"}, {"restaurant","you go there to eat"}, {"cinema","you get to see movies there"}, {"family","you're supposed to count on them"}, {"supermarket","you buy food there"}};
    const int nbOfAnswers = sizeof(answersWithHintsArray) / sizeof(answersWithHintsArray[0]);
    const int randomNumber = rand() % nbOfAnswers;
    answer = answersWithHintsArray[randomNumber][0];
    hint = answersWithHintsArray[randomNumber][1];
    const int answerSize = answer.size();
    int remainingLetters = answerSize;
    for (int i = 0; i < answerSize; ++i)
    {
      vectorEmptyAnswer.push_back('_');
      vectorAnswer.push_back(answer[i]);
    }

    cout << "Welcome to Hangman. Good Luck!\n";
    cout << "Enter quit to quit the game and hint to see the hint\n";
    
    do {
        cout << "\nYou have " << (numberOfLives-numberOfTries) << " guesses left";
        cout << "\nword so far: ";
        
        for (iteratorAnswer = vectorEmptyAnswer.begin();iteratorAnswer != vectorEmptyAnswer.end();++iteratorAnswer)
        {
               cout << *iteratorAnswer;
        }
        cout << endl << "\nEnter your guess: " << endl;
        cin >> userInput;
        if (userInput.size() == 1 && isalpha(static_cast<unsigned char>(userInput[0])))
        {
            guess = tolower(userInput[0]);
            iteratorAnswer = find(vectorAnswer.begin(), vectorAnswer.end(),guess);
            iteratorEmptyAnswer = find(vectorEmptyAnswer.begin(), vectorEmptyAnswer.end(),guess);
            iteratorLettersTyped = find(vectorLettersTyped.begin(), vectorLettersTyped.end(),guess);
            if(iteratorEmptyAnswer != vectorEmptyAnswer.end())
            {
                cout << "\nYou have already guessed: " << guess;
            }  
            else if(iteratorLettersTyped != vectorLettersTyped.end() && iteratorEmptyAnswer == vectorEmptyAnswer.end())
            {
                cout << "\nYou have already typed: " << guess;
            } 
            else if (iteratorAnswer != vectorAnswer.end())
            {
                for (int i = 0; i < answerSize; ++i)
                {   
                    if (guess == answer[i])
                    {
                        vectorEmptyAnswer[i] = answer[i];
                        --remainingLetters;
                    }
                }  
            }         
            else
            {
                ++numberOfTries;
                vectorLettersTyped.push_back(guess);
            }
        }
        else if (userInput == "hint")
        {
            cout << hint;
        }
        else
        {
            ++numberOfTries;
            cout << "Please type a valid input";
        }
    }while ((userInput != "quit") && (numberOfTries < numberOfLives) && (remainingLetters > 0));

    if(remainingLetters == 0)
    {
        cout << "\nWell done the word was indeed: " << answer;
    }
    else
    {
        cout << "GAME OVER";
    }
    
    cout << "\nThank you for playing";
    return 0;
}