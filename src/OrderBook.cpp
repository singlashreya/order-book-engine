#include "../include/OrderBook.h"
#include <iostream>

void OrderBook::addOrder(const Order& order) {
    if (order.side == Side::BUY) {
        buyOrders.push_back(order);
    } else {
        sellOrders.push_back(order);
    }
}

void OrderBook::printBook() {
    std::cout << "Buy Orders: " << buyOrders.size() << std::endl;
    std::cout << "Sell Orders: " << sellOrders.size() << std::endl;
}