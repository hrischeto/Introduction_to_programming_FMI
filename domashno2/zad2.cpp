#include <iostream>
constexpr size_t MAX_SIZE = 1024;

void print(const char* arr)
{
	if (!arr)
	{
		std::cout << "Incorrect input" << '\n';
		return;
	}

	std::cout << arr << '\n';
}

void swap(char& first, char& second)
{
	char temp = first;
	first = second;
	second = temp;
}

void selectionSort(char arr[], int n)
{
	int min_idx = 0;

	for (int i = 0; i < n - 1; i++) {

		min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
			swap(arr[min_idx], arr[i]);
	}
}

int myStrlen(const char* str)
{
	if (!str)
		return 0;

	int lenght = 0;
	while (*str)
	{
		lenght++;
		str++;
	}

	return lenght;
}

void getNextPermutation(char* arr, int arrLenght, bool& dcs)
{
	if (!arr)
		return;

	int toSwapFirst= -1;

	for (int i = 1;i < arrLenght;i++)
	{
		if (arr[i] > arr[i - 1])
			toSwapFirst = i;
	}

	if (toSwapFirst == -1)
	{
		dcs = 1;
		return;
	}

	int toSwapSecond = toSwapFirst;
	for (int i = toSwapFirst;i < arrLenght;i++)
	{
		if (arr[i] > arr[toSwapFirst - 1] && arr[i] < arr[toSwapSecond])
			toSwapSecond = i;
	}

	swap(arr[toSwapFirst - 1], arr[toSwapSecond]);

	char* startSorting = &arr[toSwapFirst];
	int sortFor = arrLenght - toSwapFirst;
	selectionSort(startSorting, sortFor);
}

void generateFirstNArrangements(char* symbolsToArrange, unsigned n)
{
	
	if (!symbolsToArrange)
	{
		print(symbolsToArrange);
		return;
	}

	int arrLenght = myStrlen(symbolsToArrange);
	
	
	if (arrLenght == 1) 
	{
		print(symbolsToArrange);
		return;
	}

	selectionSort(symbolsToArrange, arrLenght);
	print(symbolsToArrange);

	bool isInDescendingOrder = 0;
	for (int i = 1;i < n;i++)
	{
		getNextPermutation(symbolsToArrange, arrLenght,isInDescendingOrder);

		if (!isInDescendingOrder)
			print(symbolsToArrange);
		else
			return;
	}
	
}
int main()
{
	char symbolsToArrange[MAX_SIZE];
	std::cin >> symbolsToArrange;
	char* symbolsToArrangePtr = symbolsToArrange;

	unsigned n;
	std::cin >> n;

	generateFirstNArrangements(symbolsToArrangePtr, n);

}
