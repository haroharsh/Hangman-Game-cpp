#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

#define MAX_ATTEMPTS 6
using namespace std;

class HangmanGame{
    public:
    void playGame(){
        bool playAgain = true;
        while(playAgain){
            cout<<"------------------------------------------------------"<<endl;
            cout<<"|                                                    |"<<endl;
            cout<<"|                 Welcome to Hangman                 |"<<endl;
            cout<<"|                                                    |"<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"Last player was found in this condition for failing to guess the word!"<<endl;
            cout << "            _____" << endl;
            cout << "           |     |" << endl;
            cout << "           |     O" << endl;
            cout << "           |    /|\\" << endl;
            cout << "           |    / \\" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;

            string categories[] = {"Cricketers", "Subjects", "Movies", "AI"};
            int n = sizeof(categories)/sizeof(categories[0]);
            
            cout <<"Choose a category to play : "<<endl;
            for(int i=0; i<n; i++){
                cout<< i+1 << ". " << categories[i] << endl;
            }
            
            int choice;
            cout<<"Enter your choice (1-"<<n<<"): ";
            cin >> choice;
            
            string cricketers[] = {"kohli", "dhoni", "dhawan", "rohit", "raina"};
            string subjects[]   = {"mathematics", "python", "cloud", "chemistry", "english"};
            string movies[]     = {"avengers", "flash", "avatar", "welcome", "dhamaal"};
            string ai[]         = {"machinelearning", "deeplearning", "neuralnetworks", "nlp", "robotics"};
            
            srand(time(0));
            string selectedWord;
            
            if(choice == 1){
                selectedWord = cricketers[rand() % 5];
            }
            else if(choice == 2){
                selectedWord = subjects[rand() % 5];
            }
            else if(choice == 3){
                selectedWord = movies[rand() % 5];
            }
            else if(choice == 4){
                selectedWord = ai[rand() % 5];
            }
            else{
                cout<<"Invalid choice! Please try Again"<<endl;
                return;
            }
            
            cout<<endl<<"A random " << categories[choice-1] << " is founded, Can you guess who it is??"<<endl;
            
            string guessedWord(selectedWord.size(), '_');
            int lives = MAX_ATTEMPTS;
            bool won = false;
            while(lives > 0 && !won){
                cout<<endl<<"Word: ";
                for(char c : guessedWord) cout<<c<<" ";
                cout<<endl<<"Lives remaining: "<<lives<<endl;
                char guess;
                cout<<"Enter a letter: ";
                cin >> guess;
                bool correct = false;
                for(size_t i=0; i<selectedWord.size(); i++){
                    if(selectedWord[i] == guess && guessedWord[i] == '_'){
                        guessedWord[i] = guess;
                        correct = true;
                    }
                }
                
                if(!correct){
                    lives--;
                    cout<<"Wrong guess!"<<endl;
                } else {
                    cout<<"Good guess!"<<endl;
                }
                
                if(guessedWord == selectedWord){
                    won = true;
                }
            }
            
            if(won){
                cout<<endl<<"Congratulations! You guessed the word: "<<selectedWord<<endl;
            } else {
                cout<<endl<<"OOPS!! Out of lives! The word was: "<<selectedWord<<endl;
                cout<<"You are hanged :) "<<endl;
                cout << "            _____" << endl;
                cout << "           |     |" << endl;
                cout << "           |     O" << endl;
                cout << "           |    /|\\" << endl;
                cout << "           |    / \\" << endl;
                cout << "           |" << endl;
                cout << "           |" << endl;
            }
            
            char option;
            cout<<endl<<"Do you want to play again? (y/n): ";
            cin >> option;
            if(option == 'y' || option == 'Y'){
                playAgain = true;
            } else {
                playAgain = false;
                cout<<endl<<"Thanks for playing Hangman! Goodbye!"<<endl;
            }
        }
    }
};

int main(){
    HangmanGame play;
    play.playGame();
    return 0;
}
