#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("-----------\n");
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;
    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col;
    char player = 'X';
    int moveCount = 0;

    while (1) {
        clearScreen();
        printBoard(board);

        printf("Player %c's turn. Enter row (1-3) and column (1-3): ", player);
        scanf("%d %d", &row, &col);
        row--; col--;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = player;
        moveCount++;

        if (checkWin(board, player)) {
            clearScreen();
            printBoard(board);
            printf("Player %c wins!\n", player);
            break;
        }

        if (checkDraw(board)) {
            clearScreen();
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
