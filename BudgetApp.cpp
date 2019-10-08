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
        budgetMenager= new BudgetMenager (userMenager.getLoggedUserID());
    }
}

void BudgetApp::displayAllUsers()
{
    userMenager.displayAllUsers();
}
