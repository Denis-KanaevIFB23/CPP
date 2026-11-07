#include <stdio.h>
#include <locale.h>

int main()
{
	int a;
	int b;
	printf("Enter A and B (B > A): ");
	if (scanf("%d %d", &a, &b) != 2 || b <= a)
	{
		printf("Invalid input: B must be greater than A.\n");
		return 1;
	}

	FILE *output = fopen("output.txt", "w");
	if (output == NULL)
	{
		printf("Could not open output.txt.\n");
		return 1;
	}

	for (int value = a;; ++value)
	{
		fprintf(output, "%lld\n", (long long)value * 3);
		if (value == b)
			break;
	}

	fclose(output);
	return 0;
}
