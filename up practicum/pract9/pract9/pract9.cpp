#include <iostream>
constexpr size_t N= 3;
//zad1
int minElementInMatrix(int m[][N], size_t rows)
{
	int min = INT_MAX;

	for (int i = 0;i < rows; i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (m[i][j] < min)
				min = m[i][j];
		}
	}

	return min;
}

//zad2
void mainDiagonal(int m[N][N])
{
	for (int i = 0;i < N;i++)
	{
		std::cout << m[i][i] << " ";
	}
}

void secondaryDiagonal(int m[N][N])
{
	for (int i = 0;i < N;i++)
	{
		std::cout << m[i][N-i-1] << " ";
	}
}

//zad3
void zigzag(int m[][N], int rows)
{
	for (int i = 0;i < rows;i++)
	{
		if (i % 2 == 0)
			for (int j = 0;j < N;j++)
				std::cout << m[i][j]<<" ";
		else
			for (int j = N - 1;j >= 0;j--)
				std::cout << m[i][j]<<" ";
		std::cout << std::endl;
	}
}

//zad 4
bool isTriangle(int m[N][N])
{
	for (int i = 1;i <N ;i++)
	{
		for (int j = 0;j < N;j++)
			if (j < i && m[i][j] != 0)
				return false;
	}
	return true;
}

//zad6
bool isMagicSquare(int m[N][N])
{
	int sum = 0;
	
	for (int i = 0;i < N;i++)
	{
		sum += m[0][i];
	}

	int rowSum = 0, colSum = 0, mainSum = 0, secSum = 0;

	for (int i = 0;i < N;i++)
	{
		rowSum = colSum = 0;
		for (int j = 0;j < N;j++)
		{
			rowSum += m[i][j];
			colSum += m[j][i];
		}

		std::cout << "rowSum " << rowSum << " colSum " << colSum;
		if (rowSum != sum||colSum!=sum)
			return false;

		mainSum+= m[i][i];
		secSum+= m[i][N-i-1];
	}
	
	std::cout <<" " << mainSum << " " << secSum;
	if (mainSum != sum || secSum != sum)
		return false;
	return true;

}

//zad10
void  rotate(int m[][N])
{
	int newMt[N][N]{ 0 };

	for (int i = 0;i < N;i++)
	{
		for (int j = N-1;j >=0;j--)
		{
			newMt[i][N-j-1] = m[j][i];
		}
	}

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			m[i][j] = newMt[i][j];
		}
	}
}

void printMatrix(int m[][N])
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			std::cout << m[i][j] << " ";
		}
		std::cout << '\n';
	}
}
int main()
{
	int m[N][N] = { {1,2,3}, {4,5,6},{7,8,9} };
	rotate(m);
	printMatrix(m);
}