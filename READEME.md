# Limit Order Book Engine (C++)

This project implements a simple **in‑memory limit order book (LOB)** for a single financial instrument.  
The engine processes buy and sell orders, maintains separate books for bids and asks, and performs **automatic trade matching using price–time priority**.

The system simulates the **core mechanics used in real electronic trading systems**:

• Order storage  
• Price–time priority  
• Limit and Market orders  
• Trade execution  
• Partial fills  
• Order cancellation  
• Order book depth display  

The repository was built **incrementally with structured commits**, each introducing a component of the matching engine.

---

# Implemented Features

The engine currently supports the following commands:

### LIMIT Order
Adds an order to the book.

```
LIMIT BUY <price> <quantity>
LIMIT SELL <price> <quantity>
```

Example:

```
LIMIT BUY 100 10
LIMIT SELL 101 5
```

---

### MARKET Order
Immediately consumes liquidity from the opposite side of the book.

```
MARKET BUY <quantity>
MARKET SELL <quantity>
```

Example:

```
MARKET BUY 7
```

Execution example:

```
TRADE 5 @ 101
TRADE 2 @ 102
```

---

### CANCEL Order
Cancels an existing order using its `order_id`.

```
CANCEL <order_id>
```

Example:

```
CANCEL 3
```

Output:

```
CANCELLED 3
```

---

### BOOK Command
Displays the current state of the order book.

```
BOOK
```

Example output:

```
Bids:
100 : 10

Asks:
101 : 5
102 : 3
```

The book displays **total quantity per price level**, similar to real exchange order books.

---

# Matching Logic

Orders are matched using **price–time priority**.

For a trade to occur:

```
Best Bid >= Best Ask
```

Trade quantity is determined as:

```
min(buy_quantity, sell_quantity)
```

The engine supports:

• Partial fills  
• Multi‑level price matching  
• Automatic removal of filled orders  

Example:

```
LIMIT SELL 101 5
LIMIT SELL 102 5
MARKET BUY 7
```

Produces:

```
TRADE 5 @ 101
TRADE 2 @ 102
```

Remaining book:

```
Asks:
102 : 3
```

---

# Project Structure

```
project/
│
├── include/
│   ├── Order.h
│   └── OrderBook.h
│
├── src/
│   ├── main.cpp
│   └── OrderBook.cpp
│
├── README.md
└── .gitignore
```

### include/

Contains header files defining:

• `Order` structure  
• `OrderBook` class interface  

### src/

Contains the implementation:

• `main.cpp` — CLI input parser and command execution  
• `OrderBook.cpp` — matching engine implementation  

---

# Build Instructions

Compile from the project root:

```
g++ src/*.cpp -Iinclude -std=c++17 -o orderbook
```

Run interactively:

```
./orderbook
```

---

# Running With Input File

You can also run the engine using a batch input file:

```
./orderbook < orders.txt
```

Example `orders.txt`:

```
LIMIT BUY 100 10
LIMIT SELL 101 5
MARKET BUY 3
BOOK
```

---

# Example Interactive Session

```
LIMIT SELL 101 5
LIMIT SELL 102 5
MARKET BUY 7
BOOK
```

Output:

```
TRADE 5 @ 101
TRADE 2 @ 102

Bids:

Asks:
102 : 3
```

---

# Key Concepts Demonstrated

• Order book data structures  
• Price–time priority matching  
• Market vs limit order behavior  
• Partial trade execution  
• Order cancellation  
• CLI command parsing  
• Incremental development with Git  

---

# Possible Future Enhancements

Potential improvements to extend the engine:

• `MODIFY <order_id> <price> <qty>` command  
• O(1) order cancellation using an order index map  
• Order book snapshots  
• Latency measurements for matching  
• Support for multiple instruments  

---

# Summary

This project demonstrates the **core architecture of a matching engine used in modern exchanges** while maintaining a clean modular C++ structure and readable Git history.