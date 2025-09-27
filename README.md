# Restaurant Billing System (C++)

A three-part C++ application that manages a restaurant’s **menu creation**, **customer billing**,  
and **daily sales statistics**. Each module is a separate console program designed to work together.

Developed as a project to demonstrate **C++ programming**, **file I/O**,  
and **modular software design**.

---

## Project Overview

| Program | Purpose |
|--------|---------|
| **Menu Creation (`menu.cpp`)** | Head-office tool to build and maintain the restaurant menu. |
| **Billing Checkout (`billingcheckout.cpp`)** | Point-of-sale program to take customer orders, calculate totals with VAT, and save each transaction. |
| **Transaction Statistics (`transactionstatsfile.cpp`)** | End-of-day report generator summarising total sales and per-item order counts. |

The complete design, UI mock-ups, test plans, and evaluation are described in  
More on : [Project Assignment.pdf](Restaurant-Billing-System/docs/Project%20Assignment%20.pdf)

---

## Features

### 1. Menu Creation
* Add new menu items with **item number**, **category**, **description**, and **price**.
* Display current menu in a clean table.
* Save menu to `menu.txt` and load it back on demand.
* Input stored as colon-delimited text for easy sharing across programs.

### 2. Billing Checkout
* Reads menu from `menu.txt`.
* Lets cashier select item numbers and quantities until order completion.
* Calculates **subtotal**, **20 % VAT**, and **grand total** with currency formatting.
* Prints a detailed bill to the console and appends it to `transactions.txt` with a timestamp.

### 3. Daily Sales Statistics
* Parses `transactions.txt` to:
  * Count total orders for each item number.
  * Compute the **grand total takings**.
* Displays a concise daily report for management.

---

## Build

Any C++17-compatible compiler (GCC/Clang/MSVC) works.

```bash
# Menu creation
g++ -std=c++17 -O2 -Wall -Wextra -o menu menu.cpp

# Billing checkout
g++ -std=c++17 -O2 -Wall -Wextra -o billing billingcheckout.cpp

# Daily statistics
g++ -std=c++17 -O2 -Wall -Wextra -o stats transactionstatsfile.cpp
```

This produces three executables: `menu`, `billing`, and `stats`.

---

## Run

### 1 Create or Edit Menu
```bash
./menu
```
Follow prompts to add items or load/save from `menu.txt`.

### 2 Checkout Orders
```bash
./billing
```
* Loads the menu.
* Enter item numbers and quantities (0 to finish).
* View printed bill and confirm that `transactions.txt` is updated.

### 3 View Daily Statistics
```bash
./stats
```
* Reads all saved transactions.
* Outputs number of orders per item and the grand total revenue.

---

## Example Workflow

1. **Head office** builds the menu with `menu`.
2. **Cashier** runs `billing` throughout the day to record customer purchases.
3. **Manager** runs `stats` at close to see total takings and per-item counts.

---

## Repository Structure

```
├── menu.cpp                 # Program 1: Menu Creation
├── billingcheckout.cpp      # Program 2: Billing Checkout
├── transactionstatsfile.cpp # Program 3: Daily Sales Statistics
├── Project Assignment .pdf  # Full design, test plan, and evaluation
├── settings.json            
└── README.md
```

---

## Skills Demonstrated

* **Modern C++ (C++17)** – STL containers, streams, and string handling.
* **File I/O** – persistent storage and parsing of menu and transaction data.
* **Modular Architecture** – three independent yet cooperative programs.
* **Software Engineering** – UI design, test planning, and evaluation documented in the PDF.

---

## Future Improvements

* Stronger input validation and error handling (e.g., disallow negative prices or quantities).
* Richer output formatting with aligned columns and color.
* Merge into a single application with subcommands or GUI front-end.
* Database (SQLite) backend for scalability and concurrent access.

---

Developed by **Pritam Gurung**  
