#include <functional>
#include <windows.h>
#include <iostream>
#include <string>

int task1(); int task2(); int task3();

inline bool isLeapYear(int year);

inline void scheduleMessage(std::string msg, size_t time);
inline void clearLines(size_t count);
inline double getNumber();

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	const size_t taskCount = 3;
	std::string taskName[taskCount] = {
		"Разница между датами",
		"Среднее арифметическое массива",
		"Подсчёт элементов массива"
	};
	std::function<int()> taskFunc[taskCount] = { task1, task2, task3 };

	while (true) {
		system("cls");
		std::cout << "Выберите задание (Урок #12)";
		for (size_t i = 0; i < taskCount; i++)
			std::cout << "\n\t" << i + 1 << " - " << taskName[i];
		std::cout << "\n\t0 - Выход\nВыбор: ";

		int choose = getNumber();
		if (choose > 0 && choose <= taskCount) {
			while (taskFunc[choose - 1]() == 1);
		}
		else if (choose == 0) break;
		else scheduleMessage("Ошибка ввода", 2);
	}
	return 0;
}

int task1() {
	system("cls");

	const std::string title[3] {"Год", "Месяц", "День"};

	int YMD[2][3]{{1, 1, 1}, {1, 1, 1}};
	int daysSum[2]{0, 0};

	for (size_t i = 0; i < 2; i++) {
		std::cout << (i == 0 ? "Первая" : "Вторая") << " дата:";
		std::cout << '\n';
		for (size_t j = 0; j < 3; j++) {
			std::cout << '\t' << title[j] << ": ";
			YMD[i][j] = getNumber();
			if (
				YMD[i][j] < 1 || YMD[i][1] > 12 ||
				YMD[i][2] > (YMD[i][1] == 2 ? (isLeapYear(YMD[i][0]) ? 29 : 28) : (YMD[i][1] % 2 == 0 ? 30 : 31))
			) {
				scheduleMessage("Ошибка ввода", 2);
				clearLines(2);
				j--;
				continue;
			}
		}
		for (size_t y = 1; y < YMD[i][0]; y++) daysSum[i] += isLeapYear(y) ? 366 : 365;
		for (size_t m = 1; m < YMD[i][1]; m++) daysSum[i] += m == 2 ? (isLeapYear(YMD[i][0]) ? 29 : 28) : (m % 2 == 0 ? 30 : 31);
		daysSum[i] += YMD[i][2];
		std::cout << '\n';
	}

	std::cout << "Разница в днях: " << abs(daysSum[0] - daysSum[1]);
	std::cout << "\n\n0 - Назад, 1 - Повторить: ";
	return getNumber();
}

int task2() {
	system("cls");

	double sum = 0;
	double arr[10];
	for (size_t i = 0; i < 10; i++) arr[i] = NAN;

	std::cout << "Введите 10 чисел: ";
	for (size_t i = 0; i < 10; i++) {
		arr[i] = getNumber();
		if (std::isnan(arr[i])) {
			scheduleMessage("Ошибка ввода", 2);
			i--;
			clearLines(2);
			std::cout << "Введите 10 чисел: ";
			for (size_t j = 0; j < i + 1; j++) std::cout << arr[j] << (j < 9 ? ", " : "");
			continue;
		}
		clearLines(2);
		std::cout << "Введите 10 чисел: ";
		for (size_t j = 0; j < i + 1; j++) std::cout << arr[j] << (j < 9 ? ", " : "");
		sum += arr[i];
	}

	std::cout << "\nСреднее арифметическое: " << sum / 10;
	std::cout << "\n\n0 - Назад, 1 - Повторить: ";
	return getNumber();
}

int task3() {
	system("cls");

	int positiveCount = 0;
	int negativeCount = 0;
	int zeroCount = 0;

	double arr[10];
	for (size_t i = 0; i < 10; i++) arr[i] = NAN;

	std::cout << "Введите 10 чисел: ";
	for (size_t i = 0; i < 10; i++) {
		arr[i] = getNumber();
		if (std::isnan(arr[i])) {
			scheduleMessage("Ошибка ввода", 2);
			i--;
			clearLines(2);
			std::cout << "Введите 10 чисел: ";
			for (size_t j = 0; j < i + 1; j++) std::cout << arr[j] << (j < 9 ? ", " : "");
			continue;
		}
		clearLines(2);
		std::cout << "Введите 10 чисел: ";
		for (size_t j = 0; j < i + 1; j++) std::cout << arr[j] << (j < 9 ? ", " : "");

		if (arr[i] > 0) positiveCount++;
		else if (arr[i] < 0) negativeCount++;
		else zeroCount++;
	}

	std::cout << "\nКоличество положительных чисел: " << positiveCount;
	std::cout << "\nКоличество отрицательных чисел: " << negativeCount;
	std::cout << "\nКоличество нулевых чисел: " << zeroCount;
	std::cout << "\n\n0 - Назад, 1 - Повторить: ";
	return getNumber();
}

inline bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

inline void scheduleMessage(std::string msg, size_t sec) {
	for (std::cout << '\n'; sec > 0; sec--) {
		std::cout << msg << " (" << sec << ')';
		Sleep(1000);
		std::cout << "\x1b[2K\r";
	}
}

inline void clearLines(size_t count) {
	for (size_t i = 0; i < count; i++) {
		std::cout << "\033[A\033[K";
	}
	std::cout.flush();
}

inline double getNumber() {
	std::string s; std::getline(std::cin, s);
	char* e;
	double v = strtod(s.c_str(), &e);
	if (e == s.c_str() || *e) return NAN;
	return v;
}