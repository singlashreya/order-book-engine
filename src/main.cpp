#include <iostream>
#include <string>
#include "OrderBook.h"
#include "Order.h"

int main() {
    OrderBook book;
    int nextOrderId = 1;

    std::string type, side;
    double price;
    int quantity;

    while (std::cin >> type) {

    if (type == "LIMIT") {
        std::cin >> side >> price >> quantity;

        Side s = (side == "BUY") ? Side::BUY : Side::SELL;

        book.addOrder({nextOrderId++, s, price, quantity});

        std::cout << std::endl;
        book.printBook();
    }

    else if (type == "MARKET") {
        std::cin >> side >> quantity;

        Side s = (side == "BUY") ? Side::BUY : Side::SELL;

        book.processMarketOrder(s, quantity);

        std::cout << std::endl;
        book.printBook();
    }

    else if (type == "CANCEL") {
        int id;
        std::cin >> id;

        book.cancelOrder(id);

        std::cout << std::endl;
        book.printBook();
    }
}

    return 0;
}