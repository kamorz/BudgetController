#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include <vector>

using namespace std;

class Movement
{
    int id, userID;
    int item; //FOR INCOMES:1, FOR EXPENSES:0
    string name,date;
    double amount;

public:
    void setID(int newID);
    void setUserID(int newUserID);
    void setName (string newName);
    void setDate (string newDate);
    void setAmount (double newAmount);
    void setItem (int newItem);

    int getID();
    int getItem();
    int getUserID();
    string getName();
    string getDate();
    double getAmount();
};





#endif
