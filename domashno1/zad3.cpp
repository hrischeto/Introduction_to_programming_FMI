const int minimumRepetitions = 3;
constexpr size_t size = 1024;
const int maxArrLenght = 256;
const int maxShots = 127;
#include <iostream>

int fillArr(char arr[], int len)
{
	for (int i = 0;i < len; i++)
	{
		std::cin >> arr[i];
		if (arr[i] < 'a' || arr[i]>'z')
		{
			std::cout << "Invalid input\n";
			return -1;
		}
	}
	return 0;
}

void addElement(char arr[], int aimInd, int& len, char toAdd)
{
	for (int i = len - 1;i >= aimInd;i--)
		arr[i + 1] = arr[i];

	arr[aimInd + 1] = toAdd;
	len++;
	
}

void findRepetitions(const char arr[], int& len, int& repetitionsCount, int element, int& begginingOfSequence)
{
	for (int i = element; i < len;i++)
	{
		if (arr[i] == arr[element])
			repetitionsCount++;
		else
			break;
	}

	for (int i = element;i >= 0;i--)
	{
		if (arr[i] == arr[element])
		{
			repetitionsCount++;
			begginingOfSequence = i;
		}
		else
			break;
	}
	len -= repetitionsCount;
}

void deleteSequence(char arr[],int len, int repetitionsCount, int begginingOfSequence)
{
	for (int i = begginingOfSequence; i < len; i++)
	{
		arr[i] = arr[i + repetitionsCount];
	}
}

void additionalSequences(char arr[], int len, int repetitionsCount, int begginingOfSequence )
{
	while (repetitionsCount >= minimumRepetitions)
	{
		deleteSequence(arr, len, repetitionsCount, begginingOfSequence);
		repetitionsCount = 0;
		findRepetitions(arr, len, repetitionsCount, begginingOfSequence, begginingOfSequence);
	}
}

void print( const char arr[], int len)
{
	if (len == 0)
		std::cout << -1;
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i];
	}
}

int main()
{
	char arr[size];

	int len, shots, aimInd;
	char symbol;
	std::cin >> len;
	if (len < 0 || len>maxArrLenght)
	{
		std::cout << "Invalid input\n";
		return -1;
	}

	fillArr(arr, len);

	std::cin >> shots;
	if (shots < 0 || shots>maxShots)
	{
		std::cout << "Invalid input\n";
		return -1;
	}

	
	while (shots > 0)
	{
		shots--;
		std::cin >> aimInd  >> symbol;

		if (aimInd > len - 1)
			continue;
		else if (aimInd < 0)
		{
			std::cout << "Invalid input\n";
			return -1;
		}

		if(symbol < 'a' || symbol>'z')
		{
			std::cout << "Invalid input\n";
			return -1;
		}

			addElement(arr, aimInd, len, symbol);

			int repetitionsCount = 0;

			int begginingOfSequence = 0;
			findRepetitions(arr, len, repetitionsCount, aimInd + 1, begginingOfSequence);

			if (repetitionsCount >= minimumRepetitions)
			{
				deleteSequence(arr, len, repetitionsCount, begginingOfSequence);
				repetitionsCount = 0;
				findRepetitions(arr, len, repetitionsCount, begginingOfSequence, begginingOfSequence);

				additionalSequences(arr, len, repetitionsCount, begginingOfSequence);
				
			}
		
	}

	print(arr, len);
}
