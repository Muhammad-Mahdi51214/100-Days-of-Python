#include "authenticate.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

auth ::auth()
{
    username = "Anonymous";
    role = "Anonymous";
}


void auth::myLogo()
{

    cout << YELLOW;
    cout << R"(
                                         .----------------.  .----------------.  .----------------. 
                                        | .--------------. || .--------------. || .--------------. |
                                        | |  ___  ____   | || |  _________   | || |     ______   | |
                                        | | |_  ||_  _|  | || | |_   ___  |  | || |   .' ___  |  | |
                                        | |   | |_/ /    | || |   | |_  \_|  | || |  / .'   \_|  | |
                                        | |   |  __'.    | || |   |  _|      | || |  | |         | |
                                        | |  _| |  \ \_  | || |  _| |_       | || |  \ `.___.'\  | |
                                        | | |____||____| | || | |_____|      | || |   `._____.'  | |
                                        | |              | || |              | || |              | |
                                        | '--------------' || '--------------' || '--------------' |
                                         '----------------'  '----------------'  '----------------' 
    )";
    cout << RESET;

}
void auth::displayDashboard()
{
    int choice;
    do
    {
        // Display the dashboard with some design
        cout << endl;
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << CYAN << "*            USER DASHBOARD             *" << RESET << endl;
        cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
        cout << setw(50) << GREEN << "1. Login" << RESET << endl;
        cout << setw(50) << GREEN << "2. Sign Up" << RESET << endl;
        cout << setw(50) << RED << "3. Exit" << RESET << endl;
        cout << setw(50) << CYAN << "--------------------------------------------" << RESET << endl;
        cout << YELLOW << "Enter your choice: ";

        cin >> choice;

        // Handle invalid input
        while (cin.fail())
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << RED << "Invalid input. Please enter a number (1-3): " << RESET;
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
        {
            string role = login();
            if (!role.empty())
            {
                cout << endl;
                cout << GREEN << "Login successful! Welcome, " << username << RESET << endl;
                cout << YELLOW << "-------User : " << username << RESET << endl;
                cout << YELLOW << "-------Role : " << role << RESET << endl;

                // Directing the user based on their role
                if (role == "admin")
                {
                    admin obj;
                    obj.setData(username);
                    obj.displayDashboard();
                }
                else if (role == "custumer")
                {
                    custumer obj;
                    obj.setData(username);
                    obj.displayDashboard();
                }
                else if (role == "staff")
                {
                    staff obj;
                    obj.setData(username);
                    obj.displayDashboard();
                }
                else
                {
                    cout << RED << "Unknown role. Please contact admin." << RESET << endl;
                }
            }
            else
            {
                cout << RED << "Login failed. Please try again.\n"
                     << RESET;
            }
            break;
        }
        case 2:
        {
            cout << CYAN << "\nLet's create your account!" << RESET << endl;
            if (signUp())
            {
                cout << GREEN << "Sign-up successful! You can now log in.\n"
                     << RESET;
            }
            else
            {
                cout << RED << "Sign-up failed. Please try again.\n"
                     << RESET;
            }
            break;
        }
        case 3:
            cout << YELLOW << "Exiting dashboard. Goodbye!" << RESET << endl;
            break;
        default:
            cout << RED << "Invalid choice. Please choose a valid option (1-3)." << RESET << endl;
        }

        // Wait for the user to press Enter to continue
        cout << "\nPress Enter to continue... ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

    } while (choice != 3);
}

