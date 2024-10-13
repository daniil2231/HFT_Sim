#include <string>

#pragma once
class Order
{
	std::string direction;
	double price;
	double size;

public:
	Order(std::string d, double p, double s);

	std::string getDirection();

	double getPrice();

	double getSize();

	bool operator<(const Order& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Order& order);
};

