#ifndef _CAT_HPP_
#define _CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat(std::string name, size_t age, double speed_ms, std::string fur_color, bool has_claws);

	std::string getFurColor() const;
	bool hasClaws() const;
	double getWalkedDistance() const;

	void setFurColor(std::string fur_color);
	void setClaws(bool has_claws);
	void doWalk(int steps);

private:
	std::string fur_color;
	bool has_claws;
	double walked_distance = 0;

};

#endif //_CAT_HPP_