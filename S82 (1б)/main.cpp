#include <cmath>
#include <iomanip>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

class CreditCard
{
public:
	explicit CreditCard(double balance) : balance_(balance) {}

	CreditCard& operator+(CreditCard& other)
	{
		if (this != &other)
		{
			balance_ += other.balance_;
			other.balance_ = 0.0;
		}
		return *this;
	}

	double Balance() const
	{
		return balance_;
	}

private:
	double balance_;
};

bool ReadBalance(const char* prompt, double& balance)
{
	std::cout << prompt;
	if (!(std::cin >> balance) || !std::isfinite(balance) || balance < 0.0)
	{
		std::cout << "Ошибка: введите неотрицательную сумму числом.\n";
		return false;
	}
	return true;
}

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif

	CreditCard card1(0.0);
	CreditCard card2(0.0);
	double balance1;
	double balance2;

	if (!ReadBalance("Введите баланс первой карты: ", balance1) ||
		!ReadBalance("Введите баланс второй карты: ", balance2))
		return 1;

	card1 = CreditCard(balance1);
	card2 = CreditCard(balance2);

	std::cout << std::fixed << std::setprecision(2)
		<< "До операции: первая карта = " << card1.Balance()
		<< ", вторая карта = " << card2.Balance() << '\n';

	card1 + card2;

	std::cout << "После операции card1 + card2:\n"
		<< "Баланс первой карты: " << card1.Balance() << '\n'
		<< "Баланс второй карты: " << card2.Balance() << '\n';

	return 0;
}
