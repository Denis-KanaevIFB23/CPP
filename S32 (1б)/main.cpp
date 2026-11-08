#include <stdio.h>
#include <cstring>
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
	char text[256];

	print_text("Введите строку: ");
	if (fgets(text, sizeof(text), stdin) == NULL) {
		print_text("Не удалось прочитать строку.\r\n");
		wait_for_enter();
		return 1;
	}

	std::size_t length = std::strlen(text);
	if (length > 0 && text[length - 1] == '\n') {
		text[--length] = '\0';
	}

	for (char *character = text; character < text + length; ++character) {
		if (*character >= 'a' && *character < 'z') {
			++*character;
		} else if (*character == 'z') {
			*character = 'a';
		} else if (*character >= 'A' && *character < 'Z') {
			++*character;
		} else if (*character == 'Z') {
			*character = 'A';
		}
	}

	print_text(text);
	print_text("\r\n");
	wait_for_enter();
	return 0;
}
