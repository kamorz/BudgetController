#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp ("Users.xml", "Incomes.xml", "Expenses.xml");
    char choice;

    while (true)
    {
        if (budgetApp.isUserLoggedIn()!=true)
        {
            choice=budgetApp.selectOptionFromMainMenu();
            switch (choice)
            {
            case '1':
                budgetApp.userRegistration();
                break;
            case '2':
                budgetApp.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Uncorrect choice!" << endl << endl;
                Sleep(1400);
                //system("cls");  break;
            }
        }
        else
        {
            choice=budgetApp.selectOptionFromUserMenu();
            switch (choice)
            {
            case '1':
                budgetApp.addIncome();
                break;
            case '2':
                budgetApp.addExpense();
                break;
            case '3':
                budgetApp.displayAllMoneyMovements();
                break;
            case '4':
                budgetApp.displayMoneyMovementsFromCurrentMonth();
                break;
            case '5':
                budgetApp.displayMoneyMovementsFromPreviousMonth();
                break;
            case '6':
                budgetApp.displayMoneyMovementsFromSelectedPeriod();
                break;
            case '9':
                budgetApp.userLogOut();
                break;
            }
        }
    }

}

