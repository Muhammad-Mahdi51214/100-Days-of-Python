#include <iostream>
#include <fstream>
#include <iomanip>
#include "menu.h"

using namespace std;

void menu::fullMenu() {
    ifstream menu("food_items.txt");
    if (!menu.is_open()) {
        cout << RED << "Error: Unable to open file!" << RESET << endl;
        return;
    }

    // Header
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << setw(50) << CYAN << "*               Full Menu               *" << RESET << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl << endl;

    // Table header
    cout  <<setw(35) << RED << "ID"
         << setw(20) << "Food Name"
         << setw(30) << "Category"
         << setw(15) << "Price" << RESET << endl;
    cout << setw(33)<< YELLOW << "-------------------------------------------------------------" << RESET << endl;

    // Variables to read file data
    string id, food_name, food_category, food_price, food_discount, food_availablity, food_quantity;

    while (menu >> id >> food_name >> food_category >> food_price >> food_discount >> food_availablity >> food_quantity) {
        if (food_availablity == "true") {
            // Replace underscores in food names with spaces
            for (char &ch : food_name) {
                if (ch == '_') ch = ' ';
            }

            // Print the available food item
            cout  <<setw(40) << MAGENTA << id
                 << setw(20) << food_name
                 << setw(15) << food_category
                 << setw(15) << food_price << RESET << endl;
        }
    }

    menu.close();
}



void menu:: menuByCategory(string ctgry) {
    ifstream menu("food_items.txt");
    if (!menu.is_open()) {
        cout << RED << "Error: Unable to open file!" << RESET << endl;
        return;
    }

    // Header for the category menu
    cout << setw(60) << CYAN << "*****************************************" << RESET << endl;
    cout << setw(60) << CYAN << "*   Menu of " << ctgry << " Category   *" << RESET << endl;
    cout << setw(60) << CYAN << "*****************************************" << RESET << endl << endl;

    // Table header
    cout << setw(25) << RED << "ID"
         << setw(25) << "Food Name"
         << setw(25) << "Category"
         << setw(25) << "Price" << RESET << endl;
    cout << setw(25) << YELLOW << "----------------------------------------------------------------" << RESET << endl;

    // Variables to read file data
    string id, food_name, food_category, food_price, food_discount, food_availablity, food_quantity;

    bool found = false;  // Flag to track if any items are found

    while (menu >> id >> food_name >> food_category >> food_price >> food_discount >> food_availablity >> food_quantity) {
        if (food_availablity == "true" && food_category == ctgry) {
            // Replace underscores in food names with spaces
            for (char &ch : food_name) {
                if (ch == '_') ch = ' ';
            }

            // Print the food item
            cout << setw(25) << MAGENTA << id
                 << setw(25) << food_name
                 << setw(25) << food_category
                 << setw(25) << food_price << RESET << endl;
            found = true;
        }
    }

    if (!found) {
        cout << RED << "\nNo available food items found in the " << ctgry << " category." << RESET << endl;
    }

    menu.close();
}


void menu::check_low_stock()
{
    ifstream food_file("food_items.txt");
    if (!food_file.is_open())
    {
        cout << RED << "\n===============================" << endl;
        cout << "   ERROR: Unable to open food_items file!" << endl;
        cout << "===============================\n" << RESET << endl;
        return;
    }

    // Threshold for low stock (can be adjusted as needed)
    const int threshold = 10; // Example threshold

    // Temporary file for storing low-stock items
    ofstream temp_file("temp_low_stock_items.txt");
    if (!temp_file.is_open())
    {
        cout << RED << "\n===============================" << endl;
        cout << "   ERROR: Unable to create temporary file!" << endl;
        cout << "===============================\n" << RESET << endl;
        food_file.close();
        return;
    }

    string id, food_name, food_category, food_price, food_discount, food_availability, food_quantity;
    bool low_stock_found = false;

    while (food_file >> id >> food_name >> food_category >> food_price >> food_discount >> food_availability >> food_quantity)
    {
        int quantity = stoi(food_quantity);
        if (quantity <= threshold)
        {
            low_stock_found = true;
            temp_file << id << " " << food_name << " " << food_category << " " << food_price << " " << food_discount << " " << food_availability << " " << food_quantity << "\n";
        }
    }

    food_file.close();
    temp_file.close();

    // Display the low-stock items to the admin
    if (!low_stock_found)
    {
        cout << GREEN << "\n===============================" << endl;
        cout << "   All items are sufficiently stocked." << endl;
        cout << "===============================\n" << RESET << endl;
    }
    else
    {
        ifstream display_file("temp_low_stock_items.txt");
        if (!display_file.is_open())
        {
            cout << RED << "\n===============================" << endl;
            cout << "   ERROR: Unable to read temporary file!" << endl;
            cout << "===============================\n" << RESET << endl;
            return;
        }

        cout << CYAN << "\n===============================" << endl;
        cout << "   ALERT: Low Stock Items" << endl;
        cout << "===============================\n" << RESET << endl;

        // Centered Table Header
        cout << setw(33) << " " << YELLOW << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Category" << setw(10) << "Price" << setw(10) << "Discount" << setw(15) << "Availability" << setw(10) << "Quantity" << RESET << endl;
        cout << setw(60) << " " << string(90, '-') << endl;

        // Print each low-stock item
        while (display_file >> id >> food_name >> food_category >> food_price >> food_discount >> food_availability >> food_quantity)
        {
            cout << setw(33) << " " << MAGENTA << left << setw(10) << id << setw(20) << food_name << setw(15) << food_category << setw(10) << food_price << setw(10) << food_discount << setw(15) << food_availability << setw(10) << food_quantity << RESET << endl;
        }

        display_file.close();

        // Remove the temporary file after use
        if (remove("temp_low_stock_items") != 0)
        {
            cout << RED << "\nERROR: Unable to delete temporary file!" << RESET << endl;
        }

        cout << GREEN << "\nPlease restock these items immediately!" << RESET << endl;
    }
}
