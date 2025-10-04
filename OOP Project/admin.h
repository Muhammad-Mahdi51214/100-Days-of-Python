#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
#include <iostream>
#include "food.h"
#include "menu.h"
#include <limits>
#include <iomanip>
#include <windows.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
using namespace std;

class admin:protected user
{
    public:
    void displayDashboard() override;
    void setData(string name) override;
    void profile() override;
    bool addStaff();
    void editMenu(class food& obj);
    void viewMenu(class menu& obj);
    void checkInventory(class menu& obj);
    void viewMenuByCategory(class menu& obj);
    void displayAllStaff();
    void displayAllCustumers();
};

#endif // AMDIN_H