#include "user.h"
#include <iostream>
#include <fstream>

using namespace std;

int user::checkId(const string &filename)
{
    // ID Assigning to New Data
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file!" << endl;
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

bool user::recordCheck(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file!" << endl;
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

