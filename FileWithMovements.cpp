#include "FileWithMovements.h"
#include "Markup.h"



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

        while (xml.FindElem("ID"))
        {
            Movement movement;
            string IdAsString=xml.GetElemContent();
            movement.setID(AuxiliaryMethods::convertStringToInt(IdAsString));
            if (AuxiliaryMethods::convertStringToInt(IdAsString)>biggestMovementID)
                biggestMovementID=AuxiliaryMethods::convertStringToInt(IdAsString);

            xml.FindElem();
            string userIdAsString=xml.GetElemContent();
            movement.setUserID(AuxiliaryMethods::convertStringToInt(userIdAsString));
            xml.FindElem();
            string amountAsString=xml.GetElemContent();
            movement.setAmount(AuxiliaryMethods::convertStringToDouble(amountAsString));
            xml.FindElem();
            movement.setName(xml.GetElemContent());
            xml.FindElem();
            movement.setDate(xml.GetElemContent());

            if (fileNumber==1)
                movement.setItem(1);
            else if (fileNumber==2)
                //movement.setItem(0);

            if (loggedUserID==movement.getUserID())
            movements.push_back(movement);
        }
    }
    return movements;
}

