#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserMenager.h"
#include "AuxiliaryMethods.h"

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
    bool isUserLoggedIn();
    void userRegistration();
    char selectOptionFromMainMenu();
};





#endif
