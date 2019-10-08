#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserMenager.h"
#include "BudgetMenager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetApp
{
    UserMenager userMenager;
    BudgetMenager *budgetMenager;

public:
    BudgetApp (string fileWithUserName) : userMenager(fileWithUserName)
    {
        budgetMenager= NULL;
    }
    ~BudgetApp()
    {
        delete budgetMenager;
        budgetMenager=NULL;
    }
    bool isUserLoggedIn();
    void userRegistration();
    void userLogIn();
    char selectOptionFromMainMenu();
    void displayAllUsers();
    char selectOptionFromUserMenu();
};



#endif
