#include <iostream>
#include <fstream>
#include "admin.h"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
using namespace std;


void admin::displayDashboard() {
    int choice;
    food foodObj; // Object to pass to editMenu
    menu menuObj; // Object to pass to viewMenu and viewMenuByCategory
   
    do {
        // Clear the screen
        system("cls");

        // Center the dashboard menu
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << CYAN << "*            Admin Dashboard           *" << RESET << endl;
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << YELLOW << "1. Add Staff" << RESET << endl;
        cout << setw(50) << YELLOW << "2. Edit Menu" << RESET << endl;
        cout << setw(50) << YELLOW << "3. View Full Menu" << RESET << endl;
        cout << setw(50) << YELLOW << "4. View Menu by Category" << RESET << endl;
        cout << setw(50) << YELLOW << "5. Check Inventory" << RESET << endl;
        cout << setw(50) << YELLOW << "6. Profile" << RESET << endl;
        cout << setw(50) << YELLOW << "7. Display All Staff" << RESET << endl;
        cout << setw(50) << YELLOW << "8. Display All Customers" << RESET << endl;
        cout << setw(50) << YELLOW << "9. Exit" << RESET << endl;
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << MAGENTA << "Enter your choice (1-9): " << RESET;
        cin >> choice;

        // Handle invalid input
        if (cin.fail() || choice < 1 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid input! Please enter a number between 1 and 9." << RESET << endl;
            cin.get(); // Wait for user to press Enter
            continue;
        }

        // Execute the selected action
        switch (choice) {
            case 1: // Add Staff
                if (addStaff()) {
                    cout << GREEN << "Staff added successfully!" << RESET << endl;
                } else {
                    cout << RED << "Failed to add staff. Please try again." << RESET << endl;
                }
                break;

            case 2: // Edit Menu
                editMenu(foodObj);
                break;

            case 3: // View Full Menu
                viewMenu(menuObj);
                break;

            case 4: { // View Menu by Category
                viewMenuByCategory(menuObj);
                break;
            }

            case 5: // Check Inventory
                checkInventory(menuObj);
                break;

            case 6: // Profile
                profile();
                break;

            case 7: // Display All Staff
                displayAllStaff();
                break;

            case 8: // Display All Customers
                displayAllCustumers();
                break;

            case 9: // Exit
                cout << GREEN << "Exiting admin dashboard. Have a great day!" << RESET << endl;
                break;

            default:
                cout << RED << "Invalid choice! Please try again." << RESET << endl;
                break;
        }

        // Add a pause before returning to the dashboard (except on exit)
        if (choice != 9) {
            cout << YELLOW << "\nPress Enter to return to the dashboard..." << RESET;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (choice != 9);
}

void admin::setData(string name)
{
    username=name;
    ifstream adminData("admin.txt");
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

bool admin::addStaff()
{
    int staff_id;
    string staff_name, staff_first_name, staff_last_name, staff_email, staff_password, staff_role;
    cout << endl;
    cout << YELLOW << "------ Add New Staff Member ------" << RESET << endl;
    cout << BLUE<< "Enter User Name: " << RESET<< endl;
    cin >> staff_name;
    cout << BLUE<< "Enter First Name: " << RESET<< endl;
    cin >> staff_first_name;
    cout << BLUE<< "Enter Last Name: " << RESET<< endl;
    cin >> staff_last_name;
    cout << BLUE<< "Enter Email: " << RESET<< endl;
    cin >> staff_email;
    cout << BLUE<< "Enter Password: " << RESET<< endl;
    cin >> staff_password;
    staff_role = "staff"; // Assign role as staff

    bool check = recordCheck("staff.txt");

    if (check) { // Username does not exist
        staff_id = checkId("staff.txt");
        ofstream file("staff.txt", ios::app);
        if (file.is_open()) {
            file << endl;
            file << staff_id << " " << staff_name << " " << staff_first_name << " " << staff_last_name << " "
                 << staff_email << " " << staff_password << " " << staff_role;
            file.close();
            cout << GREEN << "Staff member added successfully!" << RESET << endl;
            return true;
        } else {
            cout << RED << "Error: Unable to open file for saving data." << RESET << endl;
            return false;
        }
    } 
    else { // Username already exists
        cout << RED << "Oops! Username already exists. Please try again." << RESET << endl;
        return false;
    }
}

void admin::editMenu(class food& obj)
{
    char check;
    cout << BLUE << "------ Add Food to Menu ------" << RESET << endl;
    cout << "Would you like to add food? (y/n): ";
    cin >> check;
    if (check == 'y') {
        obj.addFood();
    }
    cout << BLUE << "------ Mark Food as Unavailable ------" << RESET << endl;
    cout << "Would you like to mark food as unavailable? (y/n): ";
    cin >> check;
    if (check == 'y') {
        obj.unAvailableFood();
    }
}

void admin::viewMenu(class menu& obj)
{
    cout<<endl<<endl<<endl;
    // cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    // cout << setw(50) << CYAN << "*        Menu of Available Foods        *" << RESET << endl;
    // cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    obj.fullMenu();
}

void admin::viewMenuByCategory(class menu& obj)
{
    cout<<endl<<endl<<endl;
    // cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    // cout << setw(50) << CYAN << "*          View Menu By Category        *" << RESET << endl;
    // cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    string category;
    cout << BLUE << "Enter the category (e.g., desi, fast_food, drinks, sweets, ice_cream): " << RESET;
    cin >> category;
    obj.menuByCategory(category);
}

void admin::checkInventory(class menu& obj)

{

    cout<<endl<<endl<<endl;
    // cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    // cout << setw(50) << CYAN << "*          Inventory Check              *" << RESET << endl;
    // cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    // Placeholder for inventory checking code
    obj.check_low_stock();
    
}

void admin::displayAllStaff() {
    ifstream staffFile("staff.txt");
    if (!staffFile.is_open()) {
        cout<<endl<<endl;
        cout << RED << "Error: Unable to open staff file!" << RESET << endl;
        return;
    }
    cout<<endl<<endl<<endl;
    // Print header with a theme
     cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << setw(50) << CYAN << "*           Staff Members               *" << RESET << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;

    // Add space for readability
    cout << endl<<endl;

    // Display the header with color
    cout << setw(35) << RED << "ID" 
         << setw(20) << "Name"   // Adjusted width for Name
         << setw(30) << "Email"  // Adjusted width for Email
         << setw(15) << "Role" << RESET << endl;

    
    cout << setw(35) << YELLOW << "--------------------------------------------------------------------" << RESET << endl;

    string id,user_name, first_name, last_name, email, password, role;

    // Reading file line by line and displaying the details
    while (staffFile >> id >> user_name>> first_name >> last_name >> email >> password >> role) {
        string fullName = first_name + " " + last_name;  // Combine first and last name

        // Displaying staff member information with beautiful formatting and colors
        cout << setw(35) << GREEN << id 
             << setw(20) << fullName 
             << setw(30) << email 
             << setw(15) << role << RESET << endl;
    }

    staffFile.close();
}

void admin::displayAllCustumers() {
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
    cout << setw(35) << "ID" 
         << setw(20) << "Name" 
         << setw(30) << "Email" 
         << setw(10) << "Role" << endl;
    cout <<setw(35)<<YELLOW << "-----------------------------------------------------------------" << RESET<< endl;

    string id, us_name,first_name, last_name, email, password, role;

    // Reading file line by line
    while (customerFile >> id >>us_name>> first_name >> last_name >> email >> password >> role) {
        string fullName = first_name + " " + last_name;  // Combine first and last name
        cout << left << setw(35) << id 
             << setw(20) << fullName 
             << setw(30) << email 
             << setw(10) << role << endl;
    }

    customerFile.close();
}

void admin::profile() {
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