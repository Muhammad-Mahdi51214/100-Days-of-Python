#ifndef CUSTUMER_H
#define CUSTUMER_H

#include "user.h"
#include "menu.h"
#include <iomanip>
#include <cstdio> // for remove() and rename()
#include <stdexcept> // to handle excceptions in program
using namespace std;
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
class custumer:public user 
{
    public:
    void displayDashboard() override;
     void setData(string name) override;
     void profile() override;
    void viewMenu(class menu& obj);
    void viewMenuByCategory(class menu& obj);
   
    void orderMenu();
    void generateBill();
};
#endif