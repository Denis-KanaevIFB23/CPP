#include <iostream>

void sort(int a[10])
{
	for (int i = 0; i < 9; ++i) {
		int largest = i;
		for (int j = i + 1; j < 10; ++j) {
			if (a[j] > a[largest]) {
				largest = j;
			}
		}

		int temporary = a[i];
		a[i] = a[largest];
		a[largest] = temporary;
	}
}

int main()
{
	int a[10] = { 1, 8, 3, 6, 5, 4, 9, 2, 8, 12 };
	sort(a);

	for (int i = 0; i < 10; ++i) {
		std::cout << a[i] << (i == 9 ? '\n' : ' ');
	}
	return 0;
}
