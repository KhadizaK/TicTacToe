#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

string player1;
string player2;

void waysToWin() {

    char a1 = '_', a2 = '_', a3 = '_', b1 = '_', b2 = '_', b3 = '_', c1 = '_', c2 = '_', c3 = '_';


    printf("      1        2         3 \n");
    printf("a ___%c___|___%c___|___%c___\n", a1, a2, a3);
    printf("b ___%c___|___%c___|___%c___\n", b1, b2, b3);
    printf("c    %c   |   %c   |   %c   \n", c1, c2, c3);


    

    return;
}

bool randomStart(bool compor2, bool& playerOne, bool& playerTwo, bool& Computer) {
    
    srand((unsigned) time(NULL));

    if (compor2) {
        int random = rand();
        if (random % 2 == 0) {
            printf("\nplayer 1 goes first\n");
            playerOne = true;
            return true;
        } else {
            printf("\ncomputer goes first\n");
            Computer = true;
            return false;
        }
    } else {
        int random2 = rand();
        if (random2 % 2 == 0) {
            printf("\nplayer 1 goes first\n");
            playerOne = true;
            return true;
        } else {
            printf("\nplayer 2 goes first\n");
            playerTwo = true; //ideally I could make it so that there is need for only two additional bools, so there would be\
            bool playerOne and bool PlayertoworComp, so depending on which function it called it would mean different things.
            return false;
        }
    }
}

// PLAYER VERSUS COMPUTER

void playerVsComp() {
    ///something
    bool playerOne = false;
    bool Computer = false;
    bool playertow = false;
    char play1, Comp;

    // asks for the player name
    printf("What's your name player 1?\n");
    cin >> player1;

    //randomized start
    bool compor2 = true;
    randomStart(compor2, playerOne, playertow,Computer);

    //who goes first chooses X or O
    if (playerOne) {
        cout << '\n' << player1;
        printf(" choose X or O\n");
        cin >> play1;
        if (play1 == 'X' || play1 == 'x') {
            Comp = 'O';
            cout << '\n' << "computer " << Comp << endl;
        } else if (play1 == 'O' || play1 == 'o') {
            Comp = 'X';
            cout << '\n' << "computer " << Comp << endl;
        } else {
            return;
        }
    } else if (Computer) {
        Comp = 'O';
        cout << "computer " << Comp << endl;
        play1 = 'X';
        cout << '\n' << player1 << ' ' << play1 << endl;
        
    }
}

// PLAYER VERSUS PLAYER

void playerVsPlayer(string& player1, string& player2) {
    //all variables
    bool playerOne = false, playerTwo = false, computer = false;
    char play1, play2;

    // asks for the players name
    printf("What's your name player 1?\n");
    cin >> player1;
    printf("\nWhat's your name player 2?\n\n");
    cin >> player2;

    //randomized start
    bool compor2 = false;
    randomStart(compor2, playerOne, playerTwo, computer);

    //who goes first gets to choose X or O
    if (playerOne) {
        cout << '\n' << player1;
        printf(" choose X or O\n\n");
        cin >> play1;
        if (play1 == 'X' || play1 == 'x') {
            play2 = 'O';
            cout << '\n' << player2 << ' ' << play2 << endl;
        } else if (play1 == 'O' || play1 == 'o') {
            play2 = 'X';
            cout << '\n' << player2 << ' ' << play2 << endl;
        } else {
            return;
        }
    } else if (playerTwo) {
        cout << '\n' << player2;
        printf(" choose X or O\n\n");
        cin >> play2;
        if (play2 == 'X' || play2 == 'x') {
            play1 = 'O';
            cout << '\n' << player1 << ' ' << play1 << endl;
        } else if (play2 == 'O' || play2 == 'o') {
            play1 = 'X';
            cout << '\n' << player1 << ' ' << play1 << endl;
        } else {
            return;
        }
    }

}

int main() {

    waysToWin();
    return 0;

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Choose \na. single player \nb. double players\n");
    char modeChoice;
    cin >> modeChoice;
    if (modeChoice == 'a') {
        //calls a function that does player vs computer
        playerVsComp();
    } else if (modeChoice == 'b') {
        //calls a function that does player vs player
        playerVsPlayer(player1, player2);
    } else {
        printf("chose either a or b");
        return 0;
    }


}