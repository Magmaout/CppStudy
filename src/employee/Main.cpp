#include "headers/EmployeeCommissionSalary.hpp"

#include <windows.h>
#include <iostream>
#include <vector>

int main() {
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	EmployeeSalary base("Пепе", 50000, 2024, 5, 20);
	EmployeeSalary experienced("Шнейне", 50000, 2014, 3, 15);
	EmployeeCommissionSalary manager("Фа", 20000, 4000000, 0.10, 0.13, 2019, 9, 1);
	EmployeeCommissionSalary seniorManager("Ватафа", 30000, 5500000, 0.12, 0.13, 2010, 2, 10);

	base.raiseSalary(0.05);
	experienced.raiseSalary(0.10);
	manager.raiseSalary(0.15);
	manager.raiseCommissionRate(0.20);
	seniorManager.raiseSalary(0.25);
	seniorManager.raiseCommissionRate(0.30);

	std::vector<EmployeeSalary*> employees{
		&base,
		&experienced,
		&manager,
		&seniorManager
	};

	for (const auto employee : employees) {
		std::cout << *employee << '\n';
	}
}
