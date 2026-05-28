#ifndef _EMPLOYEESALARY_HPP_
#define _EMPLOYEESALARY_HPP_

#include <string>
#include <format>
#include <chrono>
#include <ostream>

class EmployeeSalary {
public:
	EmployeeSalary(std::string name, double salary);
	EmployeeSalary(std::string name, double salary, int hireYear, unsigned hireMonth, unsigned hireDay);
	
	std::string getName() const;
	double getSalary() const;
	std::chrono::year_month_day getHireDate() const;
	int getYearsWorked() const;
	double getSeniorityBonusRate() const;

	void raiseSalary(double percent);

	virtual double getEarning() const;
	virtual std::string toString() const;
	virtual ~EmployeeSalary() = default;

	friend std::ostream& operator<<(std::ostream& os, const EmployeeSalary& emp) {
		return os << emp.toString();
	}
private:
	void setSalary(double salary);
	void setHireDate(int hireYear, unsigned hireMonth, unsigned hireDay);

	std::string name{};
	double salary = 0.;
	std::chrono::year_month_day hireDate{};
};

#endif //_EMPLOYEESALARY_HPP_
