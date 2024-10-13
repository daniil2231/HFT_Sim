#include <iostream>
#include <queue>
#include "Order.h"
#include "OrderBook.h"

using OrderQueue = std::priority_queue<Order>;

int main()
{
    const auto initial_orders = {
        Order("buy", false, 998.0, 1.1),
        Order("buy", false, 999.0, 1.5),
        Order("sell", false, 1001.0, 0.05),
        Order("sell", false, 1002.0, 0.04)
    };

    OrderBook ob_containing_buys;
    OrderBook ob_containing_sells;

    for (Order o : initial_orders) {
        if (o.getDirection() == "buy") {
            ob_containing_buys.placeLimitOrder("buy", false, o.getPrice(), o.getSize());
        }
        else {
            ob_containing_sells.placeLimitOrder("sell", false, o.getPrice(), o.getSize());
        }
    }

    OrderQueue ob_buy_orders = ob_containing_buys.getAllOrders();
    OrderQueue ob_sell_orders = ob_containing_sells.getAllOrders();

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
}
