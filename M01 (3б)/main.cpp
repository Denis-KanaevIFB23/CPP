#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif

	std::cout << "Таблица Пифагора (1-10):\n\t";
	for (int column = 1; column <= 10; ++column)
		std::cout << column << '\t';
	std::cout << '\n';

	for (int row = 1; row <= 10; ++row)
	{
		std::cout << row << '\t';
		for (int column = 1; column <= 10; ++column)
			std::cout << row * column << '\t';
		std::cout << '\n';
	}

	return 0;
}
