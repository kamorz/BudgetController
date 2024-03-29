#include "FileWithMovements.h"
#include "Markup.h"

int FileWithMovements::getLastIncomeID()
{
    return biggestIncomeID;
}

void FileWithMovements::setBiggestIncomeID(int newBiggestIncomeID)
{
    biggestIncomeID=newBiggestIncomeID;
}

int FileWithMovements::getLastExpenseID()
{
    return biggestExpenseID;
}

void FileWithMovements::setBiggestExpenseID(int newBiggestExpenseID)
{
    biggestExpenseID=newBiggestExpenseID;
}

void FileWithMovements::addMovementToFile(Movement movement)
{
    CMarkup xml;
    string fileName;

    if (movement.getItem()==0)
        fileName= FILE_WITH_EXPENSES_NAME;
    else if (movement.getItem()==1)
        fileName= FILE_WITH_INCOMES_NAME;

    bool fileExist = xml.Load( fileName );

    if (!fileExist)
    {
        xml.AddElem( "MOVEMENTS" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("movement");
    xml.IntoElem();
    xml.AddElem( "ID", movement.getID());
    xml.AddElem( "UserID", movement.getUserID());
    xml.AddElem( "Amount", AuxiliaryMethods::convertDoubleToString(movement.getAmount()));
    xml.AddElem( "Name", movement.getName());
    xml.AddElem( "Date", movement.getDate());
    xml.OutOfElem();

    xml.Save(fileName);
}


vector <Movement> FileWithMovements::loadLoggedUserMovements(int loggedUserID)
{
    vector <Movement> movements;
    string fileName;

    for (int fileNumber=1; fileNumber<=2; fileNumber++)
    {
        if (fileNumber==1)
            fileName=FILE_WITH_INCOMES_NAME;
        else if (fileNumber==2)
            fileName=FILE_WITH_EXPENSES_NAME;

        CMarkup xml;
        bool fileExist = xml.Load( fileName );
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("movement"))
        {
            xml.IntoElem();
            xml.FindChildElem();
            Movement movement;
            string IdAsString=xml.GetElemContent();
            movement.setID(AuxiliaryMethods::convertStringToInt(IdAsString));
            if(fileNumber==1)
            {
                if (AuxiliaryMethods::convertStringToInt(IdAsString)>biggestIncomeID)
                    biggestIncomeID=AuxiliaryMethods::convertStringToInt(IdAsString);
            }
            else if (fileNumber==2)
            {
                if (AuxiliaryMethods::convertStringToInt(IdAsString)>biggestExpenseID)
                    biggestExpenseID=AuxiliaryMethods::convertStringToInt(IdAsString);
            }
            xml.FindElem();     string userIdAsString=xml.GetElemContent();
            movement.setUserID(AuxiliaryMethods::convertStringToInt(userIdAsString));
            xml.FindElem();     string amountAsString=xml.GetElemContent();
            movement.setAmount(AuxiliaryMethods::convertStringToDouble(amountAsString));
            xml.FindElem();     movement.setName(xml.GetElemContent());
            xml.FindElem();     movement.setDate(xml.GetElemContent());
            xml.OutOfElem();

            if (fileNumber==1)
                movement.setItem(1);
            else if (fileNumber==2)
                movement.setItem(0);

            if (loggedUserID==movement.getUserID())
                movements.push_back(movement);
        }
    }
    movements=sortMovementsAccordingToDate(movements);
    return movements;
}


vector <Movement> FileWithMovements::sortMovementsAccordingToDate(vector<Movement>movements)
{
    int datesAsOneNumber[movements.size()];
    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        datesAsOneNumber[searcher]=transformDateIntoOneNumber(movements[searcher].getDate());
    }

    //SELECTION SORT
    int k;
    for( int i = 0; i < movements.size(); i++ )
    {
        k = i;
        for( int j = i + 1; j < movements.size(); j++ )
        if( datesAsOneNumber[ j ] < datesAsOneNumber[ k ] )
             k = j;

        swap( datesAsOneNumber[ k ], datesAsOneNumber[ i ] );
        swap( movements[ k ], movements[ i ] );
    }

    return movements;
}


int FileWithMovements::transformDateIntoOneNumber(string dateInNormalFormat)
{
    string dateWithoutDashes="";
    dateWithoutDashes+=dateInNormalFormat[0];
    dateWithoutDashes+=dateInNormalFormat[1];
    dateWithoutDashes+=dateInNormalFormat[2];
    dateWithoutDashes+=dateInNormalFormat[3];
    dateWithoutDashes+=dateInNormalFormat[5];
    dateWithoutDashes+=dateInNormalFormat[6];
    dateWithoutDashes+=dateInNormalFormat[8];
    dateWithoutDashes+=dateInNormalFormat[9];
    int dateAsNumber;
    dateAsNumber = AuxiliaryMethods::convertStringToInt(dateWithoutDashes);
    return dateAsNumber;
}

