#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H
#include <iostream>
#include <string>
#include "admin.h"
#include "custumer.h"
#include "staff.h"


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
using namespace std;
class auth
{
    protected:
    int id;
    string username;
    string first_name;
    string last_name;
    string email;
    string password;
    string role;

public:
    auth();
    void displayDashboard();

    string login();

    int checkId(const string &filename);

    bool recordCheck(const string &filename);

    bool signUp();
    
    void myLogo();
};
#endif