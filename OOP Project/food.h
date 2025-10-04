#ifndef FOOD_H
#define FOOD_H
#include <string>
#include <fstream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
using namespace std;

class food
{
    protected:
    int id;
    string name;
    string category;
    double price;
    double discount;
    string availability;
    int quantity;

    public:
    friend class admin;
    void addFood(); // Add that food to the menu text file
    void unAvailableFood(); //Delete that food from the menu file
    bool recordCheck(const string &filename); //Override the existing function in user class
    int checkId(const string& filename);
    
};

#endif 