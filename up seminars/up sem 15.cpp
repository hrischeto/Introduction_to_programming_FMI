#include <iostream>
using namespace std;

void genBoolVectors(bool* arr, size_t size, unsigned beginIndex = 0)
{
    if (beginIndex == size)
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    arr[beginIndex] = 0;
    genBoolVectors(arr, size, beginIndex + 1);
    arr[beginIndex] = 1;
    genBoolVectors(arr, size, beginIndex + 1);
}


//backtracking
const size_t rows = 6;
const size_t colls = 5;

bool validCoordinates(int x, int y)
{
    return x >= 0 && y >= 0 && x < rows && y < colls;
}

bool findPathRec(const char field[rows][colls], bool visited[rows][colls], int currentX, int currentY, int destX, int destY)
{
    if (!validCoordinates(currentX, currentY) || field[currentX][currentY] != ' ' || visited[currentX][currentY])
        return false;

    visited[currentX][currentY] = true;

    if (currentX == destX && currentY == destY)
        return true;

    bool foundPath = findPathRec(field, visited, currentX + 1, currentY, destX, destY) ||
        findPathRec(field, visited, currentX, currentY + 1, destX, destY) ||
        findPathRec(field, visited, currentX - 1, currentY, destX, destY) ||
        findPathRec(field, visited, currentX, currentY - 1, destX, destY);
    if (!foundPath)
        visited[currentX][currentY] = false;
    return foundPath;
}

void printPath(const char field[rows][colls], const bool visited[rows][colls])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colls; j++)
        {
            if (visited[i][j])
                cout << "| 1 |";
            else
                cout << "| " << field[i][j] << " |";
        }
        cout << endl;
    }
}

bool findPath(const char field[rows][colls], int startX, int startY, int destX, int destY)
{
    bool visited[rows][colls]{ false };
    bool containsPath = findPathRec(field, visited, startX, startY, destX, destY);

    if (containsPath)
        printPath(field, visited);
    else
        cout << "No path!" << endl;
    return containsPath;
}

void backtracking()
{
    char field[rows][colls]
    {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', ' ', 'X', 'X'},
        {'X', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', ' '}

    };

    findPath(field, 3, 0, 5, 4);

    return;
}

//memoization
unsigned fibb_rec(unsigned n, unsigned* cache)
{

    if (n <= 1)
        return 1;

    if (cache[n] != 0)
        return cache[n];
    else
    {
        int current = fibb_rec(n - 1, cache) + fibb_rec(n - 2, cache);
        cache[n] = current;
        return current;
    }
}

unsigned fibb(unsigned n)
{
    unsigned* cache = new unsigned[n + 1] {0};
    unsigned res = fibb_rec(n, cache);
    delete[] cache;
    return res;
}

int main()
{
    char field[rows][colls]
    {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', ' ', 'X', 'X'},
        {'X', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', ' '}

    };

    findPath(field, 3, 0, 5, 4);

    return 0;
}