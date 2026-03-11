# Limit Order Book Engine (C++)

This project implements a simple **in‑memory limit order book** for a single financial instrument.  
The engine processes buy and sell orders and maintains separate books for bids and asks.

The goal of the project is to simulate the core mechanics used in real electronic trading systems:
- Order storage
- Price–time priority
- Matching of buy and sell orders
- Trade execution

This repository is being built **incrementally with clear commit history**, where each step introduces a new component of the matching engine.

---

# Project Structure

project/
│
├── include/        # Header files
│   ├── Order.h
│   └── OrderBook.h
│
├── src/            # Implementation files
│   ├── main.cpp
│   └── OrderBook.cpp
│
├── README.md
└── .gitignore


Explanation

include/  
Contains declarations and data structures used across the project.

src/  
Contains implementation files and the program entry point.

main.cpp  
Creates an order book instance and demonstrates basic usage.

OrderBook.cpp  
Implements order storage and order book logic.

---

# Build Instructions

Compile the program from the project root using:

g++ src/main.cpp src/OrderBook.cpp -Iinclude -o orderbook

Run the executable:

./orderbook

Expected example output:

Buy Orders: 1
Sell Orders: 1


---

# Next Planned Features

The following improvements will be implemented next:

1. Implement **price–time priority**
2. Replace vectors with **price‑sorted containers**
3. Implement **limit order matching**
4. Add **market order support**
5. Print **trade execution results**
6. Add **stdin/file input for orders**

---