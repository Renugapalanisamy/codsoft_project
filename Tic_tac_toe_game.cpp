#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to print the game board
void print_board(const vector<char>& board) {
    cout << "-------------" << endl;
    cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " | " << endl;
    cout << "-------------" << endl;
    cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " | " << endl;
    cout << "-------------" << endl;
    cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " | " << endl;
    cout << "-------------" << endl;
}

// Function to check if a player has won
bool check_win(const vector<char>& board, char player) {
    return ((board[0] == player && board[1] == player && board[2] == player) ||
            (board[3] == player && board[4] == player && board[5] == player) ||
            (board[6] == player && board[7] == player && board[8] == player) ||
            (board[0] == player && board[3] == player && board[6] == player) ||
            (board[1] == player && board[4] == player && board[7] == player) ||
            (board[2] == player && board[5] == player && board[8] == player) ||
            (board[0] == player && board[4] == player && board[8] == player) ||
            (board[2] == player && board[4] == player && board[6] == player));
}

// Function to check if the game is a tie
bool check_tie(const vector<char>& board) {
    for (char square : board) {
        if (square == ' ') {
            return false;
        }
    }
    return true;
}

// Function to generate a random move for the computer
int computer_move(const vector<char>& board) {
    vector<int> empty_positions;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            empty_positions.push_back(i);
        }
    }
    srand(static_cast<unsigned int>(time(0)));
    return empty_positions[rand() % empty_positions.size()];
}

// Main game loop
void tic_tac_toe() {
    vector<char> board(9, ' ');
    char player = 'X';

    print_board(board);

    while (true) {
        int move;
        if (player == 'X') {
            cout << "It's " << player << "'s turn. Enter a position (1-9): ";
            cin >> move;
            move--;  // Convert to 0-based index
        } else {
            move = computer_move(board);
            cout << "Computer chose position: " << move + 1 << endl;
        }

        if (board[move] == ' ') {
            board[move] = player;
            print_board(board);

            if (check_win(board, player)) {
                cout << "Congratulations! Player " << player << " wins!" << endl;
                break;
            } else if (check_tie(board)) {
                cout << "It's a tie!" << endl;
                break;
            } else {
                player = (player == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "That position is already taken. Try again." << endl;
        }
    }
}

int main() {
    tic_tac_toe();
    return 0;
}
