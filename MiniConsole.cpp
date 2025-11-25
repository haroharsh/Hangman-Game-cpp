#include <bits/stdc++.h>
using namespace std;
void clearInput(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int randInRange(int a, int b){
    return a + rand() % (b - a + 1);
}
class Hangman {
    const int MAX_LIVES = 6;
    vector<string> cricketers = {"kohli", "dhoni", "dhawan", "rohit", "raina"};
    vector<string> subjects   = {"mathematics", "python", "cloud", "chemistry", "english"};
    vector<string> movies     = {"avengers", "flash", "avatar", "welcome", "dhamaal"};
    vector<string> ai         = {"machinelearning", "deeplearning", "neuralnetworks", "nlp", "robotics"};
    vector<string> categories = {
        "Cricketers", "Subjects", "Movies", "AI", "Animals",
        "Countries","Fruits","Superheroes","Space"
    };
    vector<string> animals = {
    "tiger", "lion", "cheetah", "elephant", "giraffe",
    "kangaroo", "penguin", "dolphin", "rabbit", "zebra",
    "leopard", "hyena", "buffalo", "panda", "gorilla"
};
    vector<string> countries = {
    "india", "canada", "brazil", "argentina", "germany",
    "france", "japan", "china", "russia", "italy",
    "spain", "norway", "sweden", "finland", "egypt"
};
    vector<string> fruits = {
    "apple", "banana", "orange", "pineapple", "mango",
    "strawberry", "watermelon", "papaya", "kiwi", "grapes"
};
    vector<string> superheroes = {
    "superman", "batman", "ironman", "thor", "hulk",
    "spiderman", "deadpool", "flash", "vision", "aquaman"
};
    vector<string> space = {
    "galaxy", "nebula", "asteroid", "meteor", "comet",
    "supernova", "blackhole", "satellite", "cosmos", "orbit"
};


    void displayHangman(int lives){
        if(lives == MAX_LIVES){
            cout << "            _____" << endl;
            cout << "           |     " << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
        }
        else if(lives == (MAX_LIVES - 1)){
            cout << "            _____" << endl;
            cout << "           |     |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
        }
        else if(lives == (MAX_LIVES - 2)){
            cout << "            _____" << endl;
            cout << "           |     |" << endl;
            cout << "           |     O" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
        }
        else if(lives == (MAX_LIVES - 3)){
            cout << "            _____" << endl;
            cout << "           |     |" << endl;
            cout << "           |     O" << endl;
            cout << "           |     |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
        }
        else if(lives == (MAX_LIVES - 4)){
            cout << "            _____" << endl;
            cout << "           |     |" << endl;
            cout << "           |     O" << endl;
            cout << "           |    /|\\" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
        }
        else if(lives == (MAX_LIVES - 5)){
            cout << "            _____" << endl;
            cout << "           |     |" << endl;
            cout << "           |     O" << endl;
            cout << "           |    /|\\" << endl;
            cout << "           |     |" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
        }
        else {
            cout << "            _____" << endl;
            cout << "           |     |" << endl;
            cout << "           |     O" << endl;
            cout << "           |    /|\\" << endl;
            cout << "           |    / \\" << endl;
            cout << "           |" << endl;
            cout << "           |" << endl;
        }
    }

public:
    void play(){
        cout << "------ HANGMAN ------\n";
        for(size_t i=0;i<categories.size();++i){
            cout << i+1 << ". " << categories[i] << "\n";
        }
        cout << "Enter choice (1-" << categories.size() << "): ";

        int choice;
        if(!(cin >> choice) || choice < 1 || choice > (int)categories.size()){
            cout << "Invalid choice. Returning to menu.\n";
            clearInput();
            return;
        }

        clearInput();

        string selected;

        switch(choice){
            case 1: selected = cricketers[randInRange(0, cricketers.size()-1)]; 
            break;
            case 2: selected = subjects[randInRange(0, subjects.size()-1)]; 
            break;
            case 3: selected = movies[randInRange(0, movies.size()-1)]; 
            break;
            case 4: selected = ai[randInRange(0, ai.size()-1)];
            break;
            case 5: selected = animals[randInRange(0, animals.size()-1)];
            break;
            case 6: selected = countries[randInRange(0, countries.size()-1)];
            break;
            case 7: selected = fruits[randInRange(0, fruits.size()-1)];
            break;
            case 8: selected = superheroes[randInRange(0, superheroes.size()-1)];
            break;
            case 9: selected = space[randInRange(0, space.size()-1)];
            break;
        }

        string guessed(selected.size(), '_');
        int lives = MAX_LIVES;
        set<char> used;
        bool won = false;

        while(lives > 0 && !won){
            cout<<endl;
            cout << "Word: ";
            for(char c : guessed){
                cout << c << ' ';
            }
            cout<<endl;
            cout << "Lives: " << lives << endl<<"Used letters: ";
            for(char c : used){
                cout << c << ' ';
            }
            cout<<endl;
            cout << "Enter a letter: ";
            char g;
            cin >> g; clearInput();
            g = tolower(g);
            if(!isalpha(g)){
                cout << "Enter a letter.";
                cout<<endl;
                continue; 
            }
            if(used.count(g)){
                cout << "Already used.";
                cout<<endl;
                continue;
            }
            used.insert(g);

            bool correct = false;
            for(size_t i=0;i<selected.size();++i){
                if(selected[i]==g && guessed[i]=='_'){ 
                    guessed[i]=g; correct = true; 
                }
            }
            if(!correct){
                lives--;
                cout << "Wrong!"<<endl;
                displayHangman(lives); 
            }
            else cout << "Good!\n";

            if(guessed == selected) won = true;
        }
        if(won){
            cout << "\nYou won! Word: " << selected << "\n";
        }
        else { 
            cout << "\nYou lost. Word: " << selected << "\n"; 
            displayHangman(0); 
        }
    }
};
class TicTacToe {
    vector<char> board;
    void printBoard(){
        cout << "\n";
        for(int i=0;i<9;i++){
            cout << " " << (board[i]==' ' ? char('1'+i) : board[i]) << " ";
            if(i%3!=2) {
                cout << "|";
            }
            if(i%3==2 && i!=8) {
                cout << "\n---+---+---\n";
            }
        }
        cout << "\n\n";
    }
    char checkWinner(){
        int wins[8][3] = {
            {0,1,2},{3,4,5},{6,7,8},
            {0,3,6},{1,4,7},{2,5,8},
            {0,4,8},{2,4,6}
        };
        for(auto &w: wins){
            char a = board[w[0]], b = board[w[1]], c = board[w[2]];
            if(a!=' ' && a==b && b==c) return a;
        }
        return ' ';
    }
    int tryToFindWinningMove(char who){
        for(int i=0;i<9;i++){
            if(board[i]==' '){
                board[i] = who;
                if(checkWinner()==who){ board[i]=' '; return i; }
                board[i] = ' ';
            }
        }
        return -1;
    }
    void computerMove(char comp, char human){
        int mv = tryToFindWinningMove(comp);
        if(mv != -1){ 
            board[mv] = comp;
            return; 
        }
        mv = tryToFindWinningMove(human);
        if(mv != -1){ 
            board[mv] = comp;
            return; 
        }
        if(board[4]==' '){ 
            board[4]=comp; 
            return; 
        }
        vector<int> corners = {0,2,6,8};
        shuffle(corners.begin(), corners.end(), default_random_engine(rand()));
        for(int c: corners){
            if(board[c]==' ')
            { board[c]=comp; 
                return; 
            
            }}
        vector<int> avail;
        for(int i=0;i<9;i++){
            if(board[i]==' ') 
            {
                avail.push_back(i);
            }
        }
        if(!avail.empty()){
            board[avail[randInRange(0, avail.size()-1)]] = comp;
        }
    }

public:
    TicTacToe(){ 
        board.assign(9,' '); 
    }

    void play(){
        cout << "------ TIC-TAC-TOE ------\n1) Two Player\n2) vs Computer\nChoose mode: ";
        int mode;
        if(!(cin >> mode) || (mode!=1 && mode!=2)){ 
            cout << "Invalid. Returning.\n"; 
            clearInput(); 
            return; 
        }
        clearInput();

        board.assign(9,' ');
        char current = 'X', human='X', comp='O';
        if(mode==2){
            cout << "Play as X or O? (X goes first): ";
            char c; cin >> c; clearInput(); c = toupper(c);
            if(c=='O'){ human='O'; comp='X'; current='X'; } else { human='X'; comp='O'; current='X'; }
        }

        while(true){
            printBoard();
            if(mode==1 || (mode==2 && current==human)){
                int pos;
                cout << "Player " << current << ", choose (1-9): ";
                while(true){
                    if(!(cin >> pos) || pos < 1 || pos > 9 || board[pos-1] != ' '){
                        cout << "Invalid. Choose empty 1-9: "; clearInput(); continue;
                    }
                    clearInput();
                    break;
                }
                board[pos-1] = current;
            } else {
                cout << "Computer (" << current << ") moves...\n";
                computerMove(current, human);
            }

            char w = checkWinner();
            if(w != ' '){ 
                printBoard(); 
                cout << "Winner: " << w << "\n"; 
                break; 
            }
            if(find(board.begin(), board.end(), ' ') == board.end()){ 
                printBoard(); 
                cout << "Draw.\n"; 
                break; 
            }
            current = (current=='X'?'O':'X');
        }
    }
};
class NumberGuessing {
public:
    void play(){
        cout << "------ NUMBER GUESSING ------\nEnter lower bound (or 0 for default 1): ";

        int a; 
        if(!(cin >> a)){ 
            clearInput(); 
            a = 1; 
        }
        cout << "Enter upper bound (or 0 for default 100): ";

        int b; if(!(cin >> b)){ clearInput(); b = 100; }
        clearInput();

        if(a==0)
        {
            a = 1; 
            if(b==0){
                b = 100;
            }
        }
        if(a >= b){ 
            cout << "Invalid range. Using 1-100.\n"; 
            a=1; 
            b=100; 
        }

        int secret = randInRange(a,b);
        int tries = 0;
        cout << "I picked a number between " << a << " and " << b << ".\n";
        while(true){
            cout << "Your guess: ";
            int g;
            if(!(cin >> g)){ 
                cout << "Enter a number.\n"; 
                clearInput(); 
                continue; 
            }
            clearInput();
            tries++;
            if(g == secret){ 
                cout << "Correct in " << tries << " attempts!\n"; 
                break; 
            }
            else if(g < secret) {
                cout << "Too low.\n"; 
            }
            else {
                cout << "Too high.\n";
            }
        }
    }
};
class Toss {
public:
    void play(){
        cout << "------ COIN TOSS ------\nPick H for heads or T for tails: ";
        char c; 
        if(!(cin >> c)){ 
            clearInput(); 
            cout << "Invalid.\n"; 
            return; 
        }
        clearInput();
        c = toupper(c);
        if(c!='H' && c!='T'){ 
            cout << "Invalid choice.\n"; 
            return; 
        }
        int flip = randInRange(0,1);
        char res = (flip==0 ? 'H' : 'T');
        cout << (res=='H' ? "Heads!\n" : "Tails!\n");
        if(res==c){
            cout << "You guessed right!\n"; 
        }
        else {
            cout << "Wrong guess."<<endl;
        }
    }
};
class MiniGameConsole {
    Hangman hangman;
    TicTacToe ttt;
    NumberGuessing numberGame;
    Toss toss;

    void showMenu(){
        cout << "\n====== MINIGAME CONSOLE ======\n"
             << "1. Hangman\n"
             << "2. Tic-Tac-Toe\n"
             << "3. Number Guessing\n"
             << "4. Toss\n"
             << "5. Exit\n"
             << "Choose (1-5): ";
    }

public:
    void run(){
        srand(time(0));
        bool running = true;
        while(running){
            showMenu();
            int sel;
            if(!(cin >> sel)){ cout << "Enter a number 1-5.\n"; clearInput(); continue; }
            clearInput();
            switch(sel){
                case 1: hangman.play(); break;
                case 2: ttt.play(); break;
                case 3: numberGame.play(); break;
                case 4: toss.play(); break;
                case 5: running = false; cout << "Goodbye!\n"; break;
                default: cout << "Invalid.\n"; break;
            }
            if(running){
                cout << "\nPress Enter to return to menu..."; cin.get();
            }
        }
    }
};
int main(){
    MiniGameConsole console;
    console.run();
    return 0;
}
