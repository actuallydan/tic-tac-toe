#include <stdio.h>
#include <stdbool.h>

void printBoard(char board[3][3]);
bool checkIfWon(char board[3][3], char playerChar);

int main()
{

    bool hasWon = false;
    bool isPlayer1Turn = true;
    bool isInvalidMove = true;
    char player;
    char playerMark;

    int rowChoice;
    int colChoice;

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    // print initial board
    printBoard(board);

    // check if place has already been taken
    while (hasWon != true)
    {
        player = isPlayer1Turn ? '1' : '2';
        playerMark = isPlayer1Turn ? 'x' : 'o';

        // get user input
        while (isInvalidMove)
        {
            printf("Player %c, please enter a column: ", player);
            scanf("%d", &colChoice);

            printf("Player %c, please enter a row: ", player);
            scanf("%d", &rowChoice);

            if (board[rowChoice - 1][colChoice - 1] == ' ')
            {
                isInvalidMove = false;
            }
            else
            {
                printf("\nPlease choose another space.\n\n");
            }
        }

        // add to array
        board[rowChoice - 1][colChoice - 1] = playerMark;

        // print new board
        printBoard(board);

        hasWon = checkIfWon(board, playerMark);

        if (hasWon)
        {
            printf("Player %c wins!\n", player);
            break;
        }

        // change players
        isPlayer1Turn = !isPlayer1Turn;
        isInvalidMove = true;
    }
    return 0;
}

void printBoard(char board[3][3])
{
    printf("                        \n");
    printf("        1   2    3      \n");
    printf("    1   %c | %c | %c    \n", board[0][0], board[0][1], board[0][2]);
    printf("       -----------      \n");
    printf("    2   %c | %c | %c    \n", board[1][0], board[1][1], board[1][2]);
    printf("       -----------      \n");
    printf("    3   %c | %c | %c    \n", board[2][0], board[2][1], board[2][2]);
    printf("                        \n");
}

bool checkIfWon(char board[3][3], char playerChar)
{

    // check for diagonals
    if (board[0][0] == playerChar && board[1][1] == playerChar && board[2][2] == playerChar)
    {
        return true;
    }
    if (board[2][0] == playerChar && board[1][1] == playerChar && board[0][2] == playerChar)
    {
        return true;
    }

    // check for rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == playerChar && board[i][1] == playerChar && board[i][2] == playerChar)
        {
            return true;
        }
    }
    //check for cols
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == playerChar && board[1][i] == playerChar && board[2][i] == playerChar)
        {
            return true;
        }
    }
    return false;
}