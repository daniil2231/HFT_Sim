#include <iostream>
#include <queue>
#include "Order.h"
#include "OrderBook.h"

using OrderQueue = std::priority_queue<Order>;

int main()
{
    const auto initial_orders = {
        Order("buy", false, 1000.0, 1.1),
        Order("buy", false, 1001.0, 1.5),
        Order("sell", false, 1003.0, 0.04),
        Order("sell", false, 1001.0, 0.05)
    };

    OrderBook order_book;

    for (Order o : initial_orders) {
        order_book.placeLimitOrder(o.getDirection(), false, o.getPrice(), o.getSize());
    }

    OrderQueue order_book_orders = order_book.getAllOrders();

    while (!order_book_orders.empty()) {
        Order topOrder = order_book_orders.top();
        std::cout << topOrder << std::endl;
        order_book_orders.pop();
    }
}
