#include <iostream>

//zad1
void createTeams(int** table, size_t teamsCount)
{
	if (!table)
		return;

	for (int i = 0;i < teamsCount;i++)
	{
		int players;
		std::cin >> players;

		table[i] = new int[players + 2] {0};
		table[i][0] = players;
	}
}

void swap(int*& first, int*& second)
{
	int* temp = first;
	first = second;
	second = temp;
}

void moveToCorrectRow(int** mtx, int lastModifedRow)
{
	int current = lastModifedRow;

	while (current > 0 && mtx[current][1] > mtx[current - 1][1])
	{
		swap(mtx[current], mtx[current - 1]);
		current--;
	}
}

void addPoints(int** table, int row, int coll, int points)
{
	if (!table)
		return;

	table[row][coll + 2] += points;
	table[row][1] += points;
	moveToCorrectRow(table, row);
}

void printTeam(int* team)
{
	if (!team)
		return;

	for (int i = 2;i <= team[0]+1;i++)
	{
		std::cout << team[i] << " ";
	}

	std::cout << std::endl;
}

void printTable(int** table, size_t teamsCount)
{
	if (!table)
		return;

	for (int i = 0;i < teamsCount;i++)
		printTeam(table[i]);

	std::cout << std::endl;
}

void freeMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void teamsResult()
{
	int teamsCount = 0;
	std::cin >> teamsCount;

	int** table = new int* [teamsCount];
	createTeams(table, teamsCount);
	printTable(table, teamsCount);
	
	int points = 0, row = 0, coll = 0;

	while (true)
	{
		std::cin >> row >> coll >> points;

		if (points < 0)
			break;

		addPoints(table, row, coll, points);
		printTable(table, teamsCount);
	}

	freeMatrix(table, teamsCount);
}

int main()
{
	teamsResult();
}