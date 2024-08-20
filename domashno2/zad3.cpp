#include <iostream>

constexpr size_t DIRECTIONS_COUNT = 8;
constexpr size_t COORDINATES = 2;
int directions[DIRECTIONS_COUNT][COORDINATES] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };

int max(int a, int b)
{
	return a > b ? a : b;
}

int dfs(int** matrix, size_t matrixSize, int i, int j, int** cache)
{
	if (cache[i][j] != 0)
		return cache[i][j];

	int maxLen = 1;
	for (int d = 0;d < DIRECTIONS_COUNT;d++)
	{
		int x = i + directions[d][0];
		int y = j + directions[d][1];

		if (x >= 0 && x < matrixSize && y > 0 && y<=matrix[x][0] && matrix[x][y]>matrix[i][j])
		{
			maxLen = max(maxLen, 1 + dfs(matrix, matrixSize, x, y, cache));
		}
	}

	cache[i][j] = maxLen;

	return maxLen;
}

int findLongestIncreasingPath(int** matrix, size_t matrixSize)
{
	if (!matrix)
		return 0;

	int** cache = new int* [matrixSize];

	for (int i = 0;i < matrixSize;i++)
	{
		cache[i] = new int[matrix[i][0] + 1] {0};
		cache[i][0] = matrix[i][0];
	}

	int maxPath = 0;

	for (int i = 0;i < matrixSize;i++)
	{
		for (int j = 1;j <= matrix[i][0];j++)
			maxPath = max(maxPath, dfs(matrix, matrixSize, i, j, cache));
	}

	return maxPath;
}

void createMatrix(int**& matrix, size_t& rows)
{
	//std::cout << "Enter number of rows:";
	std::cin >> rows;

	matrix = new int* [rows];

	for (int i = 0;i < rows;i++)
	{
		int cols;

		//std::cout << "Enter number of columns for row " << i + 1 << ":";

		std::cin >> cols;

		matrix[i] = new int[cols + 1];
		matrix[i][0] = cols;

		//std::cout << "Enter elements: ";
		for (int j = 1;j < cols+1;j++)
			std::cin >> matrix[i][j];
	}

}

void printMatrix(int** matrix, size_t matrixSize)
{
	for (int i = 0;i < matrixSize;i++)
	{
		for (int j = 0;j <= matrix[i][0];j++)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

void freeMatrix(int** matrix, size_t matrixSize)
{
	if (!matrix)
		return;

	for (int i = 0; i < matrixSize;i++)
	{
		if(matrix[i])
		delete[] matrix[i];
	}

	delete[] matrix;
}

int main()
{
	int** matrix;
	size_t matrixSize = 0;

	createMatrix(matrix, matrixSize);
	printMatrix(matrix, matrixSize);

	int maxPath = findLongestIncreasingPath(matrix, matrixSize);
	std::cout << "Longest increasing path has a length of " << maxPath << std::endl;

	freeMatrix(matrix, matrixSize);
}