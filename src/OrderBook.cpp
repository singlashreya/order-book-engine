#include "../include/OrderBook.h"
#include <iostream>

void OrderBook::addOrder(const Order& order) {
    if (order.side == Side::BUY)
        bids[order.price].push_back(order);
    else
        asks[order.price].push_back(order);

    matchOrders();
}

void OrderBook::printBook() {
    std::cout << "Bids:\n";

    for (const auto& [price, orders] : bids) {
        int totalQty = 0;
        for (const auto& order : orders)
            totalQty += order.quantity;

        std::cout << price << " : " << totalQty << std::endl;
    }

    std::cout << "\nAsks:\n";

    for (const auto& [price, orders] : asks) {
        int totalQty = 0;
        for (const auto& order : orders)
            totalQty += order.quantity;

        std::cout << price << " : " << totalQty << std::endl;
    }
}

void OrderBook::matchOrders() {
    while (!bids.empty() && !asks.empty()) {

        auto bestBid = bids.begin();
        auto bestAsk = asks.begin();

        if (bestBid->first < bestAsk->first)
            break;

        Order &buyOrder = bestBid->second.front();
        Order &sellOrder = bestAsk->second.front();

        int tradeQty = std::min(buyOrder.quantity, sellOrder.quantity);

        std::cout << "TRADE "
                  << tradeQty
                  << " @ "
                  << bestAsk->first
                  << std::endl;

        buyOrder.quantity -= tradeQty;
        sellOrder.quantity -= tradeQty;

        if (buyOrder.quantity == 0) {
            bestBid->second.erase(bestBid->second.begin());
            if (bestBid->second.empty())
                bids.erase(bestBid);
        }

        if (sellOrder.quantity == 0) {
            bestAsk->second.erase(bestAsk->second.begin());
            if (bestAsk->second.empty())
                asks.erase(bestAsk);
        }
    }
}

void OrderBook::processMarketOrder(Side side, int quantity) {

    if (side == Side::BUY) {
        while (quantity > 0 && !asks.empty()) {

            auto bestAsk = asks.begin();
            Order &sellOrder = bestAsk->second.front();

            int tradeQty = std::min(quantity, sellOrder.quantity);

            std::cout << "TRADE " << tradeQty << " @ " << bestAsk->first << std::endl;

            quantity -= tradeQty;
            sellOrder.quantity -= tradeQty;

            if (sellOrder.quantity == 0) {
                bestAsk->second.erase(bestAsk->second.begin());
                if (bestAsk->second.empty())
                    asks.erase(bestAsk);
            }
        }
    }

    else { // MARKET SELL
        while (quantity > 0 && !bids.empty()) {

            auto bestBid = bids.begin();
            Order &buyOrder = bestBid->second.front();

            int tradeQty = std::min(quantity, buyOrder.quantity);

            std::cout << "TRADE " << tradeQty << " @ " << bestBid->first << std::endl;

            quantity -= tradeQty;
            buyOrder.quantity -= tradeQty;

            if (buyOrder.quantity == 0) {
                bestBid->second.erase(bestBid->second.begin());
                if (bestBid->second.empty())
                    bids.erase(bestBid);
            }
        }
    }
}