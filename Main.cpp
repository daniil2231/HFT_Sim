#include <iostream>
#include <queue>
#include "Order.h"
#include "OrderBook.h"

using OrderQueue = std::priority_queue<Order>;

int main()
{
    const auto initial_orders = {
        Order("buy", 998.0, 1.1),
        Order("buy", 999.0, 1.5),
        Order("sell", 1001.0, 0.05),
        Order("sell", 1002.0, 0.04)
    };

    OrderBook order_book;

    for (Order o : initial_orders) {
        order_book.placeLimitOrder(o.getDirection(), o.getPrice(), o.getSize());
    }

    OrderQueue ob_buy_orders = order_book.getAllBuyOrders();
    OrderQueue ob_sell_orders = order_book.getAllSellOrders();

    while (!ob_buy_orders.empty()) {
        Order topOrder = ob_buy_orders.top();
        std::cout << topOrder << std::endl;
        ob_buy_orders.pop();
    }
    std::cout << std::endl;

    while (!ob_sell_orders.empty()) {
        Order topOrder = ob_sell_orders.top();
        std::cout << topOrder << std::endl;
        ob_sell_orders.pop();
    }
    std::cout << std::endl;

    double current_market_price = 1000.0;

    order_book.placeMarketOrder("buy", current_market_price, 0.05);
    std::cout << order_book.getAllSellOrders().top();
}
