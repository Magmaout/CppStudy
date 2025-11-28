#include <functional>
#include <windows.h>
#include <iostream>
#include <string>

int task1(); int task2(); int task3();

inline void scheduleMessage(std::string msg, size_t time);
inline void getLine(std::string& str);
inline void clearLines(size_t count);
inline double getNumber();

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand((int)time(NULL));

	const size_t taskCount = 3;
	std::string taskName[taskCount] = {
		"Мин и макс элементы случ массива",
		"Сумма чисел которые меньше указанного числа в случ массиве с указанным диапазоном",
		"Просмотр прибыли за год по месяцам",
	};
	std::function<int()> taskFunc[taskCount] = { task1, task2, task3 };
	std::string input;

	while (true) {
		system("cls");
		std::cout << "Какое задание хотите выбрать? (Урок #7)";
		for (int i = 0; i < taskCount; i++) {
			std::cout << "\n\t" << i + 1 << " - " << taskName[i] << (i + 1 != taskCount ? ';' : '.');
		}
		std::cout << "\n\t0 - Выход";
		std::cout << "\nВыберите задание (от 1 до " << taskCount << "): ";

		int choose = getNumber();
		if (choose != INT_MIN && choose <= taskCount && choose > 0) {
			while (taskFunc[choose - 1]() == 1);
			continue;
		} else if (choose == 0) break;
		scheduleMessage("Ошибка: Неккоректный ввод!", 3);
		continue;
	}

	return 0;
}

int task1() {
	system("cls");
	const size_t size = 10;
	int arr[size], min, max;

	std::cout << "Случайные числа: ";
	for (size_t i = 0; i < size; i++) {
		arr[i] = rand() % 20;
		if (i > 0) {
			if (arr[i] < min) min = arr[i];
			else if (arr[i] > max) max = arr[i];
		} else min = max = arr[i];
		std::cout << arr[i] << (i + 1 != size ? ", " : "");
	}
	std::cout << "\nМинимальное число: " << min;
	std::cout << "\nМаксимальное число: " << max;

	std::cout << "\n\n0 - Назад, 1 - Повторить: ";
	return (int) getNumber();
}

int task2() {
	const size_t size = 10;
	int arr[size], minRand, maxRand, maxItem;

	while (true) {
		system("cls");
		std::cout << "Введите минимальное значение для случайного числа: ";
		minRand = getNumber();
		if (minRand == INT_MIN) {
			scheduleMessage("Ошибка: Неккоректный ввод!", 3);
			continue;
		}

		std::cout << "Введите максимальное значение для случайного числа: ";
		maxRand = getNumber();
		if (maxRand == INT_MIN) {
			scheduleMessage("Ошибка: Неккоректный ввод!", 3);
			continue;
		}
		if (maxRand < minRand) {
			scheduleMessage("Ошибка: Максимальное число не может быть меньше минимального!", 3);
			continue;
		}

		std::cout << "Введите порог значения до которого числа будут суммироваться: ";
		maxItem = getNumber();
		if (maxItem == INT_MIN) {
			scheduleMessage("Ошибка: Неккоректный ввод!", 3);
			continue;
		}
		break;
	};

	int sum = 0;
	std::cout << "\nСлучайные числа с указанным диапазоном: ";
	for (size_t i = 0; i < size; i++) {
		arr[i] = minRand + rand() % (maxRand - minRand + 1);
		std::cout << arr[i] << (i + 1 != size ? ", " : "");
		if (arr[i] < maxItem) sum += arr[i];
	}
	std::cout << "\nСумма чисел которые меньше " << maxItem << ": " << sum;

	std::cout << "\n\n0 - Назад, 1 - Повторить: ";
	return (int) getNumber();
}

int task3() {
	system("cls");
	const size_t size = 12;
	std::string month[size] = {
		"январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь"
	};
	double sumProfit = 0, profit[size] = {};

	std::cout << "Просмотр прибыли за год по месяцам\n";
	for (size_t i = 0; i < size; i++) {
		std::cout << '\t' << i + 1 << " - Введите прибыль за " << month[i] << ": ";
		double money = getNumber();
		if (money == INT_MIN) {
			scheduleMessage("Ошибка: Неккоректный ввод", 3);
			clearLines(2);
			i--;
		} else {
			profit[i] = money;
			sumProfit += money;
		}
	}

	double minProfit, maxProfit;
	std::string minProfitMonth, maxProfitMonth;
	size_t fromMonth, toMonth;
	while (true) {
		system("cls");
		std::cout << "Общая прибыль за год: " << sumProfit << "р";

		std::cout << "\n\tОт какого месяца посчитать прибыль? (номер месяца): ";
		fromMonth = getNumber();
		if (fromMonth == INT_MIN || fromMonth < 1 || fromMonth > 12) {
			scheduleMessage("Ошибка: Неккоректный ввод", 3);
			continue;
		}
		fromMonth--;

		std::cout << "\tДо какого месяца посчитать прибыль? (номер месяца): ";
		toMonth = getNumber();
		if (toMonth == INT_MIN || toMonth < 1 || toMonth > 12 || toMonth < fromMonth) {
			scheduleMessage("Ошибка: Неккоректный ввод", 3);
			continue;
		}
		toMonth--;

		minProfit = profit[fromMonth], maxProfit = profit[toMonth];
		minProfitMonth = month[fromMonth], maxProfitMonth = month[toMonth];
		for (size_t i = fromMonth; i < toMonth + 1; i++) {
			if (profit[i] < minProfit) {
				minProfit = profit[i];
				minProfitMonth = month[i];
			} else if (profit[i] > maxProfit) {
				maxProfit = profit[i];
				maxProfitMonth = month[i];
			}
		}
		std::cout << "Минимальная прибыль была в " << minProfitMonth << " месяц: " << minProfit;
		std::cout << "\nМаксимальная прибыль была в " << maxProfitMonth << " месяц: " << maxProfit;

		std::cout << "\n\n0 - Назад, 1 - Повторить, 2 - Выбрать другой диапазон: ";
		int choose = getNumber();
		if (choose == 2) continue;
		return choose;
	}
}

inline void scheduleMessage(std::string msg, size_t sec) {
	for (std::cout << '\n'; sec > 0; sec--) {
		std::cout << msg << " (" << sec << ')';
		Sleep(1000);
		std::cout << "\x1b[2K\r";
	}
}

inline double getNumber() {
	std::string input; std::getline(std::cin, input);

	char* end;
	const char* cstr = input.c_str();

	while (*cstr == ' ' || *cstr == '\t') cstr++;
	if (*cstr == '\0') return INT_MIN;

	double value = strtod(cstr, &end);

	if (cstr == end) return INT_MIN;
	while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') ++end;
	if (*end != '\0') return INT_MIN;

	return value;
}

inline void getLine(std::string& str) {
	getline(std::cin, str, '\n');
}

inline void clearLines(size_t count) {
	for (size_t i = 0; i < count; i++) {
		std::cout << "\033[A\033[K";
	}
	std::cout.flush();
}