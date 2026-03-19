#include "headers/Cat.hpp"

Cat::Cat(std::string name, size_t age, double speed_ms, std::string fur_color, bool has_claws) : Animal(name, age, speed_ms) {
	this->fur_color = fur_color;
	this->has_claws = has_claws;
}

std::string Cat::getFurColor() const {
	return this->fur_color;
}
bool Cat::hasClaws() const {
	return this->has_claws;
}
double Cat::getWalkedDistance() const {
	return this->walked_distance;
}

void Cat::setFurColor(std::string fur_color) {
	if (!fur_color.empty()) {
		if (!this->fur_color.empty()) std::cout << std::format("Питомец \"{}\" теперь имеет {} окрас шерсти!", getName(), fur_color) << '\n';
		else std::cout << std::format("Питомец \"{}\" магическим образом приобрёл шерсть и теперь имеет {} окрас шерсти!", getName(), fur_color) << '\n';
	} else std::cout << std::format("Питомец \"{}\" теперь выбритый налысо!", getName()) << '\n';
	this->fur_color = fur_color;
}
void Cat::setClaws(bool has_claws) {
	if (has_claws) std::cout << std::format("У питомца \"{}\" появились когти!", getName());
	else std::cout << std::format("Отныне питомец \"{}\" не имеет когтей... (ОСУЖДАЕМ)", getName()) << '\n';
	this->has_claws = has_claws;
}
void Cat::doWalk(int steps) {
	if (steps >= 0) {
		std::cout << std::format("Питомец \"{}\" прошёл {} метров!", getName(), getSpeedMS() * steps) << '\n';
		this->walked_distance += getSpeedMS() * steps;
	} else std::cout << std::format("Питомец \"{}\" не может пройти отрицательное кол-во шагов!", getName()) << '\n';
}