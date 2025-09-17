# Restaurant Billing System

A three-part **C++ console application** that manages a restaurant’s menu, customer billing, and end-of-day sales reporting.

## Overview
This project was designed and implemented using **object-oriented principles** and standard C++ data structures.  
It demonstrates the full development cycle: requirements analysis, program design, coding, testing, and evaluation.

The system is divided into three standalone programs:

### 1. Menu Creator
*Purpose:* Used by head office to create and maintain a digital menu.  
*Highlights:*
- Stores menu items in a `std::vector` of custom structs.
- Supports adding, displaying, loading, and saving items in the format  
  `ItemNo:Category:Description:Price`.

### 2. Billing Checkout
*Purpose:* Used in each restaurant to generate customer bills.  
*Highlights:*
- Reads the menu file and displays items with numbers and prices.
- Accepts item selections and quantities, calculates subtotal, VAT (20 %), and grand total.
- Appends a time-stamped bill to a daily `transactions.txt` file.

### 3. Daily Statistics
*Purpose:* Used by head office to analyse daily sales.  
*Highlights:*
- Reads all transactions for the day.
- Uses a `std::map` to count orders per item and compute total revenue.
- Displays a concise report of item counts and grand total takings.

## Key Technical Features
- **Object-Oriented Design:** separation of concerns across three programs.
- **Data Structures:** `std::vector` for dynamic menus; `std::map` for aggregating sales.
- **File I/O:** persistent storage for menus and transactions using plain-text files.
- **Robust Testing:** structured test plans and logs to validate each program’s functionality.


## Build & Run
Compile each component separately with a standard C++ compiler (e.g. g++):

```bash
g++ src/menu.cpp -o menu
./menu           # create or edit menu

g++ src/billingcheckout.cpp -o billing
./billing        # generate customer bills

g++ src/transactionstatsfile.cpp -o stats
./stats          # view daily sales statistics
```

## What This Demonstrates
- Ability to **design, implement, and test** a complete software system.
- Competence with **C++ OOP, STL containers, and file handling**.
- Clear documentation and professional repository organization suitable for internships or entry-level software roles.
