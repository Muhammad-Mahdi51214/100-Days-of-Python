#include <iostream>
#include "food.h"

using namespace std;

bool food::recordCheck(const string &filename)
{
    ifstream food(filename);
    if (!food.is_open())
    {
        cout << "Error: Unable to open file!" << endl;
        return false;
    }
    else
    {
        // First Check User Name
        string id, food_name, food_category, food_price, food_discount, food_availablity, food_quantity;

        while (food >> id >> food_name >> food_category >> food_price >> food_discount >> food_availablity >> food_quantity)
        {
            //Remove underscore in food name and then compare it
            string compare_food = "";
            for (char ch : food_name)
            {
                if (ch != '_')
                {
                    compare_food += ch;
                }
                else if(ch=='_')
                {
                    compare_food=compare_food+" ";
                }
            }

            if (compare_food == name)
            {
                food.close();
                return false;
            }
        }

        food.close();
        return true;
    }
}



void food::addFood()
{
    cout << endl;
    cout << "------New Food-------" << endl;
    cout << "Enter Food Name: " << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter Food Category: " << endl;
    cin >> category;
    cout << "Enter Food Price: " << endl;
    cin >> price;
    cout << "Enter Discount on that Food: " << endl;
    cin >> discount;
    cout << "Enter Availability of Food (true/false): " << endl;
    cin >> availability;
    cout << "Enter Quantity of Food: " << endl;
    cin >> quantity;
    bool check = recordCheck("food_items.txt");

    if (check)
    {
        id = checkId("food_items.txt");
        ofstream file("food_items.txt", ios::app);
        if (file.is_open())
        {
            string update_name="";
            for (char ch : name)
            {
                if (ch != ' ')
                {
                    update_name += ch;
                }
                else if(ch==' ')
                {
                   update_name+="_";
                }
            }
            name =update_name;
            file<<endl;
            file << id << " " << name << " " << category << " " << price << " " << discount << " " << availability << " " << quantity;
            file.close();
            cout << endl
                 << "Congratulations--" << endl;
            cout << "Food Added successful!" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for saving data." << endl;
        }
    }
}




void food::unAvailableFood() {
    cout << "-----Delete Food----" << endl;
    cout << "Enter the name of food: " << endl;
    string delete_name;
    cin.ignore();  // To clear any leftover newline in the buffer
    getline(cin, delete_name);  // Read the full name with spaces

    string check = "false";
    string id, food_name, food_category, food_price, food_discount, food_availablity, food_quantity;
    
    // Open the file for reading
    ifstream food("food_items.txt");
    if (!food.is_open()) {
        cout << "Error opening the file!" << endl;
        return;
    }

    // Create a temporary file to store modified data
    ofstream temp("temp_food_items.txt");

    if (!temp.is_open()) {
        cout << "Error opening the temp file!" << endl;
        return;
    }

    // Process each line of the file
    while (food >> id >> food_name >> food_category >> food_price >> food_discount >> food_availablity >> food_quantity) {
        // Remove underscores in the food name and compare it
        string compare_food = "";
        for (char ch : food_name) {
            if (ch != '_') {
                compare_food += ch;
            } else {
                compare_food += " ";  // Replace underscore with space
            }
        }

        // If food matches, mark it as unavailable
        if (compare_food == delete_name) {
            food_availablity = "false";  // Mark as unavailable
            check = "true";
        }

        // Write the (modified) data to the temporary file
        temp << id << " " << food_name << " " << food_category << " " << food_price
             << " " << food_discount << " " << food_availablity << " " << food_quantity << endl;
    }

    food.close();  // Close the input file
    temp.close();  // Close the temporary file

    if (check == "true") {
        // If food was found and updated, delete the original file
        remove("food_items.txt");
        
        // Rename the temp file to the original file name
        rename("temp_food_items.txt", "food_items.txt");

        cout << "---Food Unavailable Successfully---" << endl;
    } else {
        cout << "---Food Item Not Found---" << endl;
    }
}

int food::checkId(const string &filename)
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


