#include <iostream>
bool isPrime(unsigned n)
{
	if (n <= 1)
		return false;

	double temp = std::sqrt(n);

	for (int i = 2; i <= temp; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}
//zad1
void pairs(unsigned n)
{
	for (int i = 6;i < n;i += 6)
	{
		if (isPrime(6 * i - 1) && isPrime(6 * i + 1))
			std::cout <<  i - 1 << ", " << i + 1 << std::endl;;
	}
}

//zad4
bool isSuffix(int n, int k)
{
	int suffix = 0;
	int kCopy = k;
	int mult = 1;
	while (kCopy&&n)
	{
		suffix += (n % 10)*mult;
		n /= 10;
		kCopy /= 10;
		mult *= 10;
	}

	return k == suffix;
}

//zad6
bool isInfix(int n, int k)
{
	while (n >= k)
	{
		if (isSuffix(n, k))
			return true;
		n /= 10;
	}

	return false;
}

//zad6
int countPrimeDelimiters(int i)
{
	int delimitersCount = 0;

	for (int j = i;j > 0;j--)
	{
		if (i % j == 0 && isPrime(j))
		{
			delimitersCount++;
			i /= j;
			if (i == 1)
				return delimitersCount;
		}

	}
}
int primeDelimiters(int a, int b, int k)
{
	int numsWithKPrimeDelimiters = 0;

	for (int i = a; i <= b; i++)
	{
		if (countPrimeDelimiters(i) == k)
			numsWithKPrimeDelimiters++;
	}

	return numsWithKPrimeDelimiters;
}

//zad9
int sortDigits(unsigned n)
{
	int result = 0;

	for (int i = 0;i <= 9;i++)
	{
		unsigned temp = n;

		while (temp)
		{
			if (temp % 10 == i)
				(result *= 10) += temp % 10;
			temp /= 10;
		}
	}

	return result;
}
int main()
{
	std::cout << sortDigits(531261);
}