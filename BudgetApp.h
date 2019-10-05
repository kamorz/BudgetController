#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserMenager.h"

using namespace std;

class BudgetApp
{
    UserMenager userMenager;

public:
    BudgetApp (string fileWithUserName) : userMenager(fileWithUserName)
    {
    }
    ~BudgetApp()
    {
    }

    void userRegistration();
};







#endif
