#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>
#include "authenticate.h"
#include "authenticate.cpp"
#include "user.h"
#include "user.cpp"
#include "admin.h"
#include "admin.cpp"
#include "custumer.h"
#include "custumer.cpp"
#include "food.h"
#include "food.cpp"
#include "menu.h"
#include "menu.cpp"
#include "staff.h"
#include "staff.cpp"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
using namespace std;





int main()
{
   

    system("cls");
    auth obj;
    obj.myLogo();
    obj.displayDashboard();
}