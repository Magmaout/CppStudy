#include <windows.h>
#include <iostream>

template<class T> void createArray(T*& arr, int size);
template<class T> void initArray(T* arr, int size, T element);
template<class T> void printArray(T* arr, int size);
template<class T> void deleteArray(T*& arr);
template<class T> void pushBack(T*& arr, int& size, T element);
template<class T> void putAt(T*& arr, int& size, int index, T element);
template<class T> void removeAt(T*& arr, int& size, int index);

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	int size = 5;
	int* arr;
	createArray(arr, size);

	initArray(arr, size, 1);
	printArray(arr, size);

	pushBack(arr, size, 5);
	printArray(arr, size);

	putAt(arr, size, 4, 7);
	printArray(arr, size);

	removeAt(arr, size, 0);
	printArray(arr, size);

	deleteArray(arr);
}

template<class T> void createArray(T*& arr, int size) {
	arr = new T[size];
}

template<class T> void initArray(T* arr, int size, T element) {
	for (size_t i = 0; i < size; i++) arr[i] = element;
}

template<class T> void printArray(T* arr, int size) {
	for (size_t i = 0; i < size; i++) std::cout << arr[i] << (i < size - 1 ? ", " : "\n");
}

template<class T> void deleteArray(T*& arr) {
	delete[] arr;
	arr = NULL;
}

template<class T> void pushBack(T*& arr, int& size, T element) {
	T* temp = new T[size + 1];
	temp[0] = element;
	for (size_t i = 0; i < size; i++) temp[i + 1] = arr[i];
	delete[] arr;
	arr = temp;
	size++;
}

template<class T> void putAt(T*& arr, int& size, int index, T element) {
	if (index < 0 || index > size) return;
	T* temp = new T[size + 1];
	temp[index] = element;
	for (size_t i = 0; i < size; i++) {
		if (i < index) temp[i] = arr[i];
		else temp[i + 1] = arr[i];
	}
	delete[] arr;
	arr = temp;
	size++;
}

template<class T> void removeAt(T*& arr, int& size, int index) {
	if (index < 0 || index > size) return;
	T* temp = new T[size - 1];
	for (size_t i = 0; i < size; i++) {
		if (i < index) temp[i] = arr[i];
		else if (i > index) temp[i - 1] = arr[i];
	}
	delete[] arr;
	arr = temp;
	size--;
}