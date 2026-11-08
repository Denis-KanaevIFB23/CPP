#include <iostream>

double squared_sum(double first, double second)
{
	return (first + second) * (first + second);
}

int main()
{
	double first;
	double second;
	std::cout << "Enter two fractional numbers: ";
	if (!(std::cin >> first >> second)) {
		std::cout << "Invalid input.\n";
		return 1;
	}

	std::cout << squared_sum(first, second) << "\n";
	return 0;
}
