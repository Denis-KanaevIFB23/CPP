#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

class Bucket
{
public:
	int volume;
	int used;

	Bucket(int bucketVolume, int usedVolume)
		: volume(bucketVolume > 0 ? bucketVolume : 0),
		  used(usedVolume > 0 ? usedVolume : 0)
	{
		if (used > volume)
			used = volume;
	}

	void flush()
	{
		used = 0;
	}

	int fill(int amount)
	{
		if (amount <= 0)
			return 0;

		int accepted = amount;
		if (accepted > volume - used)
			accepted = volume - used;

		used += accepted;
		return amount - accepted;
	}
};

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif

	Bucket test_01(12, 3);
	std::cout << "1) " << test_01.volume << ", " << test_01.used << "\n";
	int rest = test_01.fill(14);
	std::cout << "2) " << test_01.used << ", " << rest << "\n";

	test_01.flush();
	rest = test_01.fill(8);
	std::cout << "3) " << test_01.used << ", " << rest << "\n";

	int volume;
	int used;
	std::cout << "\nВведите объем нового ведра и уже налитый объем: ";
	if (!(std::cin >> volume >> used) || volume < 0 || used < 0 || used > volume)
	{
		std::cout << "Некорректные значения.\n";
		return 1;
	}

	Bucket bucket(volume, used);
	int action;
	do
	{
		std::cout << "\nВедро: " << bucket.used << " из " << bucket.volume << " л\n"
			<< "1 - налить, 2 - опустошить, 0 - выход\nВыберите действие: ";
		if (!(std::cin >> action))
			return 1;

		if (action == 1)
		{
			int amount;
			std::cout << "Сколько литров налить? ";
			if (!(std::cin >> amount) || amount < 0)
			{
				std::cout << "Введите неотрицательное целое число.\n";
				return 1;
			}
			int notAccepted = bucket.fill(amount);
			std::cout << "Не поместилось: " << notAccepted << " л\n";
		}
		else if (action == 2)
		{
			bucket.flush();
			std::cout << "Ведро опустошено.\n";
		}
	} while (action != 0);

	return 0;
}
