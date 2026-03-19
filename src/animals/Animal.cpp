#include "headers\Animal.hpp"

Animal::Animal(std::string name, size_t age, double speed_ms) {
	if (name.empty() || speed_ms < 0.0) throw std::exception("Ошибка инициализации питомца!\n\n");
	this->name = name;
	this->age = age;
	this->speed_ms = speed_ms;
}

std::string Animal::getName() const {
	return name;
}
size_t Animal::getAge() const {
	return age;
}
double Animal::getSpeedMS() const {
	return speed_ms;
}

void Animal::setName(std::string name) {
	if (!name.empty()) {
		std::cout << std::format("Питомец по кличке \"{}\" теперь \"{}\"!", this->name, name) << '\n';
		this->name = name;
	} else std::cout << std::format("Нельзя переименовать \"{}\" на пустое имя!", this->name) << '\n';
}
void Animal::setAge(size_t age) {
	if (age <= this->age) {
		std::cout << std::format("Питомцу \"{}\" исполнилось {} лет!", this->name, age) << '\n';
		this->age = age;
	} else std::cout << std::format("Питомцу \"{}\" не может исполниться меньше лет чем сейчас!", this->name) << '\n';
}
void Animal::setSpeedMS(double speed_ms) {
	if (speed_ms > 0.0) {
		std::cout << std::format("Питомец \"{}\" теперь ходит {} метров в секунду!", this->name, speed_ms) << '\n';
		this->speed_ms = speed_ms;
	} else std::cout << std::format("Питомец \"{}\" не может иметь отрицательную скорость при ходьбе!", this->name) << '\n';
}