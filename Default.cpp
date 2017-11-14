/*
Jajuan Monroe
Hangman Game
November 2017
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

const int MAX_TRIES=5;
int showLetter (char, string, string&);

int main ()
{
	string name;
	char letter;
	int wrong=0;
	string word;

	string planets[] = {

		"mercury",
		"venus",
		"earth",
		"mars",
		"saturn",
		"jupiter",
		"neptune",
		"uranus"
	};

	//the computer will choose a random word from the array and copy it to word.
	//srand(time(NULL)) is used to prevent sequence repetition between runs of the program.

	srand(time(NULL));
	int randomNum=rand()% 8;
	word=planets[randomNum];
    
	//shows * for each letter of the chosen word 
	string secretWord(word.length(),'*');

	cout<<"\n\nWelcome to Hangman!";
	cout<<"\nThe object of the game is to guess the word the hidden word. Each letter is represented by a star.";
	cout<<"\n\nYou have "<<MAX_TRIES<<" tries to try and guess the word. Only enter one letter at a time.";
	cout<<"\n\nAs a hint, it's a planet";
	cout<<"\n\n----------------------------------------------------------------";

	//Loop until the user runs out of guesses

	while (wrong<MAX_TRIES){

		cout<<"\n\n"<<secretWord;
		cout<<"\n\nGuess a letter:\t";
		cin>>letter;

		//If the guess is correct, fill the letter in the appropriate place(s). Otherwise incriment wrong.

		if (showLetter(letter, word, secretWord) == 0){

			cout<<endl<<"Incorrect!. Try again."<<endl;
			wrong++;
		}else{

			cout<<endl<<"Correct! Keep going!"<<endl;
		}

		//Inform the user on how many more guesses they have left.

		cout<<"You have "<<MAX_TRIES - wrong<<" guesses left."<<endl;

		//Check to see if the word was guessed correctly.
		if (word==secretWord){

			cout<<"\n"<<word<<endl;
			cout<<"\nWhoop Whoop! You got it!";
			break;
		}
	}
	if(wrong == MAX_TRIES){

		cout<<"\nSo close yet so far away. You lose and now you have to be hanged."<<endl;
		cout<<"The word was : "<<word<<endl;
		cout<<"Press enter to close"<<endl;
	}

	cin.ignore();
	cin.get();
	return 0;
}

//Function to check if the guess matches a letter in the word. Returns 0 if the letter was already guessed or if the letter has a match in the secret word

int showLetter(char guess, string secretword, string &guessword){

	int matches=0;
	int len=secretword.length();

	for (int i=0; i<len; i++){

		if(guess == guessword[i]){

			return 0;
		} else if(guess == secretword[i]){

			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}