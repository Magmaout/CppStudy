#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include <iostream>
#include <string>
#include <format>

class Animal {
public:
	Animal(std::string name, size_t age, double speed_ms);

	std::string getName() const;
	size_t getAge() const;
	double getSpeedMS() const;

	void setName(std::string name);
	void setAge(size_t age);
	void setSpeedMS(double speed_ms);
	
private:
	std::string name;
	size_t age;
	double speed_ms;

};

#endif //_ANIMAL_HPP_