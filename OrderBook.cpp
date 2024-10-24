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
		Order top_limit_order = sell_orders.top();
		double top_limit_order_size = top_limit_order.getSize();

		// Exact order size match
		if (top_limit_order_size == s) {
			sell_orders.pop();
		}
		// Market size < closest limit size
		else if (s < top_limit_order_size) {
			// Need to reinsert the limit order in case the market order's size is not enough to fully fill it -
			// priority_queue does not support modifying elements directly.
			Order partially_filled_limit_order = Order("buy", top_limit_order.getPrice(), top_limit_order_size - s);
			sell_orders.pop();
			sell_orders.push(partially_filled_limit_order);
		}
		// Market size > closest limit size
		else {
			double partially_filled_market_order_size = s - top_limit_order_size;
			sell_orders.pop();
			// TODO: Loop which keeps getting the next order and subtracting from
			// the market order's size until the market order's size is 0.
			while (partially_filled_market_order_size > 0.01) {
				top_limit_order = sell_orders.top();
				top_limit_order_size = top_limit_order.getSize();

				if (partially_filled_market_order_size == top_limit_order_size) {
					partially_filled_market_order_size = 0;

					sell_orders.pop();
				}
				else if (partially_filled_market_order_size < top_limit_order_size) {
					Order partially_filled_limit_order = Order("buy", top_limit_order.getPrice(), top_limit_order_size - partially_filled_market_order_size);
					partially_filled_market_order_size = 0;

					sell_orders.pop();
					sell_orders.push(partially_filled_limit_order);
				}
				else {
					partially_filled_market_order_size = partially_filled_market_order_size - top_limit_order_size;

					sell_orders.pop();
				}
			}
		}
	}
	else {
		buy_orders.pop();
	}
}
