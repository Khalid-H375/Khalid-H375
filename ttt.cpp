#include <iostream>
#include <vector>

using namespace std;



const char EMPTY = ' ';
const char choiceX = 'X';
const char choiceO = 'O';

char board[3][3] = {{EMPTY,EMPTY,EMPTY},{EMPTY,EMPTY,EMPTY},{EMPTY,EMPTY,EMPTY}};

void printboard();
bool checkwin(char player);
bool checkdraw();
bool isvalidmove(int row, int col);
void makemove(int row, int col, char player);


int main()
{
    char player = choiceX;
    int px,py;
    bool gamewon = false;

    while (!gamewon && !checkdraw())
    {
        printboard();
        cout << "Player " << player << " enter your move: " << endl;
        cin >> px >> py;

        if (isvalidmove(px, py))
        {
            makemove(px, py, player);

            if (checkwin(player))
            {
                printboard();
                cout << "Player " << player << " wins!" << endl;
                gamewon = true;
            }
            else
            {
                player = (player == choiceX) ? choiceO : choiceX;
            }
        }
        else 
        {
            cout << "Invalid move. Try again." << endl;
        }
    }    

    if (!gamewon)
    {
        printboard();
        cout << "It's a draw!" << endl;
    }

    return 0 ;
}
void printboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "-----" << endl;
    }
    cout << endl;
}

bool checkwin(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

bool checkdraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int  j = 0; j < 3; j++)
        {
            if(board[i][j] == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}


bool isvalidmove(int row, int col)
{
    return(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY);
}


void makemove(int row, int col, char player)
{
    board[row][col] = player;
}