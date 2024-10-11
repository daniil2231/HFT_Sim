#include <iostream>
#include <queue>
#include "Order.h"

using OrderQueue = std::priority_queue<Order>;

int main()
{
    const auto new_orders = {
        Order("buy", "limit", 1000.0, 1.1),
        Order("buy", "limit", 1001.0, 1.5),
        Order("sell", "limit", 1003.0, 0.04),
        Order("sell", "limit", 1001.0, 0.05)
    };

    OrderQueue limit_orders;

    for (Order o : new_orders) {
        limit_orders.push(o);
    }

    while (!limit_orders.empty()) {
        Order topOrder = limit_orders.top();
        std::cout << topOrder << std::endl;
        limit_orders.pop();
    }
}
