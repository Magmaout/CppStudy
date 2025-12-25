#include <windows.h>
#include <iostream>
#include <string>

class MyClass {
	public:
		int* data;

		MyClass(size_t size) {
			this->size = size;
			this->data = new int[size];

			for (size_t i = 0; i < size; i++) this->data[i] = i;

			std::cout << "Вызов обычного конструктора " << this << '\n';
		}

		MyClass(const MyClass& other) {
			this->size = other.size;
			this->data = new int[other.size];

			for (size_t i = 0; i < other.size; i++) this->data[i] = other.data[i];

			std::cout << "Вызов конструктора копирования " << this << '\n';
		}

		MyClass& operator = (const MyClass& other) {
			std::cout << "Вызов оператора присваивания " << this << '\n';
			this->size = other.size;
			if (this->data != nullptr) delete[] this->data;

			this->data = new int[other.size];
			for (size_t i = 0; i < other.size; i++) this->data[i] = other.data[i];

			return* this;
		}

		bool operator == (const MyClass& other) {
			std::cout << "Вызов оператора равенства " << this << '\n';
			
			if (this->data == nullptr && other.data == nullptr) return true;
			if (this->size != other.size) return false;
			for (size_t i = 0; i < other.size; i++) if (this->data[i] != other.data[i]) return false;
			return true;
		}

		bool operator != (const MyClass& other) {
			std::cout << "Вызов оператора неравенства " << this << '\n';

			if (this->data == nullptr && other.data == nullptr) return false;
			if (this->size != other.size) return true;
			for (size_t i = 0; i < other.size; i++) if (this->data[i] != other.data[i]) return true;
			return false;
		}

		~MyClass() {
			std::cout << "Вызов класса после завершения кода " << this << '\n';
			delete[] data;
		}

	private:
		size_t size;
};

void voidTest(MyClass clazz) {
	std::cout << "Вызов функции voidTest\n";
}

MyClass classTest() {
	std::cout << "Вызов функции classTest\n";
	MyClass temp(2);
	return temp;
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	size_t sizeA = 6, sizeB = 3, sizeC = 8;

	MyClass a(sizeA);
	MyClass b(sizeB);
	MyClass c(sizeC);

	std::cout << "Элементы А: ";
	for (size_t i = 0; i < sizeA; i++) {
		a.data[i] = rand() % 10;
		std::cout << a.data[i] << (i < sizeA - 1 ? ", " : "\n\n");
	}
	std::cout << "Элементы B: ";
	for (size_t i = 0; i < sizeB; i++) {
		b.data[i] = rand() % 10;
		std::cout << b.data[i] << (i < sizeB - 1 ? ", " : "\n\n");
	}
	std::cout << "Элементы C: ";
	for (size_t i = 0; i < sizeC; i++) {
		c.data[i] = rand() % 10;
		std::cout << c.data[i] << (i < sizeC - 1 ? ", " : "\n\n");
	}

	//	Перегрузка оператора присваивания в классе!

	a = c = b;

	std::cout << "Новые элементы А: ";
	for (size_t i = 0; i < sizeB; i++) std::cout << a.data[i] << (i < sizeB - 1 ? ", " : "\n\n");

	//	Перегрузка оператора равенства и неравенства в классе!

	std::cout << "Равенство элементов А и C: " << (a == c ? "TRUE" : "FALSE") << "\n\n";
	std::cout << "Неавенство элементов А и C: " << (a != c ? "TRUE" : "FALSE") << "\n\n";
}