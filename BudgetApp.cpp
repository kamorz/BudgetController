#include "BudgetApp.h"
#include <cstdlib>

char BudgetApp::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    displayAllUsers();
    cout<<endl<<endl<<endl;
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Log In" << endl;
    cout << "9. Close the program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    cin.sync();
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char BudgetApp::selectOptionFromUserMenu()
{
    char choice;
    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display all your incomes and expenses" << endl;
    cout << "4. Display your incomes and expenses from current month" << endl;
    cout << "5. Display your incomes and expenses from previous month" << endl;
    cout << "6. Display your incomes and expenses from selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "8. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    cin.sync();
    choice = AuxiliaryMethods::loadCharacter();
    return choice;
}

bool BudgetApp::isUserLoggedIn()
{
    if (userMenager.getLoggedUserID()!=0)
        return true;
    else
        return false;
}

void BudgetApp::userRegistration()
{
    userMenager.userRegistration();
    system("cls");
}

void BudgetApp::userLogIn()
{
    userMenager.userLogIn();
    if (userMenager.isUserLoggedIn())
    {
        budgetMenager= new BudgetMenager (FILE_WITH_INCOMES_NAME, FILE_WITH_EXPENSES_NAME, userMenager.getLoggedUserID());
    }
}

int BudgetApp::userLogOut()
{
    return userMenager.userLogOut();
    delete budgetMenager;
    budgetMenager=NULL;
}


void BudgetApp::displayAllUsers()
{
    userMenager.displayAllUsers();
}

void BudgetApp::displayAllMoneyMovements()
{
    budgetMenager->displayAllMoneyMovements();
}

void BudgetApp::displayMoneyMovementsFromCurrentMonth()
{
    budgetMenager->displayMoneyMovementsFromCurrentMonth();
}

void BudgetApp::displayMoneyMovementsFromPreviousMonth()
{
    budgetMenager->displayMoneyMovementsFromPreviousMonth();
}

void BudgetApp::displayMoneyMovementsFromSelectedPeriod()
{
    budgetMenager->displayMoneyMovementsFromSelectedPeriod();
}

void BudgetApp::addIncome()
{
    budgetMenager->addIncome(userMenager.getLoggedUserID());
}

void BudgetApp::addExpense()
{
    budgetMenager->addExpense(userMenager.getLoggedUserID());
}
