#include <iostream>

//zad1
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

//zad2
int gcd(unsigned n, unsigned k)
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

//zad3
bool isPrime(unsigned n)
{
	if (n <= 1)
	{
		return 0;
	}

	bool isPrime = true;
	double sqrtFromNumberToCheck = sqrt(n);
	for (int i = 2; i <= sqrtFromNumberToCheck; i++)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}

//zad4
void delimiters(unsigned n)
{
	for (int i = n; i > 1; i--)
	{
		bool isprime = true;
		if (!isPrime(isprime))
			continue;

		int count = 0;
		while (n % i == 0)
		{
			count++;
			n /= i;
		}

		if (count >= 1)
		{
			std::cout << i;
			if (count >= 2)
				std::cout << "^" << count << " ";
		}
	}

}

//zad5
void delimitersUpwards(unsigned n)
{
	for (int i = 2; i <=n; i++)
	{
		bool isprime = true;
		if (!isPrime(isprime))
			continue;

		int count = 0;
		while (n % i == 0)
		{
			count++;
			n /= i;
		}

		if (count >= 1)
		{
			std::cout << i;
			if (count >= 2)
				std::cout << "^" << count << " ";
		}
	}

}

//zad6
int mostEncountered(int n)
{
	int mostCommonDigit = -1;
	int occurrences = 0;
	for (int currDigit = 0;currDigit <= 9;currDigit++)
	{
		int currentDigitOccurrences = 0;
		int copy = n;
		while (copy)
		{ 
			if (currDigit== copy % 10)
				currentDigitOccurrences++;
			copy /= 10;
		}
		if (currentDigitOccurrences > occurrences)
		{
			occurrences = currentDigitOccurrences;
			mostCommonDigit = currentDigitOccurrences;
		}
	}
	
	return mostCommonDigit;
}

//zad7
void hourglass(unsigned n)
{
	if (n % 2 == 0) {
		std::cout << "the number must be odd";
		return;
	}

	int whitespaceCount = 0;
	int starCount = n;

	while (starCount>0)
	{
		for (int j = 0; j < whitespaceCount;j++)
		{
			std::cout << ' ';
		}

		for (int j = 0;j < starCount;j++)
		{
			std::cout << '*';
		}

		for (int j = 0; j < whitespaceCount;j++)
		{
			std::cout << ' ';
		}

		std::cout << "\n\n";

		whitespaceCount++;
		starCount -= 2;
	}

	whitespaceCount -= 2;;
	starCount = 3;

	while (starCount <= n)
	{
		for (int j = 0; j < whitespaceCount;j++)
		{
			std::cout << ' ';
		}

		for (int j = 0;j < starCount;j++)
		{
			std::cout << '*';
		}

		for (int j = 0; j < whitespaceCount;j++)
		{
			std::cout << ' ';
		}

		std::cout << "\n\n";

		whitespaceCount--;
		starCount += 2;
	}
	
}

//zad1
void sum()
{
	int n = 0;
	std::cin >> n;
	int sum = 0;
	while (n)
	{
		sum += n;
		std::cin >> n;
	}
	std::cout << sum;
}

//zad2
void commonDelimiters(unsigned n, unsigned k)
{
	if (n < k) //swap
	{
		int temp = n;
		n = k;
		k = temp;
	}

	for (int i = k;i > 0;i--)
	{
		if ((n % i == 0 )&&( k % i == 0))
			std::cout << i<<" ";
	}
}

//zad3
int digitCount(int n)
{
	int length = 0;

	while (n)
	{
		length++;
		n /= 10;
	}

	return length;
}
void modifyNum(unsigned n)
{
	int length = digitCount(n);

	int newNum = 0;
	int multiplier = 1;
	if (length % 2 == 0)
	{
		for (int i = 1;i <= length;i++)
		{
			if (i != length / 2 && i != length / 2 + 1)
			{
				newNum += multiplier * (n % 10);
				multiplier *= 10;
			}
			n /= 10;
		}
	}

	else 
	{
		for (int i = 1;i <= length;i++)
		{
			if (i != length / 2 + 1)
			{
				newNum += multiplier * (n % 10);
				multiplier *= 10;
			}
			
			n /= 10;
		}
	}

	std::cout << newNum + 1;
}

//zad4
void printPrimeNumInInterval(unsigned a, unsigned b)
{
	for (int i = a;i <= b;i++)
	{
		if (isPrime(i))
			std::cout << i<<" ";
	}
}

//zad5
bool isPowerOfTwo(int n)
{
	if (n == 1)
		return true;
	while (n > 1)
	{
		if (n % 2 != 0)
			return false;
		n /= 2;
	}

	return true;
}

//zad6
void zerosOfPolinome(int a, int b, int c, int d, int e)
{
	for (int x = -100;x <= 100;x++)
	{
		if ((x * x * x * x * a +
			b * x * x * x
			+ c * x * x
			+ d * x
			+ e) >= 0)
			std::cout << x << " ";
	}
}

//zad7
void dollars(int n)
{
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < i;j++)
			std::cout << "$ ";
		std::cout <<'\n'<< std::endl;
	}
}

//zad8
void numberPyramid(int n)
{
	for (int i = 1;i <= n ;i++)
	{
		for (int j = 0;j < n - i;j++)
			std::cout << " ";

		for (int j = i;j >= 1;j--)
			std::cout << j;
		std::cout << std::endl;
	}

	for (int i = n-1;i > 0;i--)
	{
		for (int j = 0;j < n - i;j++)
			std::cout << " ";

		for (int j = i;j >= 1;j--)
			std::cout << j;
		std::cout << std::endl;
	}


}

//zad9
//void spiral1(unsigned n)
//{
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= n;j++)
//		{
//			
//		}
//		std::cout << std::endl;
//	}
//}

//zad10
void spiral2(unsigned n)
{
	for (int row = 0;row <n;row++)
	{
		if(row%2==1)
			for (int i = n;i >= 1;i--)
				std::cout<< i + n * row<<" ";
		else
		for (int i = 1;i <= n;i++)
		{
			std::cout << i + n * row<<" ";
		}

		std::cout << "\n\n";
	}
}

//zad16
void twoBiggestNumbers(unsigned n)
{
	int firstBiggest = 0;
	int secondBiggest = 0;

	for (int i = 0;i < n;i++)
	{
		int num = 0;
		std::cin >> num;

		if(num>firstBiggest)
		{
			secondBiggest = firstBiggest;
			firstBiggest = num;
		}
	}

	std::cout << firstBiggest <<" "<< secondBiggest;
}
int main()
{
	twoBiggestNumbers(5);
}
