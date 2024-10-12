#include "Order.h"
#include <iostream>

Order::Order(std::string d, bool f, double p, double s) {
	direction = d;
	filled = f;
	price = p;
	size = s;
}

std::string Order::getDirection() {
	return this->direction;
}

bool Order::getFilled() {
	return this->filled;
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
