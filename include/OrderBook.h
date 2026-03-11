#include "Order.h"
#include <map>
#include <vector>

class OrderBook {
public:
    void addOrder(const Order& order);
    void printBook();

private:
    std::map<double, std::vector<Order>, std::greater<double>> bids;
    std::map<double, std::vector<Order>> asks;
};