// fn9MI0600381_d2_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
* @task 1
*
*/

#include <iostream>
constexpr size_t MAX_SIZE = 64;
constexpr size_t SIZE_OF_CHAR = 8;

int myStrLen(const char* str)
{
	if (!str)
		return 0;
	int len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}

int getSizeOfNewString(const  char* input)
{
	if (!input)
		return 0;
	
	return myStrLen(input) * 2 + 1;
}

void getCodingSymbolInBinary(char& input, int temp[])
{
	int currentBit = 0;
	int mask = 1;

	for (int i = SIZE_OF_CHAR - 1;i >= 0;i -= 2)
	{
		currentBit = input & mask;

		if (currentBit)
		{
			temp[i - 1] = 1;
		}
		else
		{
			temp[i] = 1;
		}

		input >>= 1;
	}

	return;
}

int getASCIICode(int* binaryRepresentation)
{
	if (!binaryRepresentation)
		return-1;

	int asciiCode = 0;
	int powerOfTwo = 1;
	for (int i = SIZE_OF_CHAR - 1; i >= 0; i--)
	{
		asciiCode += binaryRepresentation[i] * powerOfTwo;
		powerOfTwo <<= 1;

	}

	return asciiCode;
}

char* codeString(char* input)
{
	if (!input)
			return nullptr;

	int strSize = getSizeOfNewString(input);
	char* codedString = new char[strSize];

	int mask = 1;

	while (*input)
	{
		int secondHalfOfSymbol[SIZE_OF_CHAR] = { 0 };
		getCodingSymbolInBinary(*input, secondHalfOfSymbol);

		int firstHalfOfSymbol[SIZE_OF_CHAR] = { 0 };
		getCodingSymbolInBinary(*input, firstHalfOfSymbol);

		*codedString = getASCIICode(firstHalfOfSymbol);
		codedString++;
		*codedString = getASCIICode(secondHalfOfSymbol);
		codedString++;

		input++;
	}

	*codedString = '\0';
	codedString -= strSize-1;
	return codedString;
}
int main()
{
	char input[MAX_SIZE];
	std::cin.getline(input, 64);
	char* inputPtr = input;

	char* codedString=codeString(inputPtr);

	if (!codedString)
	{
		std::cout << "Incorrect input" << std::endl;
		delete[] codedString;
		return -1;
	}
	std::cout << codedString << std::endl;

	delete[] codedString;
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
