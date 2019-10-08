#include "BudgetMenager.h"

void BudgetMenager::displayAllMoneyMovements()
{
    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        cout << endl << "Id: " << movements[searcher].getID()<< "  Name:  " << movements[searcher].getName()<<
        "  Item:  " << movements[searcher].getItem()<< " amount: "<<movements[searcher].getAmount()<<endl;
    }
    cout<<endl<<endl;
}

int BudgetMenager::addIncome(int loggedUserID)
{
    int typeOfMovement=1;
    Movement movement;
    int lastMovementID; //=pobierzIdOstatniegoAdresata();
    system("cls");
    cout << " >>> ADDING NEW MONEY MOVEMENT <<<" << endl << endl;
    movement = addNewMovementDatas(loggedUserID, typeOfMovement /*, idOstatniegoAdresata */);

    movements.push_back(movement);
    //dopiszAdresataDoPliku(adresat);

    return ++lastMovementID;
}

Movement BudgetMenager::addNewMovementDatas(int loggedUserID, int typeOfMovement /*, int idOstatniegoAdresata */ )
{
    Movement movement;

    //movement.setID(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    movement.setUserID(loggedUserID);

    cin.sync();
    movement.setItem(typeOfMovement);

    cin.sync();
    cout << "Insert name of income: ";
    movement.setName(AuxiliaryMethods::loadLine());

    cout << "Insert amount: ";
    movement.setAmount(10.00);

    cout << "Insert date: ";
    movement.setDate(AuxiliaryMethods::loadLine());

    return movement;
}
