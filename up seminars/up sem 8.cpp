#include <iostream>
typedef unsigned uns;

//basic bitwise functions
bool checkBit(int n, uns ind)
{
	uns mask = 1;

	mask <<= ind;

	return (mask & n) == mask;
}

uns clearBit(int n, uns ind)
{
	uns mask = 1;
	mask <<= ind;
	mask= ~mask;

	return n & mask;
}

uns setBit(int n, uns ind)
{
	uns mask = 1;
	mask <<= ind;

	return n | mask;
}

uns toggleBit(int n, uns ind)
{
	uns mask = 1;
	mask <<= ind;

	return n ^ mask;
}

//zad1
int getMissing(int arr[], size_t size)
{
	int result = 0;
	for (int i = 0;i < size;i++)
	{
		result ^= arr[i];
	}

	return result;
}

//zad2
uns countOnes(int n)
{
	uns mask = 1;
	int count = 0;
	while (n)
	{
		if (mask & n)
			count++;

		n >>= 1;
	}

	return count;
}

//zad3
int clearFirstOne(int n)
{

	uns mask = 1;
	
	while (mask <= n)
	{
		if (mask & n)
		{
			mask = ~mask;
			return n & mask;
		}
		mask <<= 1;
	}
	return 0;
}

//zad4
int getEncodedNumber(int n, uns k)
{
	int mask = 0;
	mask = ~mask;
	mask <<= k;
	mask = ~mask;

	return mask & n;
}

//zad5
bool isPartOfN(int n, int k)
{
	while (n)
	{
		if ((n | k) == n)
			return true;

		n >>= 1;
	}

	return false;
}


//zad6
void printSubset(const int arr[], size_t size, unsigned mask)
{
	std::cout << "{ ";
	for (int i = size - 1; i >= 0; i--)
	{
		if (mask % 2 != 0)
			std::cout << arr[i] << " ";
		mask /= 2;
	}
	std::cout << "} " << std::endl;

}

void generateSubsets(const int arr[], size_t size)
{
	//size <= 32
	unsigned pt = 1<<size;
	for (unsigned i = 0; i < pt; i++)
		printSubset(arr, size, i);
}

int main()
{
	constexpr size_t SIZE = 5;
	int arr[SIZE] = { 1,2,3,4,5 };

	generateSubsets(arr, SIZE);
}