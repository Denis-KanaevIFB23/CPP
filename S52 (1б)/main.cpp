#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

void print(int value)
{
	std::cout << value << '\n';
}

void print(float value)
{
	std::cout << value << '\n';
}

void print(char value)
{
	std::cout << value << '\n';
}

void print(int first, int second)
{
	std::cout << first << ", " << second << '\n';
}

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif

	int integerValue;
	float floatValue;
	char characterValue;
	int firstInteger;
	int secondInteger;

	std::cout << "Введите целое число (например, 42): ";
	std::cin >> integerValue;
	print(integerValue);

	std::cout << "Введите дробное число через точку (например, 3.14): ";
	std::cin >> floatValue;
	print(floatValue);

	std::cout << "Введите один символ (например, A): ";
	std::cin >> characterValue;
	print(characterValue);

	std::cout << "Введите два целых числа через пробел (например, 10 20): ";
	std::cin >> firstInteger >> secondInteger;
	print(firstInteger, secondInteger);
	return 0;
}
