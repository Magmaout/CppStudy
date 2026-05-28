#include "headers/EmployeeSalary.hpp"

#include <stdexcept>

EmployeeSalary::EmployeeSalary(std::string name, double salary) {
	if (name.size() < 2 || name.size() > 25) throw std::invalid_argument("Имя должно содержать от 2 до 25 букв");
	this->name = name;
	setSalary(salary);

	const auto today = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
	hireDate = std::chrono::year_month_day{ today };
}

EmployeeSalary::EmployeeSalary(std::string name, double salary, int hireYear, unsigned hireMonth, unsigned hireDay)
	: EmployeeSalary(name, salary) {
	setHireDate(hireYear, hireMonth, hireDay);
}

std::string EmployeeSalary::getName() const {
	return name;
}

double EmployeeSalary::getSalary() const {
	return salary;
}

std::chrono::year_month_day EmployeeSalary::getHireDate() const {
	return hireDate;
}

int EmployeeSalary::getYearsWorked() const {
	const auto today = std::chrono::year_month_day{
		std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())
	};

	int years = int(today.year()) - int(hireDate.year());
	if (today.month() < hireDate.month()
		|| (today.month() == hireDate.month() && today.day() < hireDate.day())) {
		--years;
	}

	return years < 0 ? 0 : years;
}

double EmployeeSalary::getSeniorityBonusRate() const {
	constexpr double bonusPerYear = 0.01;
	constexpr double maxBonus = 0.20;

	const double bonus = getYearsWorked() * bonusPerYear;
	return bonus > maxBonus ? maxBonus : bonus;
}

void EmployeeSalary::raiseSalary(double percent) {
	if (percent < 0.) throw std::invalid_argument("Процент повышения зарплаты не может быть меньше 0");
	setSalary(salary * (1. + percent));
}

double EmployeeSalary::getEarning() const {
	return getSalary() * (1. + getSeniorityBonusRate());
}

std::string EmployeeSalary::toString() const {
	return std::format(
		"Имя: {}\nДата приема: {:04}-{:02}-{:02}\nБазовая зарплата: {:.2f}\nПремия за выслугу: {:.0f}%\nЗарплата с премией: {:.2f}\n",
		name,
		int(hireDate.year()), unsigned(hireDate.month()), unsigned(hireDate.day()),
		salary,
		getSeniorityBonusRate() * 100.,
		EmployeeSalary::getEarning()
	);
}

void EmployeeSalary::setSalary(double salary) {
	if (salary < 0.) throw std::invalid_argument("Зарплата не может быть меньше 0");
	this->salary = salary;
}

void EmployeeSalary::setHireDate(int hireYear, unsigned hireMonth, unsigned hireDay) {
	const std::chrono::year_month_day date{
		std::chrono::year{ hireYear },
		std::chrono::month{ hireMonth },
		std::chrono::day{ hireDay }
	};

	if (!date.ok()) throw std::invalid_argument("Некорректная дата приема на работу");
	hireDate = date;
}
