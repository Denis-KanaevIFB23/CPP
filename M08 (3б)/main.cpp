#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif

double get_angle(double a, double b, double c)
{
	if (!std::isfinite(a) || !std::isfinite(b) || !std::isfinite(c)
		|| !(a > 0) || !(b > 0) || !(c > 0))
	{
		throw std::invalid_argument("Длины сторон должны быть положительными числами.");
	}
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		throw std::invalid_argument("Стороны не образуют треугольник.");
	}

	const double cosAngle = (b * b + c * c - a * a) / (2.0 * b * c);
	const double radiansToDegrees = 180.0 / std::acos(-1.0);
	return std::acos(cosAngle) * radiansToDegrees;
}

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif

	double a, b, c;

	std::cout << "Введите длину первой стороны (напротив искомого угла): ";
	if (!(std::cin >> a))
	{
		std::cerr << "Ошибка: введите число.\n";
		return 1;
	}

	std::cout << "Введите длины двух остальных сторон: ";
	if (!(std::cin >> b >> c))
	{
		std::cerr << "Ошибка: введите два числа.\n";
		return 1;
	}

	try
	{
		std::cout << std::fixed << std::setprecision(6)
			<< "Угол напротив первой стороны: " << get_angle(a, b, c) << " градусов\n";
	}
	catch (const std::invalid_argument& error)
	{
		std::cerr << "Ошибка: " << error.what() << '\n';
		return 1;
	}

	return 0;
}
