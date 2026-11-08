#include <iostream>
#include <limits>
#include <string>
#include <cstdint>
#ifdef _WIN32
#include <windows.h>
#endif

class TextString
{
public:
	explicit TextString(std::string value) : value_(value) {}

	TextString& operator++()
	{
		value_ = Shift(value_, 1);
		return *this;
	}

	TextString operator++(int)
	{
		TextString previous = *this;
		++(*this);
		return previous;
	}

	TextString& operator--()
	{
		value_ = Shift(value_, -1);
		return *this;
	}

	TextString operator--(int)
	{
		TextString previous = *this;
		--(*this);
		return previous;
	}

	const std::string& Value() const
	{
		return value_;
	}

private:
	static std::string Shift(const std::string& value, int offset)
	{
		std::string result;
		for (std::size_t i = 0; i < value.size();)
		{
			const unsigned char first = static_cast<unsigned char>(value[i]);
			std::uint32_t codePoint = 0;
			std::size_t length = 1;

			if ((first & 0xE0) == 0xC0 && i + 1 < value.size())
			{
				codePoint = ((first & 0x1F) << 6) |
					(static_cast<unsigned char>(value[i + 1]) & 0x3F);
				length = 2;
			}
			else if ((first & 0xF0) == 0xE0 && i + 2 < value.size())
			{
				codePoint = ((first & 0x0F) << 12) |
					((static_cast<unsigned char>(value[i + 1]) & 0x3F) << 6) |
					(static_cast<unsigned char>(value[i + 2]) & 0x3F);
				length = 3;
			}
			else if ((first & 0xF8) == 0xF0 && i + 3 < value.size())
			{
				codePoint = ((first & 0x07) << 18) |
					((static_cast<unsigned char>(value[i + 1]) & 0x3F) << 12) |
					((static_cast<unsigned char>(value[i + 2]) & 0x3F) << 6) |
					(static_cast<unsigned char>(value[i + 3]) & 0x3F);
				length = 4;
			}
			else
			{
				codePoint = first;
			}

			if (offset > 0 && codePoint < 0x10FFFF)
			{
				++codePoint;
				if (codePoint == 0xD800)
					codePoint = 0xE000;
			}
			else if (offset < 0 && codePoint > 0)
			{
				--codePoint;
				if (codePoint == 0xDFFF)
					codePoint = 0xD7FF;
			}

			if (codePoint <= 0x7F)
				result += static_cast<char>(codePoint);
			else if (codePoint <= 0x7FF)
			{
				result += static_cast<char>(0xC0 | (codePoint >> 6));
				result += static_cast<char>(0x80 | (codePoint & 0x3F));
			}
			else if (codePoint <= 0xFFFF)
			{
				result += static_cast<char>(0xE0 | (codePoint >> 12));
				result += static_cast<char>(0x80 | ((codePoint >> 6) & 0x3F));
				result += static_cast<char>(0x80 | (codePoint & 0x3F));
			}
			else
			{
				result += static_cast<char>(0xF0 | (codePoint >> 18));
				result += static_cast<char>(0x80 | ((codePoint >> 12) & 0x3F));
				result += static_cast<char>(0x80 | ((codePoint >> 6) & 0x3F));
				result += static_cast<char>(0x80 | (codePoint & 0x3F));
			}
			i += length;
		}
		return result;
	}

	std::string value_;
};

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif

	std::string input;
	std::cout << "Введите текстовую строку: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << "Ошибка: не удалось прочитать строку.\n";
		return 1;
	}

	TextString text(input);
	std::cout << "Выберите операцию:\n"
		<< "1 - префиксный ++\n"
		<< "2 - постфиксный ++\n"
		<< "3 - префиксный --\n"
		<< "4 - постфиксный --\n"
		<< "Ваш выбор: ";

	int choice;
	if (!(std::cin >> choice) || choice < 1 || choice > 4)
	{
		std::cout << "Ошибка: выберите число от 1 до 4.\n";
		return 1;
	}

	TextString expressionResult(input);
	switch (choice)
	{
	case 1:
		expressionResult = ++text;
		break;
	case 2:
		expressionResult = text++;
		break;
	case 3:
		expressionResult = --text;
		break;
	case 4:
		expressionResult = text--;
		break;
	}

	std::cout << "Результат выражения: " << expressionResult.Value() << '\n'
		<< "Строка после операции: " << text.Value() << '\n';

	return 0;
}
