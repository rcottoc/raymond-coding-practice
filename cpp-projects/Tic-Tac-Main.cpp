#include <iostream>
#include <cstdlib>
using namespace std;

char board[3][3] = { { '1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int player;
char marker;

void drawBoard();
bool placeMarker(int);
int checkWin();
void swapPlayer();
bool isFull();
int menu();

void pvp();
void pvc();
void rules();
void boardWipe();



int main() {
    while (true) {

        cout << "Welcome to Tic-Tac-Toe!\n";

        int choice = menu();

        if (choice == 1) pvp();
        else if (choice == 2) pvc();
        else if (choice == 3) rules();
        else if (choice == 0) {
            cout << "Thanks for playing!\n";
            return 0;
        }
        else cout << "Unknown input: " << choice << endl;
        system("sleep 3.5");
        system("clear");
        boardWipe();
    }

}


void drawBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--" << endl;
    }
}

bool placeMarker(int slot) {
    int row = slot / 3;
    int col = slot % 3;

    if (slot % 3 == 0) {
        row = (slot / 3) - 1;
        col = 2;
    }
    else {
        row = slot / 3;
        col = (slot % 3) - 1;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = marker;
        return true;
    }
    else {
        return false;
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        //rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return player;
        //columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return player;
    }
    //diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return player;

    return 0;
}

void swapPlayer() {
    if (marker == 'X') marker = 'O';
    else marker = 'X';

    if (player == 1) player = 2;
    else player = 1;
}

bool isFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

int menu() {
    int choice = 1;
    cout << "What would you like to do?\n\n"
        << "1) Player1 vs Player2\n"
        << "2) Player1 vs CPU\n"
        << "3) Rules\n"
        << "0) Exit\n\n>>> ";

    cin >> choice;
    return choice;
}

void pvp() {

    cout << "Player 1, choose your marker:\n\n\tX\t|\tO\n";
    cin >> marker;
    player = 1;
    drawBoard();
    int player_wins = 0;

    for (int i = 0; i < 9; i++) {

        cout << "It's player " << player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "That slot is invalid! Try another slot!\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "That slot is occupied! Try another slot!\n";
            i--;
            continue;
        }
        system("clear");
        drawBoard();

        player_wins = checkWin();

        if (player_wins == 1) {
            cout << "Player 1 won! Congratulations!\n";
            break;
        }
        if (player_wins == 2) {
            cout << "Player 2 won! Congratulations!\n";
            break;
        }

        swapPlayer();
    }
    if (player_wins == 0 && isFull()) {
        cout << "It's a tie game!\n";
    }
}

void pvc() {
    cout << "Player 1, choose your marker:\n\n\tX\t|\tO\n";
    cin >> marker;
    player = 1;
    drawBoard();
    int player_wins = 0;

    for (int i = 0; i < 9; i++) {

        if (player % 2) {
            cout << "It's your turn. Enter your slot: ";
            int slot;
            cin >> slot;


            if (slot < 1 || slot > 9) {
                cout << "That slot is invalid! Try another slot!\n";
                i--;
                continue;
            }

            if (!placeMarker(slot)) {
                cout << "That slot is occupied! Try another slot!\n";
                i--;
                continue;
            }
        }
        else {
            cout << "CPU choice was: ";
            int slot = rand() % 9 + 1;
            if (slot < 1 || slot > 9) {
                i--;
                continue;
            }

            if (!placeMarker(slot)) {
                i--;
                continue;
            }
            cout << slot << endl;
            system("sleep 2.5");
        }
        system("clear");
        drawBoard();


        player_wins = checkWin();

        if (player_wins == 1) {
            cout << "Player 1 won! Congratulations!\n";
            break;
        }
        if (player_wins == 2) {
            cout << "Player 2 won! Congratulations!\n";
            break;
        }

        swapPlayer();
    }
    if (player_wins == 0 && isFull()) {
        cout << "It's a tie game!\n";
    }
}



void rules() {
    cout << "The original capture the flag!\nEnter a number between 1-9 when prompted to place your marker\non the board at that position.\nFirst player to match three tiles wins! ";

}

void boardWipe() {
    for (int i = 1; i < 10; i++) {
        int row = i / 3;
        int col = i % 3;

        if (i % 3 == 0) {
            row = (i / 3) - 1;
            col = 2;
        }
        else {
            row = i / 3;
            col = (i % 3) - 1;
        }

        board[row][col] = '0' + i;

    }
}


