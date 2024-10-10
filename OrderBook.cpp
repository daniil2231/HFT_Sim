#include "OrderBook.h"
#include <queue>

OrderBook::OrderBook(std::priority_queue<Order> o) {
	resting_orders = o;
}

std::priority_queue<Order> OrderBook::getAllOrders() {
	return resting_orders;
}

void OrderBook::placeLimitOrder(std::string d, std::string t, float p, float s) {
	Order new_order = Order(d, t, p, s);
	resting_orders.push(new_order);
}
