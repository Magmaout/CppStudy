#include "headers/EmployeeCommissionSalary.hpp"

#include <stdexcept>

EmployeeCommissionSalary::EmployeeCommissionSalary(std::string name, double salary, double sales, double commissionRate)
	: EmployeeSalary(name, salary) {
	setSales(sales);
	setCommissionRate(commissionRate);
}

EmployeeCommissionSalary::EmployeeCommissionSalary(std::string name, double salary, double sales, double commissionRate,
	double taxRate, int hireYear, unsigned hireMonth, unsigned hireDay)
	: EmployeeSalary(name, salary, hireYear, hireMonth, hireDay) {
	setSales(sales);
	setCommissionRate(commissionRate);
	setTaxRate(taxRate);
}

void EmployeeCommissionSalary::setSales(double sales) {
	if (sales < 0) throw std::invalid_argument("Продажи не могут быть меньше нуля");
	this->sales = sales;
}

void EmployeeCommissionSalary::setCommissionRate(double commissionRate) {
	if (commissionRate < 0 || commissionRate >= 1) throw std::invalid_argument("Комиссия должна быть от 0 до 1");
	this->commissionRate = commissionRate;
}

void EmployeeCommissionSalary::setTaxRate(double taxRate) {
	if (taxRate < 0 || taxRate >= 1) throw std::invalid_argument("Налог должен быть от 0 до 1");
	this->taxRate = taxRate;
}

double EmployeeCommissionSalary::getSales() const {
	return sales;
}

double EmployeeCommissionSalary::getCommissionRate() const {
	return commissionRate;
}

double EmployeeCommissionSalary::getTaxRate() const {
	return taxRate;
}

double EmployeeCommissionSalary::getCommissionEarning() const {
	return getSales() * getCommissionRate();
}

double EmployeeCommissionSalary::getGrossEarning() const {
	return EmployeeSalary::getEarning() + getCommissionEarning();
}

double EmployeeCommissionSalary::getNetEarning() const {
	return getGrossEarning() * (1. - getTaxRate());
}

void EmployeeCommissionSalary::raiseCommissionRate(double percent) {
	if (percent < 0.) throw std::invalid_argument("Процент повышения комиссии не может быть меньше 0");
	setCommissionRate(commissionRate * (1. + percent));
}

double EmployeeCommissionSalary::getEarning() const {
	return getNetEarning();
}

std::string EmployeeCommissionSalary::toString() const {
	return std::format(
		"{}Продажи: {:.2f}\nКомиссия: {:.0f}%\nДоход от комиссии: {:.2f}\nНачислено до налога: {:.2f}\nНалог: {:.0f}%\nЗарплата после налога: {:.2f}\n",
		EmployeeSalary::toString(),
		sales,
		commissionRate * 100.,
		getCommissionEarning(),
		getGrossEarning(),
		taxRate * 100.,
		getNetEarning()
	);
}
