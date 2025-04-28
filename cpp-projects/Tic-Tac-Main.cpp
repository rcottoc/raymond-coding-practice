#include <iostream>
#include <cstdlib>
using namespace std;

char board[3][3] = { { '1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };              // board declaration
int player;                                                                            // player identifier... intended values will be player = 1 or player = 2
char marker;                                                                          // X or O marks the spot

void drawBoard();                                                                   // function prototypes 
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

        if (choice == 1) {
            pvp();
        }
        else if (choice == 2) {
            pvc();
        }
        else if (choice == 3) {
            rules();
        }
        else if (choice == 0) {
            cout << "Thanks for playing!\n";
            return 0;
        }
        else {
            cout << "Unknown input: " << choice << endl;
        }
        system("sleep 3.5");                                        // Note to self: Make small branch to allow Windows equivalent code... or, once and for all, figure out how to do these system commands from within C++
        system("clear");
        boardWipe();                                              // reset board function call
    }

}

void drawBoard() {                                              // nested for loops will draw rows and columns, displaying the "marker" at the board position
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "--|---|--" << endl;
        }
    }
}

bool placeMarker(int slot) {          // logic to assign marker to desired position, receives 
    int row = slot / 3;              // row = slot divided by 3 (slot argument should be int 1-9) will give desired row 1, 2, or 3
    int col = slot % 3;             // col = slot mod 3 (slot should be 1-9) will give desired column. 
                                   // Both values will be reset using the logic in the branch below, but I left these two lines to remember the time it took me to figure this out

    if (slot % 3 == 0) {          // Handle 3, 6, 9 user input
        row = (slot / 3) - 1;    // if (slot == 3) {row = 0;} else if (slot == 6) {row = 1;} else if (slot == 9) {row = 2;} 
        col = 2;                // I wanted to come up with a cool, showy expression but, given 3, 6, or 9, player wants column 2...
    }
    else {
        row = slot / 3;
        col = (slot % 3) - 1;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O') {     // Note to self: for the love of God, research what is the equivalent to Python's string.lower() in C++
        board[row][col] = marker;                              // if marker not already set by player, assign marker
        return true;
    }
    else {
        return false;
    }
}

int checkWin() {                                                                 // This function returns the current player if this turn resulted in a winning board state, so the function caller knows that guy's a real winner
    for (int i = 0; i < 3; i++) { 
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {        // check columns
            return player;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {     // check rows
            return player;
        }
    }
                                                                         // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return player;
    }

    return 0;
}

void swapPlayer() {
    if (marker == 'X') {             // if current marker is X then change to O
        marker = 'O';
    }
    else {
        marker = 'X';
    }

    if (player == 1) {             // if current player is 1, then change to player 2
        player = 2;
    }
    else {
        player = 1;             
    }
}

bool isFull() {              // return true if there's no room left for player markers on board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
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

void pvp() {                            // player versus player

    cout << "Player 1, choose your marker:\n\n\tX\t|\tO\n";
    cin >> marker;
    if ( marker == 'x' ) {            // fix capitalization, if the user chooses any other marker than X OR O lower or upper, then it's all doomed. TO be fixed... Soon™
        marker = 'X';                // This is because I was too in the zone (and lazy) to research C++ equivalent of string.lower() but I might come back to fix this in this lifetime, if not, my testament will place this burden on my survivors
    }
    else if ( marker == 'o' ) {
        marker = 'O';
    }
    
    player = 1;
    drawBoard();
    int player_wins = 0;

    for (int i = 0; i < 9; i++) {

        cout << "It's player " << player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "That slot is invalid! Try another slot!\n(Choose 1-9)";
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

        swapPlayer();                                 // if no player wins, then we swap players.
    }
    if (player_wins == 0 && isFull()) {             // if no player wins, AND board is full then t'was a tie
        cout << "It's a tie game!\n";
    }
}

void pvc() {                                      // player versus computer
    cout << "Player 1, choose your marker:\n\n\tX\t|\tO\n";
    cin >> marker;
     if ( marker == 'x' ) {            // fix capitalization; if the user chooses any other marker than X OR O lower or upper, then it's all doomed. TO be fixed... Soon™
        marker = 'X';
    }
    else if ( marker == 'o' ) {
        marker = 'O';
    }
    player = 1;
    drawBoard();
    int player_wins = 0;

    for (int i = 0; i < 9; i++) {             // repeat of pvp for player 1

        if (player % 2) {                    // check if player 1 turn
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
            
            srand(time(NULL));                  // seed random based on time of execution of this line
            int slot = rand() % 9 + 1;         // mod 9 random value so it's between 0 and 8, increment by 1 for desired slot values. 
            if (slot < 1 || slot > 9) {       // without announcing to player, try a different random value for CPU, this one was not valid.
                i--;
                continue;
            }

            if (!placeMarker(slot)) {      // without announcing to player, try a different random value for CPU, this one was not valid.
                i--;
                continue;
            }
            cout << "CPU choice was: ";
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
            cout << "Computer won! Bow to our new Overlords!\n";
            break;
        }

        swapPlayer();
    }
    if (player_wins == 0 && isFull()) {
        cout << "It's a tie game!\n";
    }
}



void rules() {             // This 
    cout << "The original capture the flag!\nEnter a number between 1-9 when prompted to place your marker\non the board at that position.\nFirst player to match three tiles wins! ";

}

void boardWipe() { // reset board to 1..9 for positional input from user after round ends
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


