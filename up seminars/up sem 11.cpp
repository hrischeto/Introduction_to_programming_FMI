#include <iostream>

//zad1
size_t getLengthWihtoutNumbers(const char* str)
{
	if (!str)
		return 0;

	int length = 0;
	bool number = 0;

	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			length++;
			if (number)
				number = 0;
		}
		else 
		{
			if (!number)
			{
				number = 1;
				length++;
			}
		}

		str++;
	}

	return length;
}

char* censoreNumbers(const char* str)
{
	if (!str)
		return nullptr;

	char* censored = new char[getLengthWihtoutNumbers(str) + 1];

	char* start = censored;
	bool number = 0;

	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			*censored = *str;
			censored++;

			if (number)
				number = 0;
		}
		else
		{
			if (!number)
			{
				number = 1;

				*censored = '*';
				censored++;
			}
		}

		str++;
	}

	*censored = '\0';
	censored = start;

	return censored;
	 
}

//zad2
size_t getSmallLettersCount(const char* str)
{
	if (!str)
		return 0;

	int count = 0;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			count++;
		}
		str++;
	}

	return count;
}

size_t getCapitalLettersCount(const char* str)
{
	if (!str)
		return 0;

	int count = 0;

	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			count++;
		}
		str++;
	}

	return count;
}

void getSizes(const char* str, size_t& smallLetters, size_t& caps)
{
	if (!str)
		return;
	smallLetters = caps = 0;

	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			caps++;

		else if (*str >= 'a' && *str <= 'z')
			smallLetters++;

		str++;
	}

}

void seperateString(const char* str, char*& small, char*& caps)
{
	if (!str)
		return;

	size_t smallSize = 0;
	size_t capSize = 0;
	getSizes(str, smallSize, capSize);
	small = new char[smallSize + 1];
	caps = new char[capSize + 1];

	char* smallPtr = small;
	char* capsPtr = caps;

	while(*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*capsPtr = *str;
			capsPtr++;
		}
		else if (*str >= 'a' && *str <= 'z')
		{
			*smallPtr = *str;
			smallPtr++;
		}
		str++;
	}

	*smallPtr = '\0';
	*capsPtr = '\0';
}

//zad3
void merge(const int* arr1, size_t size1, const int* arr2, size_t size2, int* result)
{
	size_t arr1Index = 0, arr2Index = 0, resultIndex = 0;

	while (arr1Index < size1 && arr2Index < size2)
	{
		if (arr1[arr1Index] < arr2[arr2Index])
			result[resultIndex++] = arr1[arr1Index++];
		else
			result[resultIndex++] = arr2[arr2Index++];
	}

	while (arr1Index < size1)
		result[resultIndex++] = arr1[arr1Index++];
	
	while(arr2Index<size2)
		result[resultIndex++] = arr2[arr2Index++];


}

int getBound(const int* arr, size_t size)
{
	if (!arr)
		return 0;

	for (int i = 0; i < size;i++)
	{
		if (arr[i] < arr[i - 1])
			return i;
	}
	
	return -1;
}

void sortArrayConcatOfTwoSortedArrays(int* arr, size_t size)
{
	if (!arr)
		return;

	int secondArrayStartIndex = getBound(arr, size);

	if (secondArrayStartIndex == -1)
		return;

	int* temp = new int[size];

	merge(arr, secondArrayStartIndex,
		arr + secondArrayStartIndex , size - secondArrayStartIndex,
		temp);

	for (int i = 0;i < size;i++)
	{
		arr[i] = temp[i];
	}
	
	delete[] temp;

}

//zad4
void fillArr(char* smallArr, const char* original)
{
	if (!smallArr || !original)
		return;

	while (*original)
	{
		if (*original >= 'a' && *original <= 'z') 
		{
			*smallArr = *original;
			smallArr++;
		}
			original++;
	}

	*smallArr = '\0';
}

void selectionSort(char* str)
{
	if (!str)
		return;

	size_t size = std::strlen(str);

	for (int i = 0;i < size - 1;i++)
	{
		int minElementIndex = i;

		for (int j = i+1;j < size;j++)
		{
			if (str[j] < str[minElementIndex])
				minElementIndex = j;
		}

		if (minElementIndex != i)
			std::swap(str[i], str[minElementIndex]);
	}
}

char* sortSmallLetters(const char* str)
{
	if (!str)
		return nullptr;

	size_t size = getSmallLettersCount(str) + 1;

	char* smallLetters = new char[size];

	fillArr(smallLetters, str);

	selectionSort(smallLetters);

	return smallLetters;

}

//zad2
int getNumIndex(const int* arr, size_t size,int num)
{
	if (!arr)
		return -1;

	int index = 0;

	for (int i = 0;i < size;i++)
	{
		if (arr[i] < num)
			index++;
	}

	return index;
}

void fillSeparated(const int* arr, size_t size, int* separated, int num, size_t numIndex)
{
	if (!arr || !separated)
		return;

	int before = 0;
	int after = numIndex + 1;

	int arrIndex = 0;

	while (arrIndex < size)
	{
		if (arr[arrIndex] < num)
			separated[before++] = arr[arrIndex++];
		else if (arr[arrIndex] > num)
			separated[after++] = arr[arrIndex++];
		else
		arrIndex++;
	}
}

void printArr(const int* arr, size_t size)
{
	if (!arr)
		return;

	for (int i = 0;i < size;i++)
	{
		std::cout << arr[i]<<" ";
	}
}

int* separateArr(const int* arr, size_t size, int num)
{
	if (!arr)
		return nullptr;

	int* separated = new int[size];

	size_t numIndex = getNumIndex(arr, size, num);
	if (numIndex == -1)
		return nullptr;

	separated[numIndex] = num;

	fillSeparated(arr, size, separated, num, numIndex);

	return separated;

}

//zad3

void printSet(int* set, size_t size)
{
	if (!set)
		return;

	std::cout << '[';
	for (int i = 1;i <= size;i++)
		std::cout << set[i] << ' ';
	std::cout << ']' << std::endl;
}

int onesCount(int num)
{
	int count = 0;

	while (num)
	{
		if (num % 2 == 1)
			count++;
		num /= 2;
	}

	return count;
}

void fillSubset (int* set, size_t size, int*& subset, unsigned mask)
{
	size_t setSize = onesCount(mask);

	subset = new int[setSize+1];
	subset[0] = setSize;

	int setIndex = 1;
	for (int i = size - 1; i >= 0; i--)
	{
		if (mask % 2 != 0)
			subset[setIndex++] = set[i];
		mask /= 2;
	}

}

void generateSubsets(int* set, size_t size, int** subsets, size_t matrixSize)
{
	if (!set || !subsets)
		return;

	for (unsigned i = 0; i < matrixSize; i++) 
		fillSubset(set, size, subsets[i], i + 1);

	}

int** subsets(int* set, size_t size, size_t& matrixSize)
{
	matrixSize = (1 << size) - 1;

	int** subsets = new int* [matrixSize];

	generateSubsets(set, size, subsets, matrixSize);

	return subsets;
}

void printSubsets(int** subsets, size_t rows)
{
	if (!subsets)
		return;

	for (int i = 0;i < rows;i++)
		printSet(subsets[i], subsets[i][0]);
}
int main()
{
	int set[5] = { 1, 2, 3,4,5 };

	size_t matrixSize = 0;
	int** matrix = subsets(set, 5, matrixSize);
	
	printSubsets(matrix, matrixSize);
}