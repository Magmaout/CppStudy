#include <windows.h>
#include <iostream>

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand((int)time(NULL));

	const size_t size = 10;
	int arr[size], min, max;

	std::cout << "Случайные числа: ";
	for (size_t i = 0; i < size; i++) {
		arr[i] = rand() % 20;
		if (i > 0) {
			if (arr[i] < min) min = arr[i];
			else if (arr[i] > max) max = arr[i];
		} else min = max = arr[i];
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n\nМинимальное число: " << min;
	std::cout << "\nМаксимальное число: " << max;

	return 0;
}