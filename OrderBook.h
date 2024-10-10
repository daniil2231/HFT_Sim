#include "Order.h"
#include <queue>

#pragma once
class OrderBook
{
public:
	std::priority_queue<Order> resting_orders;

	OrderBook(std::priority_queue<Order> o);

	std::priority_queue<Order> getAllOrders();

	void placeLimitOrder(std::string d, std::string t, float p, float s);
};

