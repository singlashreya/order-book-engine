#include <iostream>
#include <string>
#include "OrderBook.h"
#include "Order.h"

int main() {
    OrderBook book;

    std::string type, side;
    double price;
    int quantity;

    while (std::cin >> type) {

        if (type == "LIMIT") {
            std::cin >> side >> price >> quantity;

            Side s = (side == "BUY") ? Side::BUY : Side::SELL;

            book.addOrder({0, s, price, quantity});

            // Print the state of the book only after processing a valid order
            book.printBook();
        }
    }

    return 0;
}