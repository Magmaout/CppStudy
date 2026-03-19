#include "headers/Meowl.hpp"

Meowl::Meowl(
	std::string name, size_t age,
	double speed_ms, double fly_speed_ms,
	std::string fur_color, std::string feather_color,
	bool has_claws, bool can_meow_how_cat, bool can_whoop_how_owl
):
	Cat(name, age, speed_ms, fur_color, has_claws),
	Bird(name, age, speed_ms, feather_color, fly_speed_ms)
{
	this->can_meow_how_cat = can_meow_how_cat;
	this->can_whoop_how_owl = can_whoop_how_owl;
}

std::string Meowl::getBlendColor() const {
	return getFurColor() + "-" + getFeatherColor();
}
double Meowl::getMotionDistance() const {
	return getWalkedDistance() + getFlewDistance();
}
bool Meowl::canMeowHowCat() const {
	return can_meow_how_cat;
}
bool Meowl::canWhoopHowOwl() const {
	return can_whoop_how_owl;
}

void Meowl::setMeowHowCat(bool can_meow_how_cat) {
	if (can_meow_how_cat) std::cout << std::format("Питомец \"{}\" теперь умеет мяукать как кот!", this->Cat::getName()) << '\n';
	else std::cout << std::format("Питомец \"{}\" больше не у меет мяукать как кот!", this->Cat::getName()) << '\n';
	this->can_meow_how_cat = can_meow_how_cat;
}
void Meowl::setWhoopHowOwl(bool can_whoop_how_owl) {
	if (can_whoop_how_owl) std::cout << std::format("Питомец \"{}\" теперь умеет ухукать как сова!", this->Cat::getName()) << '\n';
	else std::cout << std::format("Питомец \"{}\" больше не у меет ухукать как сова!", this->Cat::getName()) << '\n';
	this->can_whoop_how_owl = can_whoop_how_owl;
}