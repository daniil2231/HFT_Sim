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

    // Fill up the order book with a few dummy orders:
    for (Order o : initial_orders) {
        order_book.placeLimitOrder(o.getDirection(), o.getPrice(), o.getSize());
    }

    OrderQueue ob_buy_orders = order_book.getAllBuyOrders();
    OrderQueue ob_sell_orders = order_book.getAllSellOrders();

    // Print out all the orders in the order book:
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

    // Dummy cmp to test placing market orders:
    double current_market_price = 1000.0;

    // Placing a market buy order and checking if the sell order closest to the market one's price is no longer a limit in the order book.
    order_book.placeMarketOrder("buy", current_market_price, 0.05);
    std::cout << order_book.getAllSellOrders().top();
}
