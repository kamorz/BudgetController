#ifndef FILEWITHMOVEMENTS_H
#define FILEWITHMOVEMENTS_H

#include <iostream>
#include "Movement.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithMovements
{
    const string FILE_WITH_EXPENSES_NAME;
    const string FILE_WITH_INCOMES_NAME;
    int biggestExpenseID;
    int biggestIncomeID;


public:
    FileWithMovements (string fileWithIncomesName, string fileWithExpensesName)
    : FILE_WITH_INCOMES_NAME(fileWithIncomesName), FILE_WITH_EXPENSES_NAME(fileWithExpensesName)
    {
        biggestIncomeID=0;
        biggestExpenseID=0;
    };
    void addMovementToFile(Movement movement);
    string getFileName();
    vector <Movement> loadLoggedUserMovements(int loggedUserID);
    int getLastIncomeID();
    int getLastExpenseID();
    void setBiggestIncomeID(int newBiggestIncomeID);
    void setBiggestExpenseID(int newBiggestExpenseID);
    vector <Movement> sortMovementsAccordingToDate(vector<Movement>movements);
    int transformDateIntoOneNumber(string dateInNormalFormat);
};



#endif
