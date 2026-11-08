#include <iostream>
#include <cmath>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif

double regularPolygonArea(double side, int sides)
{
	const double pi = std::acos(-1.0);
	return sides * side * side / (4.0 * std::tan(pi / sides));
}

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif

	double side;
	int sides;

	std::cout << "Введите длину стороны A: ";
	if (!(std::cin >> side) || side <= 0)
	{
		std::cerr << "Ошибка: длина стороны должна быть положительным числом.\n";
		return 1;
	}

	std::cout << "Введите число сторон N (не менее 3): ";
	if (!(std::cin >> sides) || sides < 3)
	{
		std::cerr << "Ошибка: число сторон должно быть целым числом не менее 3.\n";
		return 1;
	}

	std::cout << std::fixed << std::setprecision(6)
		<< "Площадь правильного " << sides << "-угольника: "
		<< regularPolygonArea(side, sides) << '\n';

	return 0;
}
