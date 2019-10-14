#include "BudgetMenager.h"

void BudgetMenager::displayAllMoneyMovements()
{
    system("cls");
    HANDLE hOut;
    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        hOut = GetStdHandle( STD_OUTPUT_HANDLE );
        if (movements[searcher].getItem()==0)
            SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        else if (movements[searcher].getItem()==1)
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );

        cout << "/Id:" << movements[searcher].getID()<<"/"<<endl<<"Name:  " << movements[searcher].getName()<<endl;
        cout<<"Date: "<<movements[searcher].getDate()<<endl;
        cout<< "Amount: ";
        if (movements[searcher].getItem()==0)
            cout<<"-"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
        else if (movements[searcher].getItem()==1)
            cout<<"+"<<fixed<<setprecision(2)<<movements[searcher].getAmount();

        cout<<endl<<endl;

    }
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<endl;
    system("pause");
}


void BudgetMenager::displayMoneyMovementsFromCurrentMonth()
{
    system("cls");
    HANDLE hOut;
    double balance=0;
    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        string dateForComparison=movements[searcher].getDate();
        string dateFormatForComparison="";
        for (int datePosition=0; datePosition<=6; datePosition++)
        {
            dateFormatForComparison+=dateForComparison[datePosition];
        }
        if (AuxiliaryMethods::getInfoAboutCurrentMonth()==dateFormatForComparison)
        {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            if (movements[searcher].getItem()==0)
                SetConsoleTextAttribute( hOut, FOREGROUND_RED );
            else if (movements[searcher].getItem()==1)
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
            cout << "/Id:" << movements[searcher].getID()<<"/"<<endl<< "Name:  " << movements[searcher].getName()<<endl;
            cout<<"Date: "<<movements[searcher].getDate()<<endl;
            cout<< "Amount: ";
            if (movements[searcher].getItem()==0)
            {
                cout<<"-"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
                balance-=movements[searcher].getAmount();
            }

            else if (movements[searcher].getItem()==1)
            {
                cout<<"+"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
                balance+=movements[searcher].getAmount();
            }
            cout<<endl<<endl;
        }
    }
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

    cout<<"BALANCE : "<<fixed<<setprecision(2)<<balance<<endl;
    cout<<endl;
    system("pause");
}


void BudgetMenager::displayMoneyMovementsFromPreviousMonth()
{
    system("cls");
    HANDLE hOut;
    double balance=0;
    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        string dateForComparison=movements[searcher].getDate();
        string dateFormatForComparison="";
        for (int datePosition=0; datePosition<=6; datePosition++)
        {
            dateFormatForComparison+=dateForComparison[datePosition];
        }
        if (AuxiliaryMethods::getInfoAboutPreviousMonth()==dateFormatForComparison)
        {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            if (movements[searcher].getItem()==0)
                SetConsoleTextAttribute( hOut, FOREGROUND_RED );
            else if (movements[searcher].getItem()==1)
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
            cout << "/Id:" << movements[searcher].getID()<<"/"<<endl<< "Name:  " << movements[searcher].getName()<<endl;
            cout<<"Date: "<<movements[searcher].getDate()<<endl;
            cout<< "Amount: ";
            if (movements[searcher].getItem()==0)
            {
                cout<<"-"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
                balance-=movements[searcher].getAmount();
            }

            else if (movements[searcher].getItem()==1)
            {
                cout<<"+"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
                balance+=movements[searcher].getAmount();
            }
            cout<<endl<<endl;
        }
    }
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<"BALANCE : "<<fixed<<setprecision(2)<<balance<<endl;
    cout<<endl;
    system("pause");
}


void BudgetMenager::displayMoneyMovementsFromSelectedPeriod()
{
    system("cls");
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    double balance=0;
    string periodStart, periodEnd;
    cout<< "Choose start of period"<<endl<<endl;
    periodStart=AuxiliaryMethods::introducingDate();
    cout<<endl<< "Choose end of period"<<endl<<endl;
    periodEnd=AuxiliaryMethods::introducingDate();
    system("cls");
    cout<<"<<< PERIOD: "<<periodStart<<" - "<<periodEnd<<" >>>"<<endl<<endl;

    for (int searcher = 0 ; searcher< movements.size(); searcher++)
    {
        if (isIntroducedDateInsidePeriod(periodStart, periodEnd, movements[searcher].getDate())==true)
        {
            if (movements[searcher].getItem()==0)
                SetConsoleTextAttribute( hOut, FOREGROUND_RED );
            else if (movements[searcher].getItem()==1)
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
            cout << "/Id:" << movements[searcher].getID()<<"/"<<endl<< "Name:  " << movements[searcher].getName()<<endl;
            cout<<"Date: "<<movements[searcher].getDate()<<endl;
            cout<< "Amount: ";
            if (movements[searcher].getItem()==0)
            {
                cout<<"-"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
                balance-=movements[searcher].getAmount();
            }

            else if (movements[searcher].getItem()==1)
            {
                cout<<"+"<<fixed<<setprecision(2)<<movements[searcher].getAmount();
                balance+=movements[searcher].getAmount();
            }
            cout<<endl<<endl;
        }
    }
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<"BALANCE: "<<fixed<<setprecision(2)<<balance<<endl<<endl;
    system("pause");
}



bool BudgetMenager::isIntroducedDateInsidePeriod(string periodStart, string periodFinish, string date)
{
    periodStart=fileWithMovements.transformDateIntoOneNumber(periodStart);
    periodFinish=fileWithMovements.transformDateIntoOneNumber(periodFinish);
    date=fileWithMovements.transformDateIntoOneNumber(date);
    if (date>=periodStart && date<=periodFinish)
        return true;
    else
        return false;

}


int BudgetMenager::addIncome(int loggedUserID)
{
    int typeOfMovement=1;
    Movement movement;
    system("cls");
    cout << " >>> ADDING NEW MONEY MOVEMENT <<<" << endl << endl;
    movement = addNewMovementDatas(loggedUserID, typeOfMovement /*, idOstatniegoAdresata */);
    fileWithMovements.addMovementToFile(movement);
    movements.push_back(movement);
    system("cls");
    cout<<"Added income!";
    Sleep(1200);
    fileWithMovements.setBiggestMovementID(fileWithMovements.getLastMovementID()+1);
    movements=fileWithMovements.sortMovementsAccordingToDate(movements);
}

int BudgetMenager::addExpense(int loggedUserID)
{
    int typeOfMovement=0;
    Movement movement;
    system("cls");
    cout << " >>> ADDING NEW MONEY MOVEMENT <<<" << endl << endl;
    movement = addNewMovementDatas(loggedUserID, typeOfMovement);
    fileWithMovements.addMovementToFile(movement);
    movements.push_back(movement);
    system("cls");
    cout<<"Added expense!";
    Sleep(1200);
    fileWithMovements.setBiggestMovementID(fileWithMovements.getLastMovementID()+1);
    movements=fileWithMovements.sortMovementsAccordingToDate(movements);
}

Movement BudgetMenager::addNewMovementDatas(int loggedUserID, int typeOfMovement)
{
    Movement movement;

    movement.setID(fileWithMovements.getLastMovementID()+1);
    movement.setUserID(loggedUserID);

    cin.sync();
    movement.setItem(typeOfMovement);

    cin.sync();
    cout << "Insert name: ";
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

