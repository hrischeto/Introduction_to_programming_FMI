#include <iostream>
int binarySearch(int arr[], int len, int searched)
{
	int left = 0;
	int right = len - 1;

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (searched > mid)
			left = mid + 1;
		else if (searched < mid)
			right = mid - 1;
		else
			return mid;
	}

	return -1;
}

void markAsNotPrime(bool sieve[], size_t size, size_t current)
{
	int toMark = current * 2;

	while (toMark < size)
	{
		sieve[toMark] = true;
		toMark += current;
	}
}
void sieveOfErathostenes(bool sieve[], size_t size)
{
	for (int i = 2;i < size;i++)
	{
		if (!sieve[i])
		{
			std::cout << i << std::endl;
			markAsNotPrime(sieve, size, i);
		}

	}
}

//zad1
bool isPalindrom(int arr[], size_t len)
{
	for (int i = 0;i < len / 2;i++)
	{
		if (arr[i] != arr[len - i - 1])
			return 0;
	}

	return 1;
}

//zad2
int lcm(unsigned a, unsigned b)
{

	unsigned max = a > b ? a : b;
	unsigned lcmCandidate = max;
	while (lcmCandidate % a != 0 || lcmCandidate % b != 0)
	{
		lcmCandidate += max;
	}

	return lcmCandidate;
}

int lcmOfArr(int arr[], size_t size)
{
	int toReturn = lcm(arr[0],arr[1]);
	for (int i = 2;i < size;i++)
	{
		toReturn = lcm(toReturn, arr[i]);
	}

	return toReturn;
}

//zad3
int gcd(int n, int k)
{
	if (n < k) //swap
	{
		int temp = n;
		n = k;
		k = temp;
	}

	while (k != 0)
	{
		int mod = n % k;
		n = k;
		k = mod;
	}

	return n;
}

int gcdArr(int arr[], size_t size)
{
	int toReturn = gcd(arr[0], arr[1]);
	for (int i = 2;i < size;i++)
	{
		toReturn = gcd(toReturn, arr[i]);
	}

	return toReturn;
}

//zad4
bool isConcatOfPalindroms(int arr[], size_t size)
{
	bool firstPalindrom = 0;
	bool secondPalindrom = 0;

	for (int i = size - 1;i > 0;i--)
	{
		if (arr[i] == arr[0])
		{
			firstPalindrom = isPalindrom(arr, i+1);
			if (firstPalindrom)
				secondPalindrom = isPalindrom(&arr[i+1], size-(i+1));
		}

		if (firstPalindrom && secondPalindrom)
			return true;
	}

	return false;
}

//zad5
int inversions(int arr[], size_t len)
{
	int inversions = 0;
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = i+1;j < len;j++)
		{
			if (arr[i] > arr[j])
				inversions++;
		}
	}

	return inversions;
}

//zad6
int smallestMissingNumber(int arr[], size_t size)
{
	for (int i = 1;i < size;i++)
	{
		if (arr[i] != arr[i - 1] + 1)
			return arr[i - 1] + 1;
	}
}

int findSmallestMissing(int arr[], size_t size)
{
	int left = 0, right = size- 1;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] - mid == arr[left] - left) {
			left = mid + 1; 
		}
		else {
			right = mid;
		}
	}

	return arr[left] - 1;
}

int main() {
	int arr1[7] = {5, 6, 7, 9, 10, 12, 13};
	int arr2 [5] = {10, 12, 13, 14, 16};

	std::cout <<  findSmallestMissing(arr1,7) << std::endl; // Изход: 8
	std::cout << findSmallestMissing(arr2,5) << std::endl; // Изход: 11

	return 0;
}

