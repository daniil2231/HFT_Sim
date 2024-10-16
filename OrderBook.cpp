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
		Order top_order = sell_orders.top();
		double top_order_size = top_order.getSize();

		if (top_order_size == s) {
			sell_orders.pop();
		}
		else if (top_order_size > s) {
			// Need to reinsert the limit order in case the market order's size is not enough to fully fill it - priority_queue does not support modifying elements directly.
			Order partially_filled_limit_order = Order("buy", top_order.getPrice(), top_order_size - s);
			sell_orders.pop();
			sell_orders.push(partially_filled_limit_order);
		}
		else {
			double partially_filled_market_order_size = s - top_order_size;
			sell_orders.pop();
			// TODO: Loop which keeps getting the next order and subtracting from the market order's size until the market order's size is 0.
		}
	}
	else {
		buy_orders.pop();
	}
}
