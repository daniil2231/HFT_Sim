#include "OrderBook.h"
#include <queue>
#include <iostream>

OrderBook::OrderBook() {}

std::priority_queue<Order> OrderBook::getAllBuyOrders() {
	return buy_orders;
}

std::priority_queue<Order> OrderBook::getAllSellOrders() {
	return sell_orders;
}

void OrderBook::placeLimitOrder(std::string d, double p, double s) {
	Order new_order = Order(d, p, s);
	if (d == "buy") {
		buy_orders.push(new_order);
	}
	else {
		sell_orders.push(new_order);
	}
}

void OrderBook::placeMarketOrder(std::string d, double p, double s) {
	Order new_order = Order(d, p, s);
	if (d == "buy" && s) {
		Order top = sell_orders.top();
		double top_size = top.getSize();
		if (top_size == s) {
			sell_orders.pop();
		}
	}
	else {
		buy_orders.pop();
	}
}