string auth::login()
{
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << setw(50) << CYAN << "*                LOGIN                  *" << RESET << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << YELLOW << "Enter your username: " << RESET << endl;
    cin >> username;
    cout << YELLOW << "Enter your Password:" << RESET << endl;
    cin >> password;

    // Check in admin.txt
    ifstream record("admin.txt");
    if (!record.is_open())
    {
        cout << RED << "Error: Unable to open file 'admin.txt'!" << RESET << endl;
    }
    else
    {
        string id, record_username, first_name, last_name, email, record_password, role;

        while (record >> id >> record_username >> first_name >> last_name >> email >> record_password >> role)
        {
            if (record_username == username && record_password == password)
            {
                record.close();
                return role; // Return the role if login is successful
            }
        }
        record.close();
    }

    // Check in staff.txt
    ifstream staff("staff.txt");
    if (!staff.is_open())
    {
        cout << RED << "Error: Unable to open file 'staff.txt'!" << RESET << endl;
    }
    else
    {
        string id, staff_username, first_name, last_name, email, staff_password, role;

        while (staff >> id >> staff_username >> first_name >> last_name >> email >> staff_password >> role)
        {
            if (staff_username == username && staff_password == password)
            {
                staff.close();
                return role; // Return the role if login is successful
            }
        }
        staff.close();
    }

    // Check in customer.txt
    ifstream customer("custumer.txt");
    if (!customer.is_open())
    {
        cout << RED << "Error: Unable to open file 'customer.txt'!" << RESET << endl;
    }
    else
    {
        string id, customer_username, first_name, last_name, email, customer_password, role;

        while (customer >> id >> customer_username >> first_name >> last_name >> email >> customer_password >> role)
        {
            if (customer_username == username && customer_password == password)
            {
                customer.close();
                return role; // Return the role if login is successful
            }
        }
        customer.close();
    }

    // If no match is found in any file
    cout << "Invalid username or password!" << endl;
    return ""; // Return empty string if login fails
}

int auth::checkId(const string &filename)
{
    // ID Assigning to New Data
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << RED << "Error: Unable to open file!" << RESET << endl;
        return -1;
    }

    else
    {
        int lineCount = 0;
        string line;

        while (getline(file, line))
        {
            lineCount++;
        }
        file.close();
        return lineCount + 1;
    }
    file.close();
    return -1;
}

bool auth::recordCheck(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << RED << "Error: Unable to open file!" << RESET << endl;
        return false;
    }
    else
    {
        // First Check User Name
        string id, customer_username, first_name, last_name, email, customer_password, role;

        while (file >> id >> customer_username >> first_name >> last_name >> email >> customer_password >> role)
        {
            if (customer_username == username)
            {
                file.close();
                return false;
            }
        }

        file.close();
        return true;
    }
}

bool auth::signUp() 
{
    cout << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl;
    cout << setw(50) << CYAN << "*               SIGN UP                 *" << RESET << endl;
    cout << setw(50) << CYAN << "*****************************************" << RESET << endl
         << endl;
    cout << YELLOW << "Enter User Name : " << RESET << endl;
    cin >> username;
    cout << YELLOW << "Enter First Name: " << RESET << endl;
    cin >> first_name;
    cout << YELLOW << "Enter Last Name: " << RESET << endl;
    cin >> last_name;
    cout << YELLOW << "Enter  Email:" << RESET << endl;
    cin >> email;
    cout << YELLOW << "Enter  Password:" << RESET << endl;
    cin >> password;
    role = "custumer";
    // Check the  username and assighning Id to new data
    bool check = recordCheck("custumer.txt");

    if (check) // username not exits previously
    {
        id = checkId("custumer.txt");
        ofstream file("custumer.txt", ios::app);
        if (file.is_open())
        {
            file << endl;
            file << id << " " << username << " " << first_name << " " << last_name << " " << email << " " << password << " " << role;
            file.close();
            cout << endl
                 << "Congratulations--" << endl;
            cout << "Sign-up successful!" << endl;
            return true;
        }
        else
        {
            cout << "Error: Unable to open file for saving data." << endl;
            return false;
        }
    }
    else // username is already exits
    {
        cout << endl;
        cout << "OOPS---User Name is already exits--" << endl;
        cout << "Please Try again" << endl;
        return false;
    }
}