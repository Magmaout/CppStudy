#ifndef _BIRD_HPP_
#define _BIRD_HPP_

#include "Animal.hpp"

class Bird : public Animal {
public:
	Bird(std::string name, size_t age, double speed_ms, std::string feather_color, double fly_speed_ms);

	std::string getFeatherColor() const;
	double getFlewDistance() const;
	double getFlySpeedMS() const;

	void setFeatherColor(std::string fur_color);
	void setFlySpeedMS(double fly_speed_ms);
	void doFly(int steps);

private:
	std::string feather_color;
	double fly_speed_ms;
	double flew_distance = 0;

};

#endif //_BIRD_HPP_