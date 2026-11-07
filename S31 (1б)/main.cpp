#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

static void print_text(const char *text)
{
#ifdef _WIN32
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	wchar_t wide_text[128];

	if (GetConsoleMode(output, &mode)) {
		int wide_length = MultiByteToWideChar(CP_UTF8, 0, text, -1, wide_text, 128);
		if (wide_length > 0) {
			DWORD written;
			if (WriteConsoleW(output, wide_text, (DWORD)(wide_length - 1), &written, NULL)) {
				return;
			}
		}
	}
#endif
	printf("%s", text);
}

static void wait_for_enter(void)
{
	int character;

	print_text("Нажмите Enter для выхода...");
	while ((character = getchar()) != '\n' && character != EOF) {
	}
	if (character != EOF) {
		getchar();
	}
}

int main(void)
{
	const char *digit_names[] = {
		"ноль", "один", "два", "три", "четыре",
		"пять", "шесть", "семь", "восемь", "девять"
	};
	int number;

	print_text("Введите цифру от 0 до 9: ");
	if (scanf("%d", &number) != 1 || number < 0 || number > 9) {
		print_text("Некорректный ввод.\r\n");
		wait_for_enter();
		return 1;
	}

	print_text(digit_names[number]);
	print_text("\r\n");
	wait_for_enter();
	return 0;
}
