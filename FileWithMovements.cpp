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
        xml.AddElem( "User ID", movement.getUserID());
        xml.AddElem( "Account", AuxiliaryMethods::convertDoubleToString(movement.getAmount()));
        xml.AddElem( "Name", movement.getName());
        xml.AddElem( "Date", movement.getDate());
        xml.OutOfElem();

    xml.Save(fileName);
}
