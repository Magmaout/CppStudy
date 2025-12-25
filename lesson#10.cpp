#include <functional>
#include <windows.h>
#include <iostream>
#include <string>

inline void scheduleMessage(std::string msg, size_t time);
inline void clearLines(size_t count);
inline float getNumber();

const size_t size = 9;
const float min = 0.5, max = 99.9;

const unsigned int range[3][2] = { {0, 4}, {5, 7}, {7, 9} };
const std::string name[size] = {
	"Яблочный", "Апельсиновый", "Абрикосовый", "Грушевый",
	"Томатный", "Луковый", "Огуречный",
	"Чесночный", "Петрушевый"
};
const float price[size] = {
	120, 140, 150, 130,
	110, 90, 100,
	160, 180
};

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	float discount = 0, total = 0, choose, count[size];

	std::cout << "--- Соки Никиты ---";
	for (size_t i = 0; i < size; i++) {
		switch (i) {
			case 0: std::cout << "\nФруктовые соки:"; break;
			case 4: std::cout << "\nОвощные соки:"; break;
			case 7: std::cout << "\nЧаи:"; break;
		}
		std::cout << "\n\t" << i + 1 << " - " << name[i] << " (" << price[i] << "р за литр)";
		count[i] = 0;
	}
	std::cout << '\n';

	while (true) {
		std::cout << "\nВыбор (0 - К оплате): ";
		choose = getNumber();
		if (choose == 0) break;
		else if (std::isnan(choose) || choose < 1 || choose > size) {
			scheduleMessage("Неккоректный ввод", 3);
			clearLines(2);
			continue;
		}
		clearLines(1);
		int product = (int) choose - 1;
		std::cout << "Продукт \"" << name[product] << "\"";
		std::cout << "\nКол-во (в литрах): ";
		choose = getNumber();
		if (std::isnan(choose) || choose < min || choose > max) {
			scheduleMessage("Кол-во литров слишком маленькое или большое", 3);
			clearLines(2);
			continue;
		}
		clearLines(1);
		std::cout << "Кол-во: " << choose << "л;";
		std::cout << "\nЦена: " << price[product] * choose << "р.\n";
		count[product] += choose;
	}

	for (size_t i = range[0][0]; i < range[0][1]; i++) {
		total += count[i] * price[i];
	}
	for (size_t i = range[1][0]; i < range[1][1]; i++) {
		total += (count[i] - (i == 5 ? (int)(count[i] / 4) : 0)) * price[i];
	}
	for (size_t i = range[2][0]; i < range[2][1]; i++) {
		float sum = count[i] * price[i];
		if (i == 8 && count[i] >= 3) {
			discount += sum * 0.05;
			sum -= sum * 0.05;
		}
		total += sum;
	}
	if (total > 1000) {
		discount += total * 0.13;
		total -= total * 0.13;
	}

	std::cout << "\n--- Итог ---\n";
	std::cout << "Скидка: " << discount << "р\n";
	std::cout << "К оплате: " << total << "р\n";
	if (count[5] / 4 > 0) std::cout << "Подарок: " << (int)(count[5] / 4) << "л лукового сока!\n";

	return 0;
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

inline float getNumber() {
	std::string s; std::getline(std::cin, s);
	char* e;
	float v = strtod(s.c_str(), &e);
	if (e == s.c_str() || *e) return NAN;
	return v;
}