/***********************************************************************
* menu.cpp
* Program for head office to create and save a restaurant menu
* Pritam Gurung
* Version 1.0
**********************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

struct MenuItem {
  int itemNo;
  std::string category;
  std::string description;
  double price;
};

// Show all items currently in memory
void displayMenu(const std::vector<MenuItem>& menu) {
  std::cout << "\nCurrent Menu:\n";
  for (const auto& item : menu) {
    std::cout << "Item " << item.itemNo << ": "
              << item.category << " - "
              << item.description << " - $"
              << item.price << "\n";
  }
  std::cout << std::endl;
}

// Prompt user and append an item
void addMenuItem(std::vector<MenuItem>& menu) {
  MenuItem newItem;
  std::cout << "Enter item number: ";
  std::cin >> newItem.itemNo;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Enter category (Main Course, Dessert, Drinks): ";
  std::getline(std::cin, newItem.category);

  std::cout << "Enter item description: ";
  std::getline(std::cin, newItem.description);

  std::cout << "Enter item price: ";
  std::cin >> newItem.price;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  menu.push_back(newItem);
  std::cout << "Menu item added.\n\n";
}

// Load items from a colon-delimited file: itemNo:category:description:price
void loadMenuFromFile(std::vector<MenuItem>& menu, const std::string& filename) {
  std::ifstream fileIn(filename);
  if (!fileIn) {
    std::cout << "Could not open file for reading.\n";
    return;
  }
  menu.clear();

  std::string line;
  while (std::getline(fileIn, line)) {
    std::stringstream ss(line);
    MenuItem item;
    std::getline(ss, line, ':');        // itemNo
    item.itemNo = std::stoi(line);
    std::getline(ss, item.category, ':');
    std::getline(ss, item.description, ':');
    std::getline(ss, line);             // price
    item.price = std::stod(line);
    menu.push_back(item);
  }
  std::cout << "Menu loaded from file.\n\n";
}

// Save items to the colon-delimited format
void saveMenuToFile(const std::vector<MenuItem>& menu, const std::string& filename) {
  std::ofstream fileOut(filename);
  if (!fileOut) {
    std::cout << "Could not open file for writing.\n";
    return;
  }
  for (const auto& item : menu) {
    fileOut << item.itemNo << ":"
            << item.category << ":"
            << item.description << ":"
            << item.price << "\n";
  }
  std::cout << "Menu saved to file.\n\n";
}

int main() {
  std::vector<MenuItem> menu;
  std::string filename = "menu.txt";
  char choice;

  // Simple console menu loop
  do {
    std::cout << "Menu Creation System\n"
              << "1. Display Menu\n"
              << "2. Add Menu Item\n"
              << "3. Load Menu from File\n"
              << "4. Save Menu to File\n"
              << "5. Exit\n"
              << "Enter your choice (1-5): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
      case '1': displayMenu(menu); break;
      case '2': addMenuItem(menu); break;
      case '3': loadMenuFromFile(menu, filename); break;
      case '4': saveMenuToFile(menu, filename); break;
      case '5': return 0; // quit
      default:
        std::cout << "Invalid choice. Please select 1-5.\n";
    }
  } while (true);
}
