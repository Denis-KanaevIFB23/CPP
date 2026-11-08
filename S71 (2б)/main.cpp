#include <iostream>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

class CreditCard
{
public:
	int Number;
	float Balance;

	CreditCard(int number, float balance)
		: Number(number), Balance(balance >= 0.0f ? balance : 0.0f)
	{
	}

	bool Put(float value)
	{
		if (value <= 0.0f)
			return false;

		Balance += value;
		return true;
	}

	bool Take(float value)
	{
		if (value <= 0.0f || value > Balance)
			return false;

		Balance -= value;
		return true;
	}
};

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif

	CreditCard firstCC(1234, 50.0f);
	CreditCard* cardPtr = &firstCC;

	std::cout << "Карта " << cardPtr->Number << " создана.\n";
	while (true)
	{
		std::cout << "\nБаланс: " << cardPtr->Balance << " Р\n"
			<< "Выберите действие:\n"
			<< "1 - пополнить карту\n"
			<< "2 - снять деньги\n"
			<< "0 - выйти\n"
			<< "Введите номер действия: ";

		int action;
		if (!(std::cin >> action))
		{
			if (std::cin.eof())
				break;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка: введите 0, 1 или 2.\n";
			continue;
		}

		if (action == 0)
			break;
		if (action != 1 && action != 2)
		{
			std::cout << "Такого действия нет. Выберите 0, 1 или 2.\n";
			continue;
		}

		float amount;
		std::cout << (action == 1 ? "Введите сумму пополнения (больше 0): "
			: "Введите сумму снятия (больше 0): ");
		if (!(std::cin >> amount))
		{
			if (std::cin.eof())
				break;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка: введите сумму числом.\n";
			continue;
		}

		if (action == 1)
		{
			if (cardPtr->Put(amount))
				std::cout << "Карта пополнена. Новый баланс: " << cardPtr->Balance << " Р\n";
			else
				std::cout << "Сумма должна быть больше нуля. Попробуйте снова.\n";
		}
		else if (amount > cardPtr->Balance)
		{
			std::cout << "Недостаточно средств. Доступно: " << cardPtr->Balance << " Р\n";
		}
		else if (cardPtr->Take(amount))
		{
			std::cout << "Деньги сняты. Новый баланс: " << cardPtr->Balance << " Р\n";
		}
		else
		{
			std::cout << "Сумма должна быть больше нуля. Попробуйте снова.\n";
		}
	}

	std::cout << "Работа завершена. Остаток: " << cardPtr->Balance << " Р\n";

	return 0;
}
