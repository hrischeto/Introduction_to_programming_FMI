#include <iostream>
unsigned fromBinaryToDecimal(unsigned n)
{
	unsigned result = 0;
	unsigned mult = 1;

	while (n)
	{
		result += mult * n % 10;
		mult *= 2;
		n /= 10;
	} 

	return result;
}

unsigned fromDecimalToBinary(unsigned n)
{
	unsigned result = 0;
	unsigned mult = 1;

	while (n)
	{
		if(n%2)
		result +=mult;
		mult *= 10;
		n /= 2;
	}

	return result;
}

//numeric systems converter
char getSymbolFromIndex(unsigned ind)
{
	if (ind >= 0 && ind <= 9)
		return ind + '0';

	if (ind >= 10)
		return ind - 10 + 'A';
}

int getIndexFromSymbol(char  ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ch - 'A' + 10;

	if (ch >= '0' && ch <= '9')
		return ch - '0';
}

void fromDecimalToRandom(unsigned n, char to[], size_t size, unsigned numericSystem)
{
	for (int i = size - 1;i >= 0;i--)
	{
		int ind = n % numericSystem;
		char current = getSymbolFromIndex(ind);

		to[i] = current;

		n /= numericSystem;
	}
}

unsigned fromRandomToDecimal(const char from[], size_t size, unsigned k)
{
	unsigned result = 0;
	unsigned mult = 1;

	for (int i = size - 1;i >= 0;i--)
	{
		result += getIndexFromSymbol(from[i])*mult;

		mult *= k;
	}

	return result;
}

void fromRandomToRandom(const char from[], size_t fromSize, int k, char to[], size_t toSize, int n)
{
	int decimal=fromRandomToDecimal(from, fromSize, k);
	fromDecimalToRandom(n, to, toSize, k);
}

void print(const char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
int main()
{
	constexpr int SIZE = 5;
	{
		char from[] = { '0', 'A', 'A','B', '3' };
		unsigned n = fromRandomToDecimal(from, SIZE, 16); //AAB3 in hex to decimal;
		std::cout << n << std::endl;;

	}

	{
		char to[SIZE] = {};
		fromDecimalToRandom(1234, to, SIZE, 16); //124 in decimal to hex;
		print(to, SIZE);
	}

	{
		char from[SIZE] = { '0', '0', 'A','B', '3' };

		char to[SIZE];
		//init(to, SIZE, '0');

		fromRandomToRandom(from, SIZE, 16, to, SIZE, 10);

		print(to, SIZE);
	}

}