#include <iostream>

//zad1
int factoriel(int n)
{
	if (n == 0)
		return 1;

	return n * factoriel(n - 1);
}

//zad2
int fibb(int num)
{
	if (num == 0 || num == 1)
		return 1;

	return fibb(num - 1) + fibb(num - 2);
}

//zad3
int power(int n, int p)
{
	if (p == 0)
		return 1;

	return n * power(n, p - 1);
}

int fastPower(int n, int k)
{
	if (k == 0)
		return 1;
	else if (k % 2 == 1)
		return n * fastPower(n, k - 1);
	else
		return fastPower(n * n, k /2);

}

//zad4
int sum(int* arr, size_t size)
{
	if (size == 0)
		return 0;
	
	return arr[0] + sum(arr+1, size - 1);
}

//zad5
bool linearSearch(int* arr, int size, int num)
{
	if (size == 0)
		return false;
	if (arr[0] == num)
		return true;
	else
		return linearSearch(arr + 1, size - 1, num);
}

//zad6
bool binarySearch(int* arr, int size, int num)
{
	if (size == 0)
		return 0;

	int mid = size / 2;
	if (arr[mid] == num)
		return true;
	else if (arr[mid] < num)
		return binarySearch(arr + (mid + 1), size-mid-1, num);
	else
		return binarySearch(arr, mid, num);
}

//zad7
bool isPalindrom(const char* str, size_t size)
{
	if (size == 1)
		return true;

	if (str[0] == str[size - 1])
		return isPalindrom(str + 1, size - 2);
	else
		return false;
}

//zad8
void countLetters(const char* str, int& smallCount, int& capsCount)
{
	if (!str || !*str)
		return;

	if (*str >= 'a' && *str <= 'z')
		countLetters(str + 1, ++smallCount, capsCount);
	else if (*str >= 'A' && *str <= 'Z')
		countLetters(str + 1, smallCount, ++capsCount);
}

//zad9 
bool isPrefix(const char* text, const char* pattern)
{
	if (!*pattern)
		return true;

	return *pattern == *text && isPrefix(text + 1, pattern + 1);
}

bool findInTextRec(const char* text, int textlen, const char* pattern, int patternlen)
{
	if (patternlen > textlen)
		return false;

	return isPrefix(text, pattern) || findInTextRec(text + 1, textlen - 1, pattern, patternlen);
}

bool findInText(const char* text, const char* pattern)
{
	return findInTextRec(text, std::strlen(text), pattern, std::strlen(pattern));
}

//zad10
int myMax(int a, int b)
{
	return a > b ? a : b;
}

int getMaxInArr(const int* arr, int size)
{
	if (!size)
		return INT_MIN;

	return myMax(arr[0], getMaxInArr(arr + 1, size - 1));
}

int getMaxInArrBinary(const int* arr, int size)
{
	if (size == 0)
		return INT_MIN;
	if (size == 1)
		return arr[0];

	return myMax(getMaxInArrBinary(arr, size / 2), getMaxInArrBinary(arr + size / 2,size-( size / 2)));
}
int main()
{
	int arr[] = { 1, 2, 6, 3, 1 };

	std::cout << getMaxInArr(arr, 5)<< " ";
	std::cout << getMaxInArrBinary(arr, 5);
	return 0;



}