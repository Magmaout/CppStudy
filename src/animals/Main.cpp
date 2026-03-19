#include <windows.h>

#include "headers/Meowl.hpp"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	try {
		Animal error("", 0, -5);
	} catch (std::exception err) {
		std::cout << err.what();
	}

	Animal animal("Дудоька", 1, 2);
	std::cout << std::format(
		"Питомцу \"{}\" {} год и он ходит со скоростью {} м/с!\n",
		animal.getName(), animal.getAge(), animal.getSpeedMS()
	);
	animal.setName("Павапепегемабоди");
	animal.setAge(2);
	animal.setSpeedMS(0.2);
	std::cout << '\n';

	Cat cat("Стёпик", 5, 3.5, "чёрный", true);
	std::cout << std::format(
		"Коту \"{}\" {} лет и он ходит со скоростью {} м/с, имеет {} окрас шерсти и {} когти!\n",
		cat.getName(), cat.getAge(), cat.getSpeedMS(), cat.getFurColor(), cat.hasClaws() ? "имеет" : "не имеет"
	);
	cat.setFurColor("белый");
	cat.setClaws(false);
	cat.doWalk(5);
	cat.doWalk(7);
	std::cout << std::format("Кот \"{}\" прошёл всего {} метров!\n\n", cat.getName(), cat.getWalkedDistance());

	Bird bird("Калли", 3, 0, "розовый", 25);
	std::cout << std::format(
		"Птичке \"{}\" {} года и она не ходит совсем из-за слабых лапок ({} м/с), имеет {} окрас перьев и летает со скоростью {} м/с!\n",
		bird.getName(), bird.getAge(), bird.getSpeedMS(), bird.getFeatherColor(), bird.getFlySpeedMS()
	);
	bird.setFeatherColor("голубой");
	bird.setFlySpeedMS(20);
	bird.doFly(30);
	bird.doFly(45);
	std::cout << std::format("Птичка \"{}\" пролетела всего {} метров!\n\n", bird.getName(), bird.getFlewDistance());

	Meowl meowl("Мяовл", 7, 0.7, 40, "белый", "коричневый", true, true, false);
	std::cout << std::format(
		"Котосове \"{}\" {} лет и она довольно медленно ходит, всего {} м/с, имеет окрас \"{}\", летает со скоростью {} м/с, а так же {} и {}!\n",
		meowl.Cat::getName(), meowl.Cat::getAge(), meowl.Cat::getSpeedMS(), meowl.getBlendColor(), meowl.getFlySpeedMS(),
		meowl.canMeowHowCat() ? "мяукает" : "не мяукает", meowl.canWhoopHowOwl() ? "ухукает" : "не ухукает"
	);
	meowl.setMeowHowCat(false);
	meowl.setWhoopHowOwl(true);
	meowl.doWalk(8);
	meowl.doWalk(13);
	meowl.doFly(68);
	meowl.doFly(46);
	std::cout << std::format("Котосова \"{}\" изменила своё местоположение на {} метров!\n", meowl.Cat::getName(), meowl.getMotionDistance());

	return 0;
}