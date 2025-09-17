/***********************************************************************
* transactionstatsfile.cpp
* Program to read and accumulate data from transaction files for
statistics
* Pritam Gurung
* Version 3.0
**********************************************************************/

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

// Read the transaction file and update per-item counts and grand total
void readTransactions(std::map<int, int>& itemOrders, double& grandTotal, const std::string& filename) {
  std::ifstream fileIn(filename);
  if (!fileIn) {
    std::cerr << "Error opening transactions file.\n";
    return;
  }

  std::string line;
  while (std::getline(fileIn, line)) {
    // Lines like: "Grand Total: $123.45"
    if (line.find("Grand Total: $") != std::string::npos) {
      std::size_t pos = line.find('$');
      if (pos != std::string::npos) {
        double total = std::stod(line.substr(pos + 1));
        grandTotal += total;
      }
    } else {
      // Lines like: "12 x 3 ItemName - $45.00"
      std::stringstream ss(line);
      int itemNo, quantity;
      char x;
      if ((ss >> itemNo >> x >> quantity) && (x == 'x')) {
        itemOrders[itemNo] += quantity;
      }
    }
  }
}

// Print per-item order counts and the grand total
void displayStatistics(const std::map<int, int>& itemOrders, double grandTotal) {
  std::cout << "\nDaily Statistics:\n";
  std::cout << "Number of Orders for Each Item:\n";
  for (const auto& order : itemOrders) {
    std::cout << "Item " << order.first << ": " << order.second << " orders\n";
  }
  std::cout << "Grand Total Takings: $" << std::fixed << std::setprecision(2) << grandTotal << std::endl;
}

int main() {
  std::map<int, int> itemOrders;   // key: item number, value: total qty
  double grandTotal = 0.0;
  std::string transactionsFilename = "transactions.txt";

  readTransactions(itemOrders, grandTotal, transactionsFilename);
  displayStatistics(itemOrders, grandTotal);
  return 0;
}
