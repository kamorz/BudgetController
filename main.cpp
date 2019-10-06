#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "BudgetApp.h"

using namespace std;

int main()
{
BudgetApp budgetApp ("Users.xml");
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
                //budgetApp.logowanieUzytkownika();
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
    }



}
