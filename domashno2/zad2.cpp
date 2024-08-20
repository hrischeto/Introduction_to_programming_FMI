// fn9MI0600381_d2_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Hristina Krumova
* @idnumber 9MI0600381
* @task 3
*
*/

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
