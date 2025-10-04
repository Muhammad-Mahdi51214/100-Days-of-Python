#ifndef STAFF_H
#define STAFF_H
#include "user.h"
#include <iomanip>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class staff:public user
{
    public:
    void displayDashboard() override;
    void setData(string name) override;
    void profile() override;
    void displayAllOrders();
    void displayAllCustumers();
    void serveCustumer(int custumer_id);
    void generateBill(int custumer_id);
};

#endif