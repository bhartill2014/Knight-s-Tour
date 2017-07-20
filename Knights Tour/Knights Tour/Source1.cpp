#include <iostream>
#include <random>
#include <ctime>
#include <array>

using namespace std;
const int n = 8;

default_random_engine engine(static_cast<unsigned int> (time(0)));
uniform_int_distribution <unsigned int> randomInt(0, 7);


typedef struct possibleMoves {
	int x; //the x coordinate on the board
	int y; //the y coordinate on the board
}possibleMoves;

void printTour(int tour[n][n]) {
	int i;
	int	j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << tour[i][j] << "\t";
		}
		cout << endl;
	}
}

bool isMovePossible(possibleMoves nextMove, int tour[n][n])
{
	int i = nextMove.x;
	int j = nextMove.y;

	if ((i >= 0 && i < n) && (j >= 0 && j < n) && (tour[i][j] == 0))
		return true;
	else
		return false;
}


// recursive function to find a knight tour
bool findTour(int tour[n][n], possibleMoves move_KT[], possibleMoves currentMove, int moveCount) {
	int i;
	possibleMoves nextMove;
	if (moveCount == n*n)
	{
		// Knight tour is completed  
		return true;
	}

	// try out the possible moves starting from the current coordinate
	for (i = 0; i < n; i++) {
		// get the next move
		nextMove.x = currentMove.x + move_KT[i].x;
		nextMove.y = currentMove.y + move_KT[i].y;

		if (isMovePossible(nextMove, tour)) {
			// if the move is possible
			// increment the move count and store it in tour matrix
			tour[nextMove.x][nextMove.y] = moveCount + 1;
			if (findTour(tour, move_KT, nextMove, moveCount + 1) == true)
			{
				return true;
			}
			else {
				// this move was invalid, try out other possiblities 
				tour[nextMove.x][nextMove.y] = 0;
			}
		}
	}
	return false;
}
void knightTour()
{
	int tour[n][n];
	int i,
		int	j;
	int currentRow = randomInt(engine);
	int currentColumn = randomInt(engine);
	// initializes the matrix
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			tour[i][j] = 0;
		}
	}

	possibleMoves moveTable[8] = { { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 },
	{ -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 } };

	// knight tour starts from random point
	possibleMoves startPoint = { currentRow, currentColumn };

	// find a possible knight tour using a recursive function
	if (findTour(tour, moveTable, startPoint, 0) == false)
	{
		cout << "\nThe tour ended with " << moveCount << "moves." << endl;
		cout << "\nThis was not a full tour";

	}
	else {
		cout << "\nTour exist ...\n";
		printTour(tour);
	}
}

// 
int main()
{
	cout << "The board for this test is:" << endl;
	knightTour();
	cout << endl;
	return 0;
}