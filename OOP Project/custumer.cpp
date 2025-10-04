#include <iostream>
#include "custumer.h"
#include <fstream>
using namespace std;

void custumer::displayDashboard()
{
    int choice;
    do
    {
        // Clear the screen
        system("cls");

        // Display the dashboard menu
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << CYAN << "*           CUSTOMER DASHBOARD          *" << RESET << endl;
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << YELLOW << "Welcome, " << GREEN << username << YELLOW << "!" << RESET << endl;
        cout << setw(50) << MAGENTA << "Please choose an option:" << RESET << endl;
        cout << setw(50) << YELLOW << "1. View Full Menu" << RESET << endl;
        cout << setw(50) << YELLOW << "2. View Menu by Category" << RESET << endl;
        cout << setw(50) << YELLOW << "3. Place an Order" << RESET << endl;
        cout << setw(50) << YELLOW << "4. Demand Bill" << RESET << endl;
        cout << setw(50) << YELLOW << "5. Profile " << RESET << endl;

        cout << setw(50) << YELLOW << "6. Exit" << RESET << endl;
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << MAGENTA << "Enter your choice (1-5): " << RESET;

        cin >> choice;

        // Validate user input
        while (cin.fail() || choice < 1 || choice > 6)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid choice. Please enter a valid option (1-5): " << RESET;
            cin >> choice;
        }

        // Perform actions based on the user's choice
        switch (choice)
        {
        case 1:
        {
            // View the full menu
            menu obj;
            viewMenu(obj);
            break;
        }
        case 2:
        {
            // View menu by category
            menu obj;

            viewMenuByCategory(obj);
            break;
        }
        case 3:
        {
            // Place an order
            cout << GREEN << "Placing your order..." << RESET << endl;
            cout << endl
                 << endl
                 << endl;

            menu obj;
            viewMenu(obj);
            orderMenu();
            break;
        }
        case 4:
        {
            // Demand a bill
            generateBill();
            break;
        }
        case 5:
        {
            // Profile
            profile();

            break;
        }
        case 6:
        {
            // Exit
            cout << GREEN << "Thank you for visiting! Goodbye." << RESET << endl;
            break;
        }
        }

        // Add a pause before returning to the dashboard
        if (choice != 6)
        {
            cout << YELLOW << "\nPress Enter to return to the dashboard..." << RESET;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (choice != 6);
}

void custumer::setData(string name)
{
    username = name;
    ifstream adminData("custumer.txt");
    int user_id;
    string user_name, f_name, l_name, user_email, user_password, user_role;
    while (adminData >> user_id >> user_name >> f_name >> l_name >> user_email >> user_password >> user_role)
    {
        if (user_name == name)
        {
            id = user_id;
            first_name = f_name;
            last_name = l_name;
            email = user_email;
            password = user_password;
            role = user_role;
        }
    }
    adminData.close();
}

void custumer::viewMenu(class menu &obj)
{
    obj.fullMenu();
}

void custumer::viewMenuByCategory(class menu &obj)
{
    string category;
    cout << BLUE << "Enter the category (e.g., desi, fast_food, drinks, sweets, ice_cream): " << RESET;
    cin >> category;
    obj.menuByCategory(category);
}

void custumer::profile()
{
    cout << endl
         << endl
         << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << setw(50) << CYAN << "*                MY PROFILE               *" << RESET << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << setw(50) << MAGENTA << "User ID: " << RESET << id << endl;
    cout << setw(50) << MAGENTA << "Username: " << RESET << username << endl;
    cout << setw(50) << MAGENTA << "First Name: " << RESET << first_name << endl;
    cout << setw(50) << MAGENTA << "Last Name: " << RESET << last_name << endl;
    cout << setw(50) << MAGENTA << "Email: " << RESET << email << endl;
    cout << setw(50) << MAGENTA << "Role: " << RESET << role << endl;
    cout << setw(50) << MAGENTA << "=========================" << RESET << endl;
}

void custumer::orderMenu()
{
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << setw(50) << CYAN << "*               Place Order             *" << RESET << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << endl
         << endl;
    cout << setw(50) << MAGENTA << "------------------------------------------------" << RESET << endl;
    cout << setw(50) << RED << "NOTICE!!!! Enter ID of Item to place Order and type '0' to stop ordering." << RESET << endl;
    cout << setw(50) << MAGENTA << "------------------------------------------------" << RESET << endl;
    cout << endl
         << endl;

    string item_id;
    int quantity;

    do
    {
        cout << setw(50) << MAGENTA << "Enter ID: " << RESET;
        cin >> item_id;
        if (item_id == "0")
        {
            break;
        }

        cout << setw(50) << MAGENTA << "Enter Quantity: " << RESET;
        cin >> quantity;

        if (quantity <= 0)
        {
            cout << RED << "Error: Quantity must be greater than 0!" << RESET << endl;
            continue;
        }

        ifstream menu("food_items.txt");
        ofstream temp("temp.txt"); // Temporary file to store updated data
        ofstream order("order.txt", ios::app);

        if (!menu.is_open() || !temp.is_open() || !order.is_open())
        {
            cout << RED << "Error: Unable to open file(s)!" << RESET << endl;
            return;
        }

        string food_id, food_name, food_category, food_price, food_discount, food_availability, food_quantity;
        bool found = false;

        while (menu >> food_id >> food_name >> food_category >> food_price >> food_discount >> food_availability >> food_quantity)
        {
            if (food_id == item_id)
            {
                int available_quantity = stoi(food_quantity);

                if (available_quantity >= quantity)
                {
                    found = true;
                    int updated_quantity = available_quantity - quantity;

                    // Write updated food item to temp file
                    temp << food_id << " " << food_name << " " << food_category << " "
                         << food_price << " " << food_discount << " "
                         << food_availability << " " << updated_quantity << endl;

                    // Write order details to order.txt
                    order << id << " " << food_id << " " << food_name
                          << " " << food_category << " " << food_price
                          << " " << food_discount << " " << quantity << endl;

                    cout << GREEN << "Order placed successfully for " << food_name << "!" << RESET << endl;
                }
                else
                {
                    cout << RED << "Error: Insufficient stock for " << food_name << "!" << RESET << endl;
                    temp << food_id << " " << food_name << " " << food_category << " "
                         << food_price << " " << food_discount << " "
                         << food_availability << " " << food_quantity << endl;
                }
            }
            else
            {
                // Write unchanged food item to temp file
                temp << food_id << " " << food_name << " " << food_category << " "
                     << food_price << " " << food_discount << " "
                     << food_availability << " " << food_quantity << endl;
            }
        }

        if (!found)
        {
            cout << RED << "Error: Item ID " << item_id << " not found!" << RESET << endl;
        }
        if (remove("food_items.txt") != 0)
        {
            cout << "Error deleting the existing file";
            cout << endl;
        }

        // Rename the temporary file
        if (rename("food_items.txt", "temp.txt") != 0)
        {
            cout << "Error renaming the file";
            cout << endl;
        }
        else
        {
            cout << "File renamed successfully!\n";
        }
        menu.close();
        temp.close();
        order.close();

        // Replace original file with updated file
        remove("food_items.txt");
        rename("temp.txt", "food_items.txt");

    } while (true);

    cout << GREEN << "Thank you for your orders!" << RESET << endl;
}

void custumer::generateBill()
{
    ifstream bill("order.txt");
    if (!bill.is_open())
    {
        cout << "\033[31m" << "Error: Unable to open file order.txt!" << "\033[0m" << endl;
        return;
    }

    string cus_id, food_id, food_name, food_category;
    int food_quantity;
    double food_price, food_discount;
    double total_bill = 0.0;

    // Header
    cout << endl
         << endl;
    cout << setw(50) << "\033[36m" << "*****************************************" << "\033[0m" << endl;
    cout << setw(50) << "\033[36m" << "*                 BILL                  *" << "\033[0m" << endl;
    cout << setw(50) << "\033[36m" << "*****************************************" << "\033[0m" << endl
         << endl;

    // Assuming the first entry in the file contains customer information
    if (!(bill >> cus_id))
    {
        cout << "\033[31m" << "Error: Missing or invalid customer ID in the file." << "\033[0m" << endl;
        bill.close();
        return;
    }
    cout << setw(45) << "\033[35m" << "Customer ID: " << cus_id << "\033[0m" << endl
         << endl;

    // Table header
    cout << setw(45) << "\033[32m" << "Food ID"
         << setw(25) << "Food Name"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << "\033[0m" << endl;
    cout << setw(65) << setfill('-') << "-" << setfill(' ') << "\033[0m" << endl;

    // Process each food item in the order
    while (bill >> food_id >> food_name >> food_category >> food_price >> food_discount >> food_quantity)
    {
        double price = food_price;
        double discount = food_discount;
        int quantity = food_quantity;

        double discounted_price = price * (1 - (discount / 100.0));
        total_bill += discounted_price * quantity;

        // Replace underscores in food names with spaces
        for (char &ch : food_name)
        {
            if (ch == '_')
                ch = ' ';
        }

        // Print food item details
        cout << setw(45) << "\033[36m" << food_id
             << setw(25) << food_name
             << setw(10) << quantity
             << setw(10) << fixed << setprecision(2) << discounted_price << "\033[0m" << endl;
    }

    cout << setw(45) << setw(65) << setfill('-') << "-" << setfill(' ') << "\033[0m" << endl;

    // Display total bill
    cout << setw(45) << "\033[35m" << "\nTotal Bill: " << fixed << setprecision(2) << total_bill << "\033[0m" << endl;
    cout << setw(50) << "\033[36m" << "*****************************************" << "\033[0m" << endl;

    bill.close();
}