#include "BudgetMenager.h"

void BudgetMenager::displayAllMoneyMovements()
{
    system("cls");
    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        cout << "Id: " << movements[searcher].getID()<< "  Name:  " << movements[searcher].getName()<<endl;
        cout<<"Date: "<<movements[searcher].getDate()<<endl;
        cout<< "Amount: ";
        if (movements[searcher].getItem()==0)
        cout<<"-"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
        else if (movements[searcher].getItem()==1)
        cout<<"+"<<fixed<<setprecision(2)<<movements[searcher].getAmount();

        cout<<endl<<endl;
    }
    cout<<endl;
    system("pause");
}


void BudgetMenager::displayMoneyMovementsFromCurrentMonth()
{
    cout<<AuxiliaryMethods::getInfoAboutCurrentMonth()<<endl;
    system("pause");
    /*system("cls");
    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        cout << "Id: " << movements[searcher].getID()<< "  Name:  " << movements[searcher].getName()<<endl;
        cout<<"Date: "<<movements[searcher].getDate()<<endl;
        cout<< "Amount: ";
        if (movements[searcher].getItem()==0)
        cout<<"-"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
        else if (movements[searcher].getItem()==1)
        cout<<"+"<<fixed<<setprecision(2)<<movements[searcher].getAmount();

        cout<<endl<<endl;
    }
    cout<<endl;
    system("pause"); */
}


void BudgetMenager::displayMoneyMovementsFromPreviousMonth()
{
    cout<<AuxiliaryMethods::getInfoAboutPreviousMonth()<<endl;
    system("pause");
    /*system("cls");
    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        cout << "Id: " << movements[searcher].getID()<< "  Name:  " << movements[searcher].getName()<<endl;
        cout<<"Date: "<<movements[searcher].getDate()<<endl;
        cout<< "Amount: ";
        if (movements[searcher].getItem()==0)
        cout<<"-"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
        else if (movements[searcher].getItem()==1)
        cout<<"+"<<fixed<<setprecision(2)<<movements[searcher].getAmount();

        cout<<endl<<endl;
    }
    cout<<endl;
    system("pause"); */
}


int BudgetMenager::addIncome(int loggedUserID)
{
    int typeOfMovement=1;
    Movement movement;
    int lastMovementID;
    system("cls");
    cout << " >>> ADDING NEW MONEY MOVEMENT <<<" << endl << endl;
    movement = addNewMovementDatas(loggedUserID, typeOfMovement /*, idOstatniegoAdresata */);
    fileWithMovements.addMovementToFile(movement);
    movements.push_back(movement);

    system("cls");
    cout<<"Added income!";
    Sleep(1200);

}

int BudgetMenager::addExpense(int loggedUserID)
{
    int typeOfMovement=0;
    Movement movement;
    int lastMovementID;
    system("cls");
    cout << " >>> ADDING NEW MONEY MOVEMENT <<<" << endl << endl;
    movement = addNewMovementDatas(loggedUserID, typeOfMovement);
    fileWithMovements.addMovementToFile(movement);
    movements.push_back(movement);
    system("cls");
    cout<<"Added expense!";
    Sleep(1200);

}

Movement BudgetMenager::addNewMovementDatas(int loggedUserID, int typeOfMovement)
{
    Movement movement;

    movement.setID(fileWithMovements.getLastMovementID()+1);
    movement.setUserID(loggedUserID);

    cin.sync();
    movement.setItem(typeOfMovement);

    cin.sync();
    cout << "Insert name of income: ";
    movement.setName(AuxiliaryMethods::loadLine());

    double newAmount=0;
    cout << "Insert amount using separator '.' :  ";
    while (! (cin>>newAmount))
    {
    cout<<"Uncorrect value! Try again!"<<endl;
    cin.clear();
    cin.sync();
    }
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
