#include "Order.h"
#include <queue>

#pragma once
class OrderBook
{
public:
	std::priority_queue<Order> limit_orders;

	OrderBook(std::priority_queue<Order> o);

	OrderBook();

	std::priority_queue<Order> getAllOrders();

	void placeLimitOrder(std::string d, bool f, double p, double s);
};

