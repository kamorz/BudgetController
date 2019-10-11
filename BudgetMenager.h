#ifndef BUDGETMENAGER_H
#define BUDGETMENAGER_H

#include <iostream>
#include  <cstdlib>
#include <stdio.h>
#include "Movement.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetMenager
{
    const int LOGGED_USER_ID;
    vector <Movement> movements;


public:
    BudgetMenager(int loggedUserID) : LOGGED_USER_ID(loggedUserID)
    {
        //movements= plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void displayAllMoneyMovements();
    int addIncome(int loggedUserID);
    Movement addNewMovementDatas(int loggedUserID, int typeOfMovement /*, int idOstatniegoAdresata */ );
};



#endif
