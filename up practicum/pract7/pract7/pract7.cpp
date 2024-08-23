#include <iostream>

//zad1
int fromCharToInt(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 10;
}

char fromIntToChar(int n)
{
    if (n >= 0 && n <= 9)
        return n + '0';
    else if (n >= 10)
        return n + 'A' - 10;
}

void increment(char arr[], size_t size, unsigned k)
{

    for(int i=size-1;i>=0;i--)
    {
        int index = fromCharToInt(arr[i]);
        if (index < k - 1)
        {
            arr[i] = fromIntToChar(index + 1);
            break;
        }
        else if (index == k - 1)
            arr[i] = '0';
    }
}

void PRINT(const char arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

//zad2
void decrement(char arr[], size_t size, unsigned k)
{
    for (int i = size - 1;i >= 0;i--)
    {
        int index = fromCharToInt(arr[i]);

        if (index > 0)
        {
            arr[i] = fromIntToChar(index - 1);
            break;
        }
        else if (index == 0)
            arr[i] = fromIntToChar(k - 1);
    }
}

//zad3
void add(char ch1, char ch2, unsigned k, char result[], size_t resultSize)
{
    int index = fromCharToInt(ch1)+fromCharToInt(ch2) + fromCharToInt(result[resultSize - 1]);
    bool one = 0;
    if (index >= k)
    {
        index %= k;
        one = 1;
    }

    result[resultSize-1] = fromIntToChar(index);
    if (one)
        increment(result, resultSize - 1, k);
}

void addTwoNumbers(const char n1[], const char n2[], size_t size, unsigned k, char result[], size_t resultSize)
{

    for (int i = size - 1;i >= 0;i--)
    {
        add(n1[i], n2[i], k, result, resultSize - (size-i-1));
    }
}

//zad4
unsigned fromDecimalToRandomShort(unsigned num, unsigned k)
{
    unsigned result = 0;
    while (num)
    {
        (result *= 10) += num % k;
        num /= k;
    }

    return result;
}

unsigned reverse(unsigned num)
{
    unsigned result = 0;
    unsigned mult = 1;

    while (num)
    {
        result += (num % 10) * mult;
        mult *= 10;
        num /= 10;
    }

    return result;
}

bool isPalindrom(unsigned num, unsigned k)
{
    num = fromDecimalToRandomShort(num, k);

    return num == reverse(num);
}

//zad5
unsigned fromRandomToDecimal(const char from[], size_t fromSize, unsigned k)
{
    unsigned result = 0;

    for (int i = fromSize - 1, mult=1;i >= 0;i--,mult*=k)
    {
        int index = fromCharToInt(from[i]);
        result += index * mult;
    }

    return result;
}

bool areEqual(const char n1[], size_t size1, unsigned k, const char n2[], size_t size2, unsigned n)
{
    int num1 = fromRandomToDecimal(n1, size1, k);
    int num2 = fromRandomToDecimal(n2, size2, n);

    return num1 == num2;
}

int main()
{
    char n1[3] = { '9', };
    char n2[3] = { '1','1','1'};

    std::cout << areEqual(n1, 1, 10, n2, 3, 2);
}


