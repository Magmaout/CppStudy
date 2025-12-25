#include <windows.h>
#include <iostream>

int* createArray(int size);
void initArray(int* arr, int size, int value);
void printArray(int* arr, int size);
void deleteArray(int*& arr);
void pushBack(int*& arr, int& size, int value);

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	int size = 5;
	int* arr = createArray(size);

	initArray(arr, size, 1);
	printArray(arr, size);

	pushBack(arr, size, 10);
	printArray(arr, size);

	deleteArray(arr);
}

int* createArray(int size) {
	return new int[size];
}

void initArray(int* arr, int size, int value) {
	for (int i = 0; i < size; i++) arr[i] = value;
}

void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) std::cout << arr[i] << (i < size - 1 ? ", " : "\n");
}

void deleteArray(int*& arr) {
	delete[] arr;
}

void pushBack(int*& arr, int& size, int value) {
	int* temp = new int[size + 1];
	temp[0] = value;
	for (int i = 0; i < size; i++) temp[i + 1] = arr[i];
	delete[] arr;
	arr = temp;
	size++;
}
