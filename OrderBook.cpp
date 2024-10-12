#include "OrderBook.h"
#include <queue>

OrderBook::OrderBook(std::priority_queue<Order> o) {
	limit_orders = o;
}

OrderBook::OrderBook() {}

std::priority_queue<Order> OrderBook::getAllOrders() {
	return limit_orders;
}

void OrderBook::placeLimitOrder(std::string d, std::string t, double p, double s) {
	Order new_order = Order(d, t, p, s);
	limit_orders.push(new_order);
}
