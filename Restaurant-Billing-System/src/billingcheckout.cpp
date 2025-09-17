/***********************************************************************
* billingcheckout.cpp
* Billing checkout program for restaurant chain
* Pritam Gurung
* Version 2.0
**********************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime> // for time/ctime

struct MenuItem {
  int itemNo;
  std::string name;
  std::string description;
  double price;
};

// Load colon-delimited menu into memory
void loadMenu(std::vector<MenuItem>& menu, const std::string& filename) {
  std::ifstream fileIn(filename);
  if (!fileIn) {
    std::cerr << "Error opening menu file.\n";
    return;
  }

  MenuItem item;
  std::string line;
  while (std::getline(fileIn, line)) {
    std::stringstream ss(line);
    std::getline(ss, line, ':');   // itemNo
    item.itemNo = std::stoi(line);
    std::getline(ss, item.name, ':');
    std::getline(ss, item.description, ':');
    std::getline(ss, line);        // price
    item.price = std::stod(line);
    menu.push_back(item);
  }
}

// Show menu items with prices
void displayMenu(const std::vector<MenuItem>& menu) {
  std::cout << "\nMenu Items:\n";
  for (const auto& item : menu) {
    std::cout << item.itemNo << ": " << item.name
              << " - " << item.description << " - $"
              << std::fixed << std::setprecision(2)
              << item.price << "\n";
  }
  std::cout << std::endl;
}

// Basic VAT calculator (20%)
double calculateVAT(double amount) {
  const double VAT_RATE = 0.20;
  return amount * VAT_RATE;
}

// Append the bill text and totals to a transaction file
void saveBillToFile(const std::string& transactionFile, const std::string& billText, double total) {
  std::ofstream outFile(transactionFile, std::ios::app);
  if (!outFile) {
    std::cerr << "Error opening transaction file.\n";
    return;
  }

  std::time_t now = std::time(nullptr);
  std::string datetime = std::ctime(&now); // includes newline

  outFile << "\n" << datetime;
  outFile << billText;
  outFile << "Grand Total: $" << std::fixed << std::setprecision(2) << total << "\n";
  outFile << "-------------------------\n";

  std::cout << "Bill saved to transactions file.\n";
}

// Take orders, build bill, compute totals, save
void processOrder(const std::vector<MenuItem>& menu, const std::string& transactionFile) {
  displayMenu(menu);
  std::cout << "Enter item numbers and quantities (0 to finish):\n";

  int itemNo, quantity;
  double subtotal = 0.0;
  std::ostringstream bill; // build printable bill text

  while (true) {
    std::cout << "Item number (0 to finish): ";
    std::cin >> itemNo;
    if (itemNo == 0) break;

    std::cout << "Quantity: ";
    std::cin >> quantity;

    bool found = false;
    for (const auto& item : menu) {
      if (item.itemNo == itemNo) {
        double itemTotal = item.price * quantity;
        subtotal += itemTotal;
        bill << item.itemNo << " x " << quantity << " "
             << item.name << " - $" << std::fixed << std::setprecision(2)
             << itemTotal << "\n";
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "Invalid item number. Please select a valid one.\n";
    }
  }

  double vat = calculateVAT(subtotal);
  double total = subtotal + vat;

  bill << "Subtotal: $" << std::fixed << std::setprecision(2) << subtotal << "\n";
  bill << "VAT: $"      << std::fixed << std::setprecision(2) << vat      << "\n";
  bill << "Total: $"    << std::fixed << std::setprecision(2) << total    << "\n";

  std::cout << "\nBill:\n" << bill.str();
  saveBillToFile(transactionFile, bill.str(), total);
}

int main() {
  std::vector<MenuItem> menu;
  std::string menuFilename = "menu.txt";
  std::string transactionFilename = "transactions.txt";

  loadMenu(menu, menuFilename);
  processOrder(menu, transactionFilename);
  return 0;
}
