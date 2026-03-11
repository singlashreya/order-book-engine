#include <iostream>
#include <string>
#include "../include/OrderBook.h"

int main() {
    OrderBook book;

    Order order1{1, Side::BUY, 100.5, 10};
    Order order2{2, Side::SELL, 101.0, 5};

    book.addOrder(order1);
    book.addOrder(order2);

    book.printBook();

    return 0;
}