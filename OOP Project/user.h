#ifndef USER_H
#define USER_H
#include <iostream>
#include <iomanip>
#include <limits>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
using namespace std;


class user
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
    virtual void displayDashboard()=0;
    
    virtual void setData(string user_name)=0;

    virtual void profile()=0;
    
    int checkId(const string &filename);

    bool recordCheck(const string &filename);

    void myLogo();
};


#endif // USER_H