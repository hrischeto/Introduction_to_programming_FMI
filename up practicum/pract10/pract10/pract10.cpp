#include <iostream>

//zad1
void addSymbol(const char* text,char symbol, int pos, char* result)
{
	if (!text || !result)
		return;

	size_t len = std::strlen(text);

	for (int i = 0;i <= len;i++)
	{
		if (i == pos)
			*result = symbol;
		
		else
		{
			*result = *text;
			text++;
		}
		result++;
	}
	*result = '\0';

}

//zad2
void reorder(const char* text, char* result)
{
	if (!text || !result)
		return;

	int len = std::strlen(text);

	for (int i = 0;i < len;i += 2)
	{
		result[(text[i + 1] - '0')] = text[i];
	}

	result[len / 2] = '\0';
}

//zad3
const int DIGITS = 10;

void getDigits(const char* str, int* counter)
{
	if (!str || !counter)
		return;

	while (*str)
	{
		int index = *str - '0';

		counter[index]++;
		str++;
	}
}

void fillResult(const int* count, char* result)
{
	if (!count || !result)
		return;

	for (int i = 0;i < DIGITS;i++)
	{
		if (count[i])
		{
			*result = count[i] + '0';
			result++;
			*result = 'x';
			result++;
			*result = i+'0';
			result++;
			*result = ',';
			result++;
		}
	}
	*(result-1) = '\0';
}

void countDigits(const char* str, char* result)
{
	if (!str || !result)
		return;

	int count[10] { 0 };

	getDigits(str, count);
	fillResult(count, result);
}

//zad4
void shiftLeft(char* str)
{
	if (!str)
		return;

	while (*str)
	{
		*str = *(str + 1);
		str++;
	}
}

void removeSymbol(char* str, char symbol)
{
	if (!str)
		return;

	while (*str)
	{
		if (*str == symbol)
			shiftLeft(str);
		str++;
	}
}

//zad5
bool checkElement(const char* str, char element)
{
	if (!str)
		return 0;

	while (*str)
	{
		if (*str == element)
			return 1;

		str++;
	}

	return 0;
}

void getDifferenceFromArr(const char* str1, const char* str2, char*& result)
{

	if (!str1 || !str2 || !result)
		return;

	const char* ptr2 = str2;

	while (*str1)
	{
		if (!checkElement(ptr2, *str1))
		{
			*result = *str1;
			result++;
		}

		str1++;
	}

	*result = '\0';
}

void differences(const char* str1, const char* str2, char* result)
{
	if (!str1 || !str2 || !result)
		return;

	getDifferenceFromArr(str1, str2, result);
	getDifferenceFromArr(str2, str1, result);
}

//zad6
void caps(char* str)
{
	if (!str)
		return;


	if (*str >= 'a' && *str <= 'z')
		*str -= 'a' - 'A';
	str++;

	while (*str)
	{
		if(*(str-1)==' '&& *str >= 'a' && *str <= 'z')
			*str -= 'a' - 'A';
		str++;
	}
}

int main()
{
	char str[]=" am from fmi";

	caps(str);
	std::cout << str;
}