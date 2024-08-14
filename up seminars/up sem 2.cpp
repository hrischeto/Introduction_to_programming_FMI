#include <iostream>

const double PI = 3.14;
int main()
{
	char figure;
	std::cin >> figure;

	double area = 0;
	if (figure == 's')
	{
		int side = 0;
		std::cin >> side;
		area = side * side;
	}

	else if (figure == 'r')
	{
		int sideA = 0, sideB = 0;
		std::cin >> sideA >> sideB;
		area = sideA * sideB;
	}

	else if (figure == 't') {

		int side = 0, height = 0;
		std::cin >> side >> height;
		area = (side * height) / 2;
	}
	else if (figure == 'c')
	{
		int radious = 0;
		std::cin >> radious;
		area = radious * radious * PI;
	}
	else
		std::cout << " Invalid Input";
	

	std::cout << area;
}