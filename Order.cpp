#include "Order.h"

Order::Order(std::string d, std::string t, float p, float s) {
	direction = d;
	type = t;
	price = p;
	size = s;
}

bool Order::operator<(const Order& other) const {
	return this->price < other.price;
}