#include <iostream>
#include <limits>
#include <cmath>
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

bool Transfer(CreditCard& C1, CreditCard& C2, float V)
{
	if (C1.Number == C2.Number)
	{
		std::cout << "Это одна и та же карта. Операция не проводится.\n";
		return false;
	}

	if (!std::isfinite(V) || V <= 0.0f)
	{
		std::cout << "Ошибка: сумма перевода должна быть больше нуля.\n";
		return false;
	}

	if (V > C1.Balance)
	{
		std::cout << "Ошибка: недостаточно средств на карте " << C1.Number
			<< ". Доступно: " << C1.Balance << " Р\n";
		return false;
	}

	C1.Balance -= V;
	C2.Balance += V;
	std::cout << "Перевод выполнен.\n";
	return true;
}

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif

	int firstNumber;
	float firstBalance;
	int secondNumber;
	float secondBalance;
	float amount;

	std::cout << "Введите номер карты C1: ";
	if (!(std::cin >> firstNumber))
	{
		std::cout << "Ошибка: номер карты должен быть целым числом.\n";
		return 1;
	}

	std::cout << "Введите баланс карты C1 (неотрицательное число): ";
	if (!(std::cin >> firstBalance) || !std::isfinite(firstBalance) || firstBalance < 0.0f)
	{
		std::cout << "Ошибка: баланс должен быть неотрицательным числом.\n";
		return 1;
	}

	std::cout << "Введите номер карты C2: ";
	if (!(std::cin >> secondNumber))
	{
		std::cout << "Ошибка: номер карты должен быть целым числом.\n";
		return 1;
	}

	std::cout << "Введите баланс карты C2 (неотрицательное число): ";
	if (!(std::cin >> secondBalance) || !std::isfinite(secondBalance) || secondBalance < 0.0f)
	{
		std::cout << "Ошибка: баланс должен быть неотрицательным числом.\n";
		return 1;
	}

	CreditCard C1(firstNumber, firstBalance);
	CreditCard C2(secondNumber, secondBalance);

	std::cout << "Введите сумму перевода с карты C1 на карту C2: ";
	if (!(std::cin >> amount))
	{
		std::cout << "Ошибка: сумма должна быть числом.\n";
		return 1;
	}

	Transfer(C1, C2, amount);
	std::cout << "Баланс карты " << C1.Number << ": " << C1.Balance << " Р\n"
		<< "Баланс карты " << C2.Number << ": " << C2.Balance << " Р\n";

	return 0;
}
