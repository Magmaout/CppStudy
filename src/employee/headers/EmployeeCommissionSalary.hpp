#ifndef _EMPLOYEECOMMISSIONSALARY_HPP_
#define _EMPLOYEECOMMISSIONSALARY_HPP_

#include "EmployeeSalary.hpp"

class EmployeeCommissionSalary : public EmployeeSalary {
public:
	EmployeeCommissionSalary(std::string name, double salary, double sales, double commissionRate);
	EmployeeCommissionSalary(std::string name, double salary, double sales, double commissionRate,
		double taxRate, int hireYear, unsigned hireMonth, unsigned hireDay);

	void setSales(double sales);
	void setCommissionRate(double commissionRate);
	void setTaxRate(double taxRate);
	double getSales() const;
	double getCommissionRate() const;
	double getTaxRate() const;
	double getCommissionEarning() const;
	double getGrossEarning() const;
	double getNetEarning() const;

	void raiseCommissionRate(double percent);

	double getEarning() const override;
	std::string toString() const override;
private:
	double sales = 0., commissionRate = 0., taxRate = 0.13;
};

#endif //_EMPLOYEECOMMISSIONSALARY_HPP_
