#include <iostream>
int dividerCount(int dividend)
{
	int count = 0;

	for (int i = 1; i <= dividend; i++)
	{
		if (dividend % i == 0)
			count++;
	}
	return count;
}
void findCouplesCount(int x, int n, int k, unsigned& couplesCount)
{
	for (int y = x; y <= n; y++)
	{
		bool areKTimesLess = k * dividerCount(x) * dividerCount(y) == x * y;

		if (areKTimesLess)
		{
			couplesCount++;
		}
	}

}

int main()
{
	int n, k;
	std::cin >> n >> k;

	if (n < 0 || k < 0)
	{
		std::cout << "Incorrect input!" << std::endl;
		return -1;
	}

	unsigned couplesCount = 0;

	for (int x = 1; x <= n;x++)
	{
		findCouplesCount(x, n, k, couplesCount);
	}

	std::cout << couplesCount << '\n';
}
