#include <iostream>
using namespace std;

char board[3][3];
int turn = 0;

void initialize() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = '1' + i * 3 + j;
}

void display() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    for (int i = 0; i < 3; ++i)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool draw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}

int main() {
    initialize();
    while (true) {
        display();
        char current = turn % 2 == 0 ? 'X' : 'O';
        int move;
        cout << "Player " << current << ", enter your move (1-9): ";
        cin >> move;
        int r = (move - 1) / 3, c = (move - 1) % 3;
        if (board[r][c] != 'X' && board[r][c] != 'O') {
            board[r][c] = current;
            if (checkWin()) {
                display();
                cout << "Player " << current << " wins!\n";
                break;
            }
            if (draw()) {
                display();
                cout << "It's a draw!\n";
                break;
            }
            turn++;
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
    return 0;
}
