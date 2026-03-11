#pragma once

#include <vector>

enum class Side {
    BUY,
    SELL
};

struct Order {
    int id;
    Side side;
    double price;
    int quantity;
};

class OrderBook {
public:
    void addOrder(const Order& order);
    void printBook();

private:
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;
};
