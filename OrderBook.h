#include "Order.h"
#include <queue>

#pragma once
class OrderBook
{
public:
	std::priority_queue<Order> buy_orders;

	std::priority_queue<Order> sell_orders;

	OrderBook();

	std::priority_queue<Order> getAllBuyOrders();

	std::priority_queue<Order> getAllSellOrders();

	void placeLimitOrder(std::string d, double p, double s);

	void placeMarketOrder(std::string d, double p, double s);
};

