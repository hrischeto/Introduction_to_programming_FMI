#include <iostream>
void zad1() 
{
	int a = 0;
	std::cin >> a;
	std::cout << !((a % 10) % 2);
}

void zad2()
{
	int a = 0;
	std::cin >> a;

	int result = 0;
	result += ((a % 10) * 100);
	a /= 10;
	
	result += ((a % 10) * 10);
	a /= 10;

	result += a % 10;
	a /= 10;

	std::cout << ++result;
}

void zad3()
{
	char ch = '\0';
	std::cin >> ch;
	bool isVowel=ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i'
		|| ch == 'A' || ch == 'E' || ch == 'O' || ch == 'U' || ch == 'I';

	std::cout << isVowel;
}

void zad7() {
	int amount = 0;
	std::cin >> amount;
	
	int hundredsCount = 0;
	hundredsCount = amount / 100;
	amount %= 100;

	int fiftiesCount = amount / 50;
	amount %= 50;

	int twentiesCount = amount / 20;
	amount %= 20;

	int tensCount = amount / 10;
	amount %= 10;

	int fivesCount = amount / 5;
	amount %= 5;

	int twosCount = amount / 2;
	amount %= 2;

	std::cout << hundredsCount << "x100lv " << fiftiesCount << "x50lv " << twentiesCount << "x20lv " << tensCount << "x10lv "
		<< fivesCount << "x5lv " << twosCount << "x2lv " << amount << "x1lv. " << std::endl;
}

void zad8()
{
	int a=0, b = 0;

	std::cin >> a >> b;
	bool isBigger = a > b;

	std::cout << a * isBigger + b * (!isBigger);
}
int main() {
	zad8();
}