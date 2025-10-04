#ifndef MENU_H
#define MENU_H
#include <string>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
using namespace std;
class menu
{
    public:
    void fullMenu();
    void menuByCategory(string catgry);
    void check_low_stock();
    friend class custumer;
    friend class admin;
    friend class staff;
};
#endif