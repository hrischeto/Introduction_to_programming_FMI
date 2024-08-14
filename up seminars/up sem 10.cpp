#include <iostream>
#pragma warning(disable:4996)

//basic string functions
size_t myStrlen(const char* str)
{
	if (!str)
		return 0;

	size_t len = 0;
	while (*str)
	{
		len++;
		str++;
	}

	return len;
}
void myStrcpy(char* dest, const char* source)
{
	if (!dest || !source)
		return;

	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}
int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
		return 0;

	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}

	return *first - *second;
}
void myStrcat(char* first, const char* second)
{
	if (!first || !second)
		return;

	first += myStrlen(first);

	myStrcpy(first, second);
}

bool isPrefix(const char* pattern, const char* text)
{
	if (!pattern || !text)
		return 0;

	while (*pattern && *text)
	{
		if (*pattern != *text)
			return false;

		text++;
		pattern++;
	}

	return *pattern == '\0';
}

bool searchInText(const char* text, const char* pattern)
{
	size_t textLen = myStrlen(text);
	size_t patternLen = myStrlen(pattern);

	while (textLen >= patternLen)
	{
		if (isPrefix(pattern, text))
			return true;

		textLen--;
		text++;
	}

	return false;
}

//zad1
void shiftLeft(char* str, size_t shiftWith)
{
	if (!str)
		return;

	while (*str)
	{
		*(str - shiftWith) = *str;
		str++;
	}
	*(str - shiftWith) = '\0';
}

void shiftRight(char* str, size_t shiftWith) 
{
	if (!str)
		return;

	size_t strSize = myStrlen(str);
	for (int i = strSize;i >= 0;i--)
	{
		str[i + shiftWith]  = str[i];
	}
}

void replace(char* text, const char* what,size_t whereLen)
{
	size_t whatLen = myStrlen(what);

	if (whatLen > whereLen)
		shiftRight(text+whereLen, whatLen-whereLen);
	else if (whatLen < whereLen)
		shiftLeft(text+whatLen, whereLen - whatLen);

	while (*what)
	{
		*text = *what;
		text++;
		what++;
	}
}

void replaceInText(char* text, const char* where, const char* what)
{
	if (!text || !where || !what)
		return;

	size_t whereLen = myStrlen(where);
	size_t textLen = myStrlen(text);
	size_t whatLen = myStrlen(what);

	while (textLen>=whereLen)
	{
		if (isPrefix(where, text))
		{
			replace(text, what, whereLen);
			where < what ? textLen += whatLen - whereLen : textLen -= whereLen - whatLen;
		}
		textLen--;
		text++;
	}
}

void zad1()
{
	char text[1024] = "I am the worst of the worst";
	char what[] = "best";
	char where[] = "worst";

	replaceInText(text, where, what);

	std::cout << text;
}

//zad2
void toUpper(char* str)
{
	if (!str)
		return;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= 'a' - 'A';
		}
		str++;
	}
}
void toLower(char* str)
{
	if (!str)
		return;

	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 'a' - 'A';
			
		}
		str++;
	}
}

//zad3
int wordCount(const char* str)
{
	if (!str)
		return 0;

	int count = 0;
	bool isInWord = 0;
	while(*str)
	{
		if (isInWord)
		{
			if (!(*str >= 'a' && *str <= 'z' || *str >= 'A' && *str <= 'Z'))
				isInWord = 0;
		}
		else
		{
			if (*str >= 'a' && *str <= 'z' || *str >= 'A' && *str <= 'Z')
			{
				count++;
				isInWord = 1;
			}
		}

		str++;
	}
	return count;
}

//zad4
void getFirstWord(const char* str, char* word, int& toShift)
{
	if (!str || !word)
		return;

	while (!(*str >= 'a' && *str <= 'z' || *str >= 'A' && *str <= 'Z')&&*str)
	{
		str++;
		toShift++;
	}

	while ((*str >= 'a' && *str <= 'z' || *str >= 'A' && *str <= 'Z')&&*str)
	{
		*word = *str;
		str++;
		word++;
		toShift++;
	}
	*word = '\0';
}

bool isPrefixNoCaps(const char* pattern, const char* text)
{
	if (!pattern || !text)
		return 0;

	while (*pattern && *text)
	{
		if (*pattern == *text ||
			*pattern >= 'A' && *pattern <= 'Z' && *pattern == *text - ('a' - 'A')||
			*pattern >= 'a' && *pattern <= 'z' && *pattern == *text + ('a' - 'A'))
		{
			text++;
			pattern++;
		}
		else
			return false;
	}

	return *pattern == '\0';
}

int getWordEncounters(const char* str, const char* word)
{
	if (!str || !word)
		return 0;

	int count = 0;
	bool isInWord = 0;

	while (*str)
	{
		if (isInWord)
		{
			if (!(*str >= 'a' && *str <= 'z' || *str >= 'A' && *str <= 'Z'))
				isInWord = 0;
		}
		else
		{
			if (*str >= 'a' && *str <= 'z' || *str >= 'A' && *str <= 'Z')
			{
				if (isPrefixNoCaps(word, str))
				count++;
				isInWord = 1;
			}
		}

		str++;
	}

	return count;
}

void mostCommonWord(const char* str)
{
	if (!str)
		return;

	char mostCommonWord[20];
	char currentWord[20];

	int maxEncounters = 0;
	int currentEncounters = 0;

	while (*str)
	{
		int toShift = 0;
		getFirstWord(str, currentWord, toShift);
		currentEncounters = getWordEncounters(str, currentWord);

		if (currentEncounters > maxEncounters)
		{
			maxEncounters = currentEncounters;
			myStrcpy(mostCommonWord, currentWord);
		}

		str += toShift;
	}

	std::cout << mostCommonWord;
}

//zad5
void lowestWord(const char* str)
{
		if (!str)
			return;

		char lowestWord[20];
		char currentWord[20];

		int toShift = 0;
		getFirstWord(str, lowestWord, toShift);
		toLower(lowestWord);
		str += toShift;

		while (*str)
		{
			toShift = 0;
			getFirstWord(str, currentWord, toShift);

			if(*currentWord)
			{
				toLower(currentWord);

				if (myStrcmp(currentWord, lowestWord) < 0)

					myStrcpy(lowestWord, currentWord);
			}

			str += toShift;
		}

		std::cout << lowestWord;
	
}

int main()
{
	std::cout << std::atoi("1234")+1;
}