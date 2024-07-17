#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

class Battleship{
    private:
    vector <int> board[5][5];
    int guesses;
    int maxgeusses;
    int locationx;
    int locationy;
    public:
    Battleship(int maxg){
        guesses=0;
        maxgeusses=maxg;
        srand(static_cast<unsigned int>(std::time(nullptr)));
        locationx=rand() % 5 + 0;
        locationy=rand() % 5 + 0;
    }
    bool guess(int x, int y){
        guesses++;
        if(x==locationx && y==locationy){
            cout << "you won in " << guesses << " guesses! \n";
            return true;
        }else if(x==locationx-1 || x==locationx+1){
            cout << "you missed ... you have " << 5-guesses << " guesses left.\n";
            cout << "you're on the same coulmn as battleship\n";
           // guesses++;
        }else if(y==locationy-1 || y==locationy+1){
            cout << "you missed ... you have " << 5-guesses << " guesses left.\n";
            cout << "you're on the same row as battleship\n";
          //  guesses++;
        }else if(x>5|| y>5){
            cout <<"your guess is out of bounds.\n";
            guesses--;
        }else {
            cout << "you missed ... you have " << 5-guesses << " guesses left.\n";
        }
        return false;
    }
    bool gameover(){
        if(guesses>=maxgeusses){
            cout << "GAME OVER!\n";
            return true;
        }else{
            return false;
        }
    }
    int getguesses(){
        return guesses;
    }
};

int main(){
    Battleship guessobj(5);
    int x,y,i=5,j=1;
    cout << "Welcome to Battleship!\n";
    cout << "you have 5 geusses to find the battleship hidden in a 5x5 grid.\n";
    while(guessobj.gameover()==false){
        cout << "Enter your guess (row & coloumn): ";
        cin >> x >> y;
        bool ret=guessobj.guess(x,y);
        if(ret==true){
            break;
        }
    }
    return 0;
}