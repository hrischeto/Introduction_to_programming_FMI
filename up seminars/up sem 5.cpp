#include <iostream>

namespace bullsAndCows
{
	const int DIGIT_COUNT = 4;

	unsigned getDigitsCount(unsigned n)
	{
		if (n == 0)
			return 1;
		unsigned count = 0;

		while (n != 0)
		{
			count++;
			n /= 10;
		}
		return count;
	}

	unsigned countDigitOccurences(unsigned n, unsigned digit)
	{
		if (digit == 0 && n == 0)
			return 1;

		unsigned count = 0;
		while (n != 0)
		{
			int lastDigit = n % 10;
			if (lastDigit == digit)
				count++;
			n /= 10;
		}
		return count;
	}

	bool areAllDistinctDigits(unsigned n)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (countDigitOccurences(n, i) > 1)
				return false;
		}
		return true;
	}

	bool isValidInput(unsigned n)
	{
		return areAllDistinctDigits(n) && getDigitsCount(n) == DIGIT_COUNT;
	}

	unsigned userInput()
	{
		unsigned n;
		do
		{
			std::cin >> n;
		} while (!isValidInput(n));
		return n;
	}

	unsigned getBulls(unsigned toGuess, unsigned myGuess)
	{
		unsigned bulls = 0;
		while (toGuess != 0)
		{
			if (toGuess % 10 == myGuess % 10)
				bulls++;
			toGuess /= 10;
			myGuess /= 10;
		}
		return bulls;

	}

	unsigned getBullsAndCowsSum(unsigned toGuess, unsigned myGuess)
	{
		unsigned sum = 0;
		while (toGuess != 0)
		{
			int lastDigit = toGuess % 10;

			bool contains = countDigitOccurences(myGuess, lastDigit) == 1;

			if (contains)
				sum++;

			toGuess /= 10;
		}
		return sum;
	}

	void getBullsAndCows(unsigned toGuess, unsigned myGuess,
		unsigned& bulls, unsigned& cows)
	{
		bulls = getBulls(toGuess, myGuess);
		cows = getBullsAndCowsSum(toGuess, myGuess) - bulls;
	}

	void bullsAndCows() {
		unsigned toGuess = userInput();
		std::cout << "Success! Try and guess it." << std::endl;
		unsigned bulls, cows;
		do
		{
			unsigned myGuess = userInput();
			getBullsAndCows(toGuess, myGuess, bulls, cows);
			std::cout << "Bulls: " << bulls << " Cows: " << cows << std::endl;
		} while (bulls != DIGIT_COUNT);
		std::cout << "Congratulations! " << std::endl;
	}
}

int countDigits(unsigned n)
{
	int count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}

	return count;
}
int concat(unsigned a, unsigned b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a * 10;

	int digitCount = countDigits(b);
	int del = 1;
	for (int i = 1;i < digitCount;i++)
		del *= 10;
	while (b)
	{
		(a *= 10) += (b / del);
		b %= del;
		del /= 10;
	}

	return a;
}
int main()
{
	std::cout<<concat(123, 456);
	
}

