#include <stdio.h>
#include <locale.h>

int main()
{
	for (int number = 0; number <= 100; ++number)
	{
		if (number % 3 == 0)
		{
			printf("%d\t", number);
		}
	}
	printf("\nPress Enter to exit...");
	getchar();
}
