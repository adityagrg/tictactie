#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
char player = 'O', opponent = 'X';

void print(int place, char element);
void tictactoe(int place, char element);
bool isMovesLeft(char arr[9]);
int evaluate(char b[9]);
int minimax(char board[9], int depth, bool isMax);
int findBestMove(char board[9]);
char checkcondition();

	char arr[9];

int main()
{
	int place,first_turn;
	char element;
	cout<<"if you want to go second, input 2";
	cin>>first_turn;
	if(true)
	{
		if(first_turn == 2)
		{
			for(int i = 0 ; i < 4 ; i++)
			{
				place = findBestMove(arr)+1;
				element = 'O';
				tictactoe(place,element);
				element = 'X';
				cout<<"input place";
				cin>>place;
				tictactoe(place,element);
			}
			srand((int)time(0));
			place = (rand()%9+1);
			element = 'O';
			tictactoe(place,element);
		}
		else
		{
			for(int i = 0 ; i < 4 ; i++)
			{
				
				element = 'X';
				cout<<"input place";
				cin>>place;
				tictactoe(place,element);
				place = findBestMove(arr)+1;
				element = 'O';
				tictactoe(place,element);
			}
			
				element = 'X';
				cout<<"input place";
				cin>>place;
				tictactoe(place,element);
		}
	}
}
 
// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool isMovesLeft(char arr[9])
{
    for (int i = 0; i<9; i++)
        if(arr[i] == '\0')
        	return true;
    return false;
}
 
// This is the evaluation function as discussed
// in the previous article ( http://goo.gl/sJgv68 )
int evaluate(char b[9])
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row<9; row=row+3)
    {
        if (b[row+0]==b[row+1] &&
            b[row+1]==b[row+2])
        {
            if (b[row+0]==player)
                return +10;
            else if (b[row+0]==opponent)
                return -10;
        }
    }
 
    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0+col]==b[3+col] &&
            b[3+col]==b[6+col])
        {
            if (b[0+col]==player)
                return +10;
 
            else if (b[0+col]==opponent)
                return -10;
        }
    }
 
    // Checking for Diagonals for X or O victory.
    if (b[0]==b[4] && b[4]==b[8])
    {
        if (b[0]==player)
            return +10;
        else if (b[0]==opponent)
            return -10;
    }
 
    if (b[2]==b[4] && b[4]==b[6])
    {
        if (b[2]==player)
            return +10;
        else if (b[2]==opponent)
            return -10;
    }
 
    // Else if none of them have won then return 0
    return 0;
}
 
// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(char board[9], int depth, bool isMax)
{
    int score = evaluate(board);
 
    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;
 
    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;
 
    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board)==false)
        return 0;
 
    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;
 
        // Traverse all cells
        for (int i = 0; i<9; i++)
        {
                // Check if cell is empty
                if (board[i]=='\0')
                {
                    // Make the move
                    board[i] = player;
 
                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                        minimax(board, depth+1, !isMax) );
 
                    // Undo the move
                    board[i] = '\0';
                }
        }
        return best;
    }
 
    // If this minimizer's move
    else
    {
        int best = 1000;
 
        // Traverse all cells
        for (int i = 0; i<9; i++)
        {
                // Check if cell is empty
                if (board[i]=='\0')
                {
                    // Make the move
                    board[i] = opponent;
 
                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                           minimax(board, depth+1, !isMax));
 
                    // Undo the move
                    board[i] = '\0';
                }
        }
        return best;
    }
}
 
// This will return the best possible move for the player
int findBestMove(char board[9])
{
    int bestVal = -1000;
    int bestMove = -1;
 
    // Traverse all cells, evalutae minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<9; i++)
    {
            // Check if celll is empty
            if (board[i]=='\0')
            {
                // Make the move
                board[i] = player;
                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);
 
                // Undo the move
                board[i] = '\0';
 
                // If the value of the current move is
                // more than the best value, then update

                if (moveVal > bestVal)
                {
                    bestMove = i;
                    bestVal = moveVal;
                }
            }
    }
 
    return bestMove;
}


void print(int place, char element)
{
	cout<<arr[0]<<" | "<<arr[1] << " | "<< arr[2]<<endl;
	cout<<"---------"<<endl;
	cout<<arr[3]<<" | "<<arr[4] << " | "<< arr[5]<<endl;
	cout<<"---------"<<endl;
	cout<<arr[6]<<" | "<<arr[7] << " | "<< arr[8]<<endl<<endl;
	
	char ch = checkcondition();
	if(ch == 'c')
	{
		cout<<"computer wins";
		exit(0);
	}
	else if(ch=='h')
	{
		cout<<"human wins";
		exit(0);
	}
	
}

void tictactoe(int place, char element)
{
	while(arr[place-1] == 'X' || arr[place-1] == 'O')
	{
		if(place == 9)place = 1;
		else place = place+1;
	}
	arr[place-1] = element;
	print(place, element);
}

char checkcondition()
{
	for(int i = 0 ; i < 9 ; i=i+3)
	{
		if((arr[i]=='X'&&arr[i+1]=='X'&&arr[i+2]=='X'))
		{
			return 'h';
		}
		else if(arr[i]=='O'&&arr[i+1]=='O'&&arr[i+2]=='O')
			return 'c';
	}
	for(int i = 0 ; i < 9 ; i=i+1)
	{
		if((arr[i]=='X'&&arr[i+3]=='X'&&arr[i+6]=='X'))
			return 'h';
		else if(arr[i]=='O'&&arr[i+3]=='O'&&arr[i+6]=='O')
			return 'c';	
	}
	if((arr[0]=='X'&&arr[4]=='X'&&arr[8]=='X') || (arr[2]=='X'&&arr[4]=='X'&&arr[6]=='X'))
		return 'h';
	else if((arr[0]=='O'&&arr[4]=='O'&&arr[8]=='O') || (arr[2]=='O'&&arr[4]=='O'&&arr[6]=='O'))
		return'c';
	else return 0;
}
