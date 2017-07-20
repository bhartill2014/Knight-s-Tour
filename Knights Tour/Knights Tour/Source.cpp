#include <iostream>
#include <random>
#include <ctime>
#include <array>

using namespace std;
const int size = 8;

default_random_engine engine(static_cast<unsigned int> (time(0)));
uniform_int_distribution <unsigned int> randomInt(0, 7);

typedef struct possibleMoves {
	int currentRow = randomInt(engine); //the x coordinate on the board
	int currentColumn = randomInt(engine); //the y coordinate on the board
}possibleMoves;

array <int, 8 > horizontal = { 2, 1, -1, -2, -2, -1, 1, 2 };
array <int, 8 > vertical = { 1, 2, 2, 1, -1, -2, -2, -1 };
array <int, 8 > startHoriz = { 0, 1, 2, 3, 4, 5, 6, 7 };
array <int, 8 > startVert = { 0, 1, 2, 3, 4, 5, 6, 7 };

void printTour(int tour[size][size])
{
	int i;
	int j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			cout << tour[i][j] << "\t";
		}
		cout << endl;
	}
}

bool isMovePossible(possibleMoves nextMove, int tour[size][size])
{
	int i = nextMove.currentRow;
	int j = nextMove.currentColumn;

	if ((i >= 0 && i < size) && (j >= 0 && j < size) && (tour[i][j] == 0))
		return true;
	else
		return false;
}


// recursive function to find a knight tour
bool findTour(int tour[size][size], possibleMoves move_KT[], possibleMoves currentMove, int moveCount) {
	int i;
	possibleMoves nextMove;
	if (moveCount == size*size)
	{
		// Knight tour is completed  
		return true;
	}

	// try out the possible moves starting from the current coordinate
	for (i = 0; i < size; i++) {
		// get the next move
		nextMove.currentRow = currentMove.currentRow + move_KT[i].currentRow;
		nextMove.currentColumn = currentMove.currentColumn + move_KT[i].currentColumn;

		if (isMovePossible(nextMove, tour)) {
			// if the move is possible
			// increment the move count and store it in tour matrix
			tour[nextMove.currentRow][nextMove.currentColumn] = moveCount + 1;
			if (findTour(tour, move_KT, nextMove, moveCount + 1) == true)
			{
				return true;
			}
			else {
				// this move was invalid, try out other possiblities 
				tour[nextMove.currentRow][nextMove.currentColumn] = 0;
			}
		}
	}
	return false;
}
void knightTour()
{
	int tour[size][size];
	int i;
	int j;
	int currentRow;
	int currentColumn;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			tour[i][j] = 0;
		}
	}

	possibleMoves horizontal;
	possibleMoves vertical;
	possibleMoves startHoriz;
	possibleMoves startVert;

	array <int, 8, 8> startPoint;
	array <int, 8, 8> moveTable;

	if (findTour(tour, moveTable, startPoint, 0) == false)
	{
		cout << "\nThe tour ended with " << moveCount << "moves." << endl;
		cout << "\nThis was not a full tour";
		cout << "The voard for this test was:\n";
		printTour(tour);
	}
	else {
		cout << "";
		printTour(tour);
	}

}

int main()
{
	knightTour();
	cout << endl;
	return 0;
}