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

//zad4
int getNumIndex(const int* arr, size_t size,int num)
{
	if (!arr)
		return -1;

	for (int i = 0;i < size;i++)
	{
		if (arr[i] == num)
			return i;
	}

	return -1;
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

int main()
{
	int arr[] = { 1, 5, 6, 3, 0, -1, 2, 9, 7 };
	int* separated = separateArr(arr, 9, 3);
	
	if(separated)
	printArr(separated, 9);
}