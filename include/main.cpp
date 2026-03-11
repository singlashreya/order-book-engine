#include <iostream>
#include <string>

enum class Side {
    BUY,
    SELL
};

struct Order {
    int order_id;
    Side side;
    double price;
    int quantity;
};

int main() {
    std::cout << "Order Book Engine Initialized" << std::endl;
    return 0;
}