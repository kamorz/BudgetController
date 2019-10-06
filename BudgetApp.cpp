#include "BudgetApp.h"
#include <cstdlib>

char BudgetApp::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
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

bool BudgetApp::isUserLoggedIn()
{
    if (userMenager.getLoggedUserID()!=0)
        return true;
    else
        return false;
}
