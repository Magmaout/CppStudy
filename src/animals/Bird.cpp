#include "headers/Bird.hpp"

Bird::Bird(std::string name, size_t age, double speed_ms, std::string feather_color, double fly_speed_ms) : Animal(name, age, speed_ms) {
	this->feather_color = feather_color;
	this->fly_speed_ms = fly_speed_ms;
}

std::string Bird::getFeatherColor() const {
	return this->feather_color;
}
double Bird::getFlySpeedMS() const {
	return this->fly_speed_ms;
}
double Bird::getFlewDistance() const {
	return this->flew_distance;
}

void Bird::setFeatherColor(std::string feather_color) {
	if (!feather_color.empty()) {
		if (!this->feather_color.empty()) std::cout << std::format("Питомец \"{}\" теперь имеет {} окрас перьев!", getName(), feather_color) << '\n';
		else std::cout << std::format("Питомец \"{}\" магическим образом приобрёл перья и теперь имеет {} окрас перьев!", getName(), feather_color) << '\n';
	}
	else std::cout << std::format("Питомец \"{}\" теперь выщипанный налысо!", getName()) << '\n';
	this->feather_color = feather_color;
}
void Bird::setFlySpeedMS(double fly_speed_ms) {
	if (fly_speed_ms > 0.0) {
		std::cout << std::format("Питомец \"{}\" теперь летает {} метров в секунду!", getName(), fly_speed_ms) << '\n';
		this->fly_speed_ms = fly_speed_ms;
	}
	else std::cout << std::format("Питомец \"{}\" не может иметь отрицательную скорость в полёте!", getName()) << '\n';
}
void Bird::doFly(int steps) {
	if (steps >= 0) {
		std::cout << std::format("Питомец \"{}\" прошёл {} метров!", getName(), getFlySpeedMS() * steps) << '\n';
		this->flew_distance += getFlySpeedMS() * steps;
	} else std::cout << std::format("Питомец \"{}\" не может пройти отрицательное кол-во шагов!", getName()) << '\n';
}