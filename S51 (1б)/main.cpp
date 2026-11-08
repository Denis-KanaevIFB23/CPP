#include <iostream>
#include <string>

void reverse(const std::string& text)
{
	for (auto character = text.rbegin(); character != text.rend(); ++character) {
		std::cout << *character;
	}
}

int main()
{
	std::string text;
	std::cout << "Enter a word: ";
	std::cin >> text;
	reverse(text);
	std::cout << '\n';
	return 0;
}
