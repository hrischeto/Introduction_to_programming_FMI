#include <iostream>

//zad2 
bool contains(int num, int k)
{
    if (num % 10 == k)
        return true;

    return contains(num / 10, k);
}

//zad3
int sumNumber(int num)
{
    if (num == 0)
        return 0;

    return num % 10 + sumNumber(num / 10);
}

//zad4
bool increasing(const int* seq, size_t n)
{
    if (n == 1)
        return true;

    return seq[0] <= seq[1] && increasing(seq + 1, n - 1);
}

//zad5
bool hasDelimiter(int num, int del)
{
    if (del == 1)
        return false;

    return num % del==0 || hasDelimiter(num, del - 1);

}
bool isPrime(int n)
{
    return !hasDelimiter(n, sqrt(n));
}

//zad6
void addNumber(int* arr, int size, int n)
{
    if (arr[size - 1] < n||size==1)
        arr[size] = n;
    else 
    {
        arr[size] = arr[size - 1];
        addNumber(arr, size - 1, n);
    }

}

//zad7
unsigned int reverse(unsigned int n)
{
    unsigned reversedNumber = 0;

    while (n != 0)
    {
        unsigned int lastDigit = n % 10;
        (reversedNumber *= 10) += lastDigit;
        n /= 10; //removes the last digit
    }
    return reversedNumber;

}

bool isPalindrome(unsigned int n)
{
    return n == reverse(n);
}

bool couldBePalindrome(int n, int del)
{
    if (n < 10)
        return false;

    return isPalindrome(n) || couldBePalindrome(n / 10,del/10) || couldBePalindrome(n % del,del/10);
}

//zad8
int factoriel(int n)
{
    if (n == 0)
        return 1;

    return n * factoriel(n - 1);
}

int binomeCoef(int n, int k)
{
    return factoriel(n) / (factoriel(k) * factoriel(n - k));
}

//zad9
int sumArrTail(const int* arr, size_t size, int sum = 0)
{
    if (size == 0)
        return sum;
    return sumArrTail(arr + 1, size - 1, sum + arr[0]);
}

int biggerThanAverage(const int* arr, size_t size)
{
    if (size == 1)
        return arr[size - 1];

    int average = sumArrTail(arr + 1, size - 1) / (size - 1);
    if (arr[0] > average)
        return arr[0];
    else
        return biggerThanAverage(arr + 1, size - 1);

}

//zad10
void printPalindromes(int start, int end)
{
    if (start > end)
    {
        std::cout << std::endl;
        return;
    }

    if (isPalindrome(start))
        std::cout << start << " ";

        printPalindromes(start + 1, end);
}
   
void printPrime(int start, int end)
{
    if (start > end)
    {
        std::cout << std::endl;
        return;
    }

    if (isPrime(start))
        std::cout << start << " ";

    printPrime(start + 1, end);
}

bool isSquare(int num)
{
    int square = sqrt(num);

    return (square * square) == num;
}

void printSquares(int start, int end)
{
    if (start > end)
    {
        std::cout << std::endl;
        return;
    }

    if (isSquare(start))
        std::cout << start << " ";

    printSquares(start + 1, end);
}

void printCriteria(int start, int end)
{
    printPalindromes(start, end);
    printPrime(start, end);
    printSquares(start, end);
}

int main()
{
    printCriteria(100, 110);
}