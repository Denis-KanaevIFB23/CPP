#include <stdio.h>
#include <locale.h>

int main()
{
	int number = 1;
	int sum = 0;
	while (number <= 1000)
	{
		printf("%d\t", number);
		if (number % 7 == 0)
		{
			sum += number;
		}
		number += 4;
	}
	printf("Sum: %d\n", sum);
	printf("\nPress Enter to exit...");
	getchar();
}
