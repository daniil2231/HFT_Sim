#include <string>

#pragma once
class Order
{
	std::string direction;
	std::string type;
	float price;
	float size;

public:
	Order(std::string d, std::string t, float p, float s);

	bool operator<(const Order& other) const;
};

