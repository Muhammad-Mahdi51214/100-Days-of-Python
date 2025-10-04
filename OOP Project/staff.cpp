#include <iostream>
#include "staff.h"
#include <fstream>

using namespace std;

void staff::displayDashboard() {
    int choice;
   
    do {
        // Clear the screen
        system("cls");

        // Center the dashboard menu
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << CYAN << "*             Staff Dashboard           *" << RESET << endl;
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << YELLOW << "1. Display All Custumers " << RESET << endl;
        cout << setw(50) << YELLOW << "2. Display All Orders" << RESET << endl;
        cout << setw(50) << YELLOW << "3. Serve Custumer" << RESET << endl;
        cout << setw(50) << YELLOW << "4. Generate Bill" << RESET << endl;
        cout << setw(50) << YELLOW << "5. Profile" << RESET << endl;
        // cout << setw(50) << YELLOW << "6. Display All Customers" << RESET << endl;
        cout << setw(50) << YELLOW << "6. Exit" << RESET << endl;
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << MAGENTA << "Enter your choice (1-6): " << RESET;
        cin >> choice;

        // Handle invalid input
        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid input! Please enter a number between 1 and 9." << RESET << endl;
            cin.get(); // Wait for user to press Enter
            continue;
        }

        // Execute the selected action
        switch (choice) {
            case 1: 
                displayAllCustumers();
                break;

            case 2: 
                displayAllOrders();
                break;

            case 3: 
                cout<<endl<<endl;
                displayAllOrders();
                cout<<endl<<endl;
                int cus_id;
                cout << BLUE << "Enter Id of Custumer to serve Custumer : " << RESET;
                cin >> cus_id;
                serveCustumer(cus_id);
                break;

            case 4: 
            { 
                 cout<<endl<<endl;
                int cus_id;
                cout << BLUE << "Enter Id of Custumer to serve Bill : " << RESET;
                cin >> cus_id;
                generateBill(cus_id);
                break;
            }

            case 5: 
                profile();
                break;

            
            case 6: 
                cout << GREEN << "Exiting Staff dashboard. Have a great day!" << RESET << endl;
                break;

            default:
                cout << RED << "Invalid choice! Please try again." << RESET << endl;
                break;
        }

        // Add a pause before returning to the dashboard (except on exit)
        if (choice != 6) {
            cout << YELLOW << "\nPress Enter to return to the dashboard..." << RESET;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (choice != 6);
}

void staff::setData(string name)
{
    username=name;
    ifstream adminData("staff.txt");
    int user_id;
    string user_name, f_name, l_name, user_email, user_password, user_role;
   while (adminData >> user_id >> user_name >> f_name >> l_name >> user_email >> user_password >> user_role) {
            if(user_name==name)
            {
                id=user_id;
                first_name=f_name;
                last_name=l_name;
                email=user_email;
                password=user_password;
                role=user_role;
            }
        }
        adminData.close();

}

void staff::profile() {
     cout<<endl<<endl<<endl;
    cout << setw(50) << CYAN <<"*****************************************" << RESET << endl;
    cout <<setw(50) << CYAN << "*                MY PROFILE               *" << RESET << endl;
    cout <<setw(50) << CYAN << "*****************************************" << RESET<<endl;
    cout << setw(50) << MAGENTA << "User ID: " << RESET << id << endl;
    cout << setw(50) << MAGENTA << "Username: " << RESET << username << endl;
    cout << setw(50) << MAGENTA << "First Name: " << RESET << first_name << endl;
    cout << setw(50) << MAGENTA << "Last Name: " << RESET << last_name << endl;
    cout << setw(50) << MAGENTA << "Email: " << RESET << email << endl;
    cout << setw(50) <<MAGENTA  << "Role: " << RESET << role << endl;
    cout << setw(50) << MAGENTA << "=========================" << RESET << endl;
}

void staff::displayAllCustumers() {
    ifstream customerFile("custumer.txt");
    if (!customerFile.is_open()) {
        cout<<endl<<endl<<endl;
        cout << RED << "Error: Unable to open customer file!" << RESET << endl;
        return;
    }

    // Print header
    cout<<endl<<endl<<endl;
    cout << setw(50) << CYAN <<"*****************************************" << RESET << endl;
    cout <<setw(50) << CYAN << "*             Customer List             *" << RESET << endl;
    cout <<setw(50) << CYAN << "*****************************************" << RESET<<endl;
    cout << left << setw(35) << "ID" 
         << setw(20) << "Name" 
         << setw(30) << "Email" 
         << setw(10) << "Role" << endl;
    cout <<setw(35)<<YELLOW << "-----------------------------------------------------------------" << RESET<< endl;

    string id, first_name, last_name, email, password, role;

    // Reading file line by line
    while (customerFile >> id >> first_name >> last_name >> email >> password >> role) {
        string fullName = first_name + " " + last_name;  // Combine first and last name
        cout << left << setw(35) << id 
             << setw(20) << fullName 
             << setw(30) << email 
             << setw(10) << role << endl;
    }

    customerFile.close();
}


void staff::serveCustumer(int customerID) {
    ifstream inputFile("order.txt");
    ofstream tempFile("temp.txt"); // Temporary file to store updated data

    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int cus_id, food_id;
    string food_name, food_category;
    double food_price, food_discount;
    int food_quantity;

    bool customerFound = false;

    while (inputFile >> cus_id >> food_id >> food_name >> food_category >> food_price >> food_discount >> food_quantity) {
        if (cus_id == customerID) {
            customerFound = true;
            cout << "Customer " << customerID << " has been served Sucessfully.." << endl;
            // Skip writing this customer's data to the temp file
        } else {
            // Write other customers' data to the temp file
            tempFile << cus_id << " " << food_id << " " << food_name << " " << food_category << " "
                     << food_price << " " << food_discount << " " << food_quantity << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (customerFound) {
        // Replace original file with updated file
        if (remove("order.txt") != 0) {
            cerr << "Error deleting original file." << endl;
            return;
        }
        if (rename("temp.txt", "order.txt") != 0) {
            cerr << "Error renaming temporary file." << endl;
        }
    } else {
        cout << "Customer ID " << customerID << " not found." << endl;
        remove("temp.txt"); // Remove temp file as no changes are needed
    }
}
void staff::generateBill(int custumer_id) 
{
    ifstream bill("order.txt");
    if (!bill.is_open()) {
        cout << RED << "Error: Unable to open file order.txt!" << RESET << endl;
        return;
    }

    string  food_id, food_name, food_category;
    int cus_id,food_quantity;
    double food_price,food_discount;
    double total_bill = 0.0;

    // Header
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << setw(50) << CYAN << "*                 BILL                  *" << RESET << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl << endl;

    // Assuming the first entry in the file contains customer information
    
    
        cout << MAGENTA << "Customer ID: " << custumer_id << RESET << endl << endl;
    
    

    // Table header
    cout << setw(45) << GREEN << "Food ID"
         << setw(20) << "Food Name"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << RESET << endl;
    cout << setw(33) << YELLOW << "-------------------------------------------------------------" << RESET << endl;

    // Process each food item in the order
    while (bill >> cus_id>> food_id >> food_name >> food_category >> food_price >> food_discount >> food_quantity) {
        if(cus_id==custumer_id)
        {
            double price = food_price;
        double discount = food_discount/ 100.0;
        double discounted_price = price * (1 - discount);
        int quantity = food_quantity;
        total_bill += discounted_price * quantity;

        // Replace underscores in food names with spaces
        for (char &ch : food_name) {
            if (ch == '_') 
              ch = ' ';
        }

        // Print food item details
        cout << setw(45) << CYAN << food_id
             << setw(20) << food_name
             << setw(10) << quantity
             << setw(10) << fixed << setprecision(2) << discounted_price << RESET << endl;
        }
        
    }

    cout << setw(45) << YELLOW << "-------------------------------------------------------------" << RESET << endl;

    // Display total bill
    cout << MAGENTA << "\nTotal Bill: " << fixed << setprecision(2) << total_bill << RESET << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;

    bill.close();
}



void staff::displayAllOrders()
{
     
    ifstream inputFile("order.txt");

    if (!inputFile.is_open()) {
        cerr << RED << "Error opening file!" << RESET << endl;
        return;
    }

    int cus_id, food_id;
    string food_name, food_category;
    double food_price, food_discount;
    int food_quantity;

    
    cout<<endl<<endl<<endl;
    cout << setw(50) << CYAN <<"*****************************************" << RESET << endl;
    cout <<setw(50) << CYAN << "*               All Orders              *" << RESET << endl;
    cout <<setw(50) << CYAN << "*****************************************" << RESET<<endl;
    cout << YELLOW;
    cout << setw(45) << "CustomerID" << setw(10) << "FoodID" << setw(15) << "FoodName" << setw(15) << "Category"
         << setw(10) << "Price" << setw(10) << "Discount" << setw(10) << "Quantity" << endl;
    cout << RESET;

    while (inputFile >> cus_id >> food_id >> food_name >> food_category >> food_price >> food_discount >> food_quantity) {
        cout << setw(45) << cus_id << setw(10) << food_id << setw(15) << food_name << setw(15) << food_category
             << setw(10) << food_price << setw(10) << food_discount << setw(10) << food_quantity << endl;
    }

    inputFile.close();

}