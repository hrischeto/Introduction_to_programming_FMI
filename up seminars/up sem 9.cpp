#include <iostream>

//linearExpressionSolver
void divideBy(double arr[], size_t size, double by)
{
	for (int i = 0; i < size; i++)
		arr[i] /= by;
}

void substract(double first[], double second[], double coef, size_t size)
{
	for (int i = 0; i < size; i++)
		first[i] -= (second[i] * coef);
}

void makeAllZeros(double matrix[][3], size_t rows, size_t colls, int currentRow)
{
	for (int i = 0; i < rows; i++)
	{
		if (i != currentRow)
			substract(matrix[i], matrix[currentRow], matrix[i][currentRow], colls);
	}
}

void gauss(double matrix[][3], size_t n, double result[])
{
	size_t rows = n;
	size_t colls = n + 1;

	for (int i = 0; i < rows; i++)
	{
		divideBy(matrix[i], colls, matrix[i][i]);
		makeAllZeros(matrix, rows, colls, i);
	}

	for (int i = 0;i < rows;i++)
	{
		result[i] = matrix[i][colls = 1];
	}

}

void linearExpressionSolver()
{
	constexpr size_t rows = 2;
	constexpr size_t colls = 3;

	double m[rows][colls] = { {2, 6, 40},  // 2x + 6y = 40
								  {4, 1, 14} };// 4x +  y = 14

	double result[rows];
	gauss(m, rows, result);

	for (int i = 0; i < rows; i++)
		std::cout << result[i] << " ";
}

//tic-tac-toe
const size_t N = 3;
const unsigned PLAYERS_COUNT = 2;
const unsigned LINE_LENGTH = 3;
const char EMPTY_FIELD = ' ';

void init(char field[][N], char initWith)
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			field[i][j] = initWith;
		}
	}
}

void printField(const char field[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout << "[" << field[i][j] << "]";
		std::cout << std::endl;
	}
}

bool areValidIndices(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

int getConsecutiveDirection(const char field[][N], int row, int coll, int rowMove, int collMove)
{
	char ch = field[row][coll];

	int count = 0;

	while (areValidIndices(row, coll) && field[row][coll] == ch)
	{
		count++;
		row += rowMove;
		coll += collMove;
	}
	return count;
}

unsigned getConsecutiveOnLine(const char field[][N], int row, int coll, int rowMove, int collMove)
{
	return getConsecutiveDirection(field, row, coll, rowMove, collMove) +
		getConsecutiveDirection(field, row, coll, -rowMove, -collMove) - 1;
}

bool isWinningMove(const char field[][N], int row, int coll)
{
	return   getConsecutiveOnLine(field, row, coll, 0, 1) >= LINE_LENGTH || //horizontal
		getConsecutiveOnLine(field, row, coll, 1, 0) >= LINE_LENGTH || //vertical
		getConsecutiveOnLine(field, row, coll, 1, 1) >= LINE_LENGTH || //main diagonal
		getConsecutiveOnLine(field, row, coll, 1, -1) >= LINE_LENGTH;   //anti diagonal
}

void input(char field[][N], int& x, int& y)
{
	std::cin >> x >> y;

	while (!areValidIndices(x, y) || field[x][y] != EMPTY_FIELD)
	{
		std::cin >> x >> y;
	}
}

void ticTacToe()
{
	char field[N][N];

	init(field, EMPTY_FIELD);
	printField(field);

	bool haveWinner = false;
	for (int i = 0, currentPlayer = 0;i < N * N && !haveWinner;i++, (++currentPlayer) %= PLAYERS_COUNT)
	{
		int row, coll;
		input(field, row, coll);
		field[row][coll] = 'A' + currentPlayer;
		printField(field);
		haveWinner = isWinningMove(field, row, coll);
	}

	std::cout << (haveWinner ? "Winner!" : "Draw!") << std::endl;
}

//zad1
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void transpose(int matrix[][N])
 {
	for (int i = 0; i <N;i++)
	{
		for (int j = 0;j <N;j++)
		{
			if(i!=j&&i<j)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}
}

//zad2
bool isReflexive(const bool relation[][N])
{
	for (int i = 0;i < N;i++)
	{
		if (!relation[i][i])
			return false;
	}

	return true;
}

bool isSimetric(const bool relation[][N])
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (relation[i][j]&& !relation[j][i])
				return false;
		}

		return true;
	}
}

bool isTransitive(const bool relation[][N])
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < N;k++)
			{
				if (relation[i][j] && relation[j][k])
				{
					if (!relation[i][k])
						return false;
				}
			}
		}
	}

	return true;
}

bool isEquivalenceRelation(const bool relation[][N])
{
	return isReflexive(relation) && isSimetric(relation) && isTransitive(relation);
}

//zad3
constexpr size_t M = 2;
constexpr size_t K = 4;
void multipyMatrices(int m1[M][N], int m2[N][K], int result[M][K])
{
	for (int i = 0;i < M;i++)
	{
		for (int k = 0;k < K;k++)
		{
			for (int j = 0;j < N;j++)
			{
				result[i][k] += m1[i][j] * m2[j][k];
			}
		}
	}
}

void printMatrix(const int matrix[][K])
{
	for (int i = 0; i < M;i++)
	{
		for (int j = 0;j < K;j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int main()
{
	bool relation[N][N] = { { 0,1,1 }, 
							{ 0,1,1 }, 
							{ 0,1,1 } };

	std::cout << isTransitive(relation);
}