#ifndef _MEOWL_HPP_
#define _MEOWL_HPP_

#include "Cat.hpp"
#include "Bird.hpp"

class Meowl : public Cat, public Bird {
public:
	Meowl(
		std::string name, size_t age,
		double speed_ms, double fly_speed_ms,
		std::string fur_color, std::string feather_color,
		bool has_claws, bool can_meow_how_cat, bool can_whoop_how_owl
	);

	std::string getBlendColor() const;
	double getMotionDistance() const;
	bool canMeowHowCat() const;
	bool canWhoopHowOwl() const;

	void setMeowHowCat(bool can_meow_how_cat);
	void setWhoopHowOwl(bool can_whoop_how_owl);

private:
	bool can_meow_how_cat;
	bool can_whoop_how_owl;
};

#endif //_MEOWL_HPP_