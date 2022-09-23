#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void resetboard();
void printboard();
int checkfreespaces();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);

char board [3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';



int main()
{
    char winner=' ';
    char response=' ';
    do
    {
        winner=' ';
        response=' ';
        resetboard();
    while (winner == ' ' && checkfreespaces() != 0)
    {
        printboard();
        playermove();
        winner = checkwinner();
        if(winner != ' ' || checkfreespaces() == 0)
        {
            break;
        }
        computermove();
        winner = checkwinner();
        if (winner != ' ' || checkfreespaces() == 0)
        {
            break;
        }
    }
    printboard();
    printwinner(winner);
    printf("\nWould you like to play again?(Y/N):");
    scanf("%c");
    scanf("%c",&response);
    response= toupper(response);
    } while (response == 'Y');
    printf("Thanks For Playing!");
    return 0;
}


void resetboard()
{
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            board[i][j] = ' ';
        } 
    }
}


void printboard()
{
    printf(" %c | %c | %c", board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[2][0],board[2][1],board[2][2]);
    printf("\n");

}


int checkfreespaces()
{
    int freespaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freespaces--;
            }
        } 
    }
    return freespaces;
}


void playermove()
{
    int x;
    int y;
    do
    {
        printf("Enter row #(1-3):");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3):");
        scanf("%d", &y);
        y--;
        if(board[x][y] != ' ')
        {
            printf("Invalid Move");
        }
        else
        {
            board[x][y] = PLAYER;
            break;

        }
    } while (board[x][y] != ' ');
}


void computermove()
{
    srand(time(0));
    int x;
    int y;
    if(checkfreespaces() > 0)
    {
        do 
        {
            x = rand()%3;
            y = rand()%3;
        }
        while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else
    {
        printwinner(' ');
    }
    
}


char checkwinner()
{
    //rows
    for (int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //columns
    for (int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    //diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}


void printwinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("You Win!!");
    }
    else if (winner == COMPUTER)
    {
        printf("Computer Wins!!");
    }
    else
    {
        printf("Its Tie!");
    }

}
