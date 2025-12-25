#include <windows.h>
#include <iostream>
#include <string>

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	/*
		Я старался решить проблему с русскими буквами, и искал методы из сторонних библиотек, и сам создавал массивы алфавитов и пытался сравнивать char.
		Сравнение работало, но с выводом случалась какая-то фигня, хотя char был верный, короче говоря работает только с английским тектом :<
	*/

	std::string input, ops = ".!?;,:";
	do {
		system("cls");
		std::cout << "Введите сообщение: ";
		std::getline(std::cin, input);

		std::cout << "\033[A\033[2K";
		if (!input.empty()) {
			
			if (ops.find(input[input.size() - 1]) == std::string::npos) input += '.';
			for (char& ch : input) ch = tolower(ch);
			std::string lower = input;
			input[0] = toupper(input[0]);
			std::cout << input;

			std::cout << "\n\nКакое слово будем искать?\nВвод: ";
			std::getline(std::cin, input);
			for (char& ch : input) ch = tolower(ch);
			std::cout << "Слово " << input << (lower.find(input) != std::string::npos ? " присутствует" : " отсутствует") << " в сообщении.";
		} else std::cout << "\nСообщение пустое!";

		std::cout << "\n\nПовторить программу? (Пустой ввод - выход)\nВвод: ";
		std::getline(std::cin, input);
	} while (!input.empty());
}