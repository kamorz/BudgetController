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
    const string FILE_WITH_INCOMES_NAME;
    const string FILE_WITH_EXPENSES_NAME;

public:
    BudgetApp (string fileWithUserName, string fileWithIncomesName, string fileWithExpensesName)
    : userMenager(fileWithUserName), FILE_WITH_INCOMES_NAME(fileWithIncomesName), FILE_WITH_EXPENSES_NAME(fileWithExpensesName)
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
    void displayAllMoneyMovements();
    void displayMoneyMovementsFromCurrentMonth();
    void displayMoneyMovementsFromPreviousMonth();
    char selectOptionFromUserMenu();
    int userLogOut();
    void addIncome();
    void addExpense();
};



#endif
