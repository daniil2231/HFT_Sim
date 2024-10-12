#include <string>

#pragma once
class Order
{
	std::string direction;
	bool filled;
	double price;
	double size;

public:
	Order(std::string d, bool f, double p, double s);

	std::string getDirection();

	bool getFilled();

	double getPrice();

	double getSize();

	bool operator<(const Order& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Order& order);
};

