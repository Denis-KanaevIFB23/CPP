#include <stdio.h>
#include <locale.h>

static void wait_for_exit(void)
{
	int character;
	while ((character = getchar()) != '\n' && character != EOF)
	{
	}
	if (character != EOF)
	{
		printf("Press Enter to exit...");
		fflush(stdout);
		getchar();
	}
}

int main()
{
	int a;
	int b;
	printf("Enter A and B (B > A): ");
	if (scanf("%d %d", &a, &b) != 2 || b <= a)
	{
		printf("Invalid input: B must be greater than A.\n");
		wait_for_exit();
		return 1;
	}

	FILE *output = fopen("output.txt", "w");
	if (output == NULL)
	{
		printf("Could not open output.txt.\n");
		wait_for_exit();
		return 1;
	}

	for (int value = a;; ++value)
	{
		fprintf(output, "%lld\n", (long long)value * 3);
		if (value == b)
			break;
	}

	fclose(output);

	output = fopen("output.txt", "r");
	if (output == NULL)
	{
		printf("Could not open output.txt for reading.\n");
		wait_for_exit();
		return 1;
	}

	int number;
	int index = 1;
	while (fscanf(output, "%d", &number) == 1)
	{
		printf("%d. %d\n", index, number);
		++index;
	}

	fclose(output);
	wait_for_exit();
	return 0;
}
