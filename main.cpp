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
                //budgetApp.dodajAdresata();
                break;
            case '2':
                //budgetApp.wyswietlWszystkichAdresatow();
                break;
            case '9':
                budgetApp.userLogOut();
                break;
            }
        }
    }

}

