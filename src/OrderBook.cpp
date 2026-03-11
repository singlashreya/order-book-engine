#include "../include/OrderBook.h"
#include <iostream>

void OrderBook::addOrder(const Order& order) {
    if (order.side == Side::BUY) {
        bids[order.price].push_back(order);
    } else {
        asks[order.price].push_back(order);
    }
}

void OrderBook::printBook() {
    std::cout << "Bids:\n";
    for (const auto& [price, orders] : bids) {
        std::cout << price << " : " << orders.size() << " orders\n";
    }

    std::cout << "\nAsks:\n";
    for (const auto& [price, orders] : asks) {
        std::cout << price << " : " << orders.size() << " orders\n";
    }
}