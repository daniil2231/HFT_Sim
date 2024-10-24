#include "Order.h"
#include <iostream>

Order::Order(std::string d, double p, double s) {
	direction = d;
	price = p;
	size = s;
}

std::string Order::getDirection() {
	return this->direction;
}

double Order::getPrice() {
	return this->price;
}

double Order::getSize() {
	return this->size;
}

bool Order::operator<(const Order& other) const {
	if (direction == "buy" && other.direction == "buy") {
		return price < other.price;
	}
	else if (direction == "sell" && other.direction == "sell") {
		return price > other.price;
	}
	else {
		return direction == "sell";
	}
}

std::ostream& operator<<(std::ostream& os, const Order& order)
{
	os << "Price: " << order.price << ", Direction: " << order.direction << ", Size: " << order.size;
	return os;
}
