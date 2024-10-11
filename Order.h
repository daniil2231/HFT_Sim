#include <string>

#pragma once
class Order
{
	std::string direction;
	std::string type;
	double price;
	double size;

public:
	Order(std::string d, std::string t, double p, double s);

	bool operator<(const Order& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Order& order);
};

