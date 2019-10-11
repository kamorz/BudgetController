#include "BudgetMenager.h"

void BudgetMenager::displayAllMoneyMovements()
{
    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        cout << endl << "Id: " << movements[searcher].getID()<< "  Name:  " << movements[searcher].getName()<<
        "  Item:  " << movements[searcher].getItem()<< " amount: "<<movements[searcher].getAmount()<<" date: "
        <<movements[searcher].getDate()<<endl;
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
    system("cls");
    cout<<"Added income!";
    Sleep(1200);
    //dopiszAdresataDoPliku(adresat);

    return ++lastMovementID;
}

Movement BudgetMenager::addNewMovementDatas(int loggedUserID, int typeOfMovement /*, int idOstatniegoAdresata */ )
{
    Movement movement;

    movement.setID(movements.size()+1);
    movement.setUserID(loggedUserID);

    cin.sync();
    movement.setItem(typeOfMovement);

    cin.sync();
    cout << "Insert name of income: ";
    movement.setName(AuxiliaryMethods::loadLine());

    double newAmount;
    cout << "Insert amount: ";
    cin>>newAmount;
    movement.setAmount(newAmount);

    char choice='0';
    cout<<"Do you want to load current date (enter 'C')or insert your own(enter 'O')?";
    while (choice!='o' && choice!='O' && choice!='C' && choice!='c')
    {
    cin>>choice;
    if (choice == 'C' || choice=='c')
    {
    string newDate= AuxiliaryMethods::loadSystemDate();
    movement.setDate(newDate);
    }
    else if (choice == 'O' || choice=='o')
    {
    movement.setDate(AuxiliaryMethods::introducingDate());
    }
    }
    return movement;
}
