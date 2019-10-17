#ifndef BUDGETMENAGER_H
#define BUDGETMENAGER_H

#include <iostream>
#include  <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <windows.h>

#include "Movement.h"
#include "AuxiliaryMethods.h"
#include "DateOperation.h"
#include "FileWithMovements.h"

using namespace std;

class BudgetMenager
{
    const int LOGGED_USER_ID;
    vector <Movement> movements;
    FileWithMovements fileWithMovements;
    DateOperation dateOperation;

public:
    BudgetMenager(string fileWithIncomesName, string fileWithExpensesName, int loggedUserID)
    : fileWithMovements(fileWithIncomesName, fileWithExpensesName), LOGGED_USER_ID(loggedUserID)
    {
        movements= fileWithMovements.loadLoggedUserMovements(LOGGED_USER_ID);
    };
    void displayAllMoneyMovements();
    int addIncome(int loggedUserID);
    int addExpense(int loggedUserID);
    Movement addNewMovementDatas(int loggedUserID, int typeOfMovement);
    void displayMoneyMovementsFromCurrentMonth();
    void displayMoneyMovementsFromPreviousMonth();
    void displayMoneyMovementsFromSelectedPeriod();
    bool isIntroducedDateInsidePeriod(string periodStart, string periodFinish, string date);
};

#endif
