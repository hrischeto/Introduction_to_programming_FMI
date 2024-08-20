#include <iostream>

const int maxCitizensQuestioned = 1000;
constexpr size_t size = maxCitizensQuestioned;



void fillArr(int arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		std::cin >> arr[i];
	}
}

void deleteElements(int arr[], int n, int toRemove)
{
	for (int j = 0;j < n;j++)
	{
		if (arr[j] == toRemove)
			arr[j] = -1;
	}
}

void countSameNumbers(int arr[], int n, int& sameNumberCount, int i)
{
	for (int j = 0;j < n;j++)
	{
		if (arr[j] == arr[i])
			sameNumberCount++;
	}
}

int minimumPeople(int arr[], int len)
{
	int minimumPeopleCount = 0;
	for (int i = 0;i < len;i++)
	{
		if (arr[i] == -1)
			continue;

		int sameNumberCount = 0;

		countSameNumbers(arr, len, sameNumberCount, i);

		minimumPeopleCount += (sameNumberCount / (arr[i] + 1)) * (arr[i] + 1);

		minimumPeopleCount += sameNumberCount % (arr[i] + 1) == 0 ? 0 : (arr[i] + 1);

		deleteElements(arr, len, arr[i]);

	}
	return minimumPeopleCount;
}

int main()
{
	int len;
	std::cin >> len;
	if (len < 0 || len>maxCitizensQuestioned)
	{
		std::cout << "Incorrect input!" << std::endl;
		return -1;
	}

	int arr[size];
	fillArr(arr, len);
	for (int i = 0;i < len;i++)
	{
		std::cin >> arr[i];
		if (arr[i] < 0 || arr[i] > maxCitizensQuestioned)
		{
			std::cout << "Invalid input\n";
			return -1;
		}
	}

	std::cout << minimumPeople(arr, len) << std::endl;

}