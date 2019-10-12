#ifndef FILEWITHMOVEMENTS_H
#define FILEWITHMOVEMENTS_H

#include <iostream>
#include "Movement.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithMovements
{
    string FILE_WITH_EXPENSES_NAME;
    string FILE_WITH_INCOMES_NAME;

public:
    FileWithMovements (string fileWithIncomesName, string fileWithExpensesName)
    : FILE_WITH_INCOMES_NAME(fileWithIncomesName), FILE_WITH_EXPENSES_NAME(fileWithExpensesName)
    {
    };
    void addMovementToFile(Movement movement);
    string getFileName();
};



#endif
