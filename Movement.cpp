#include "Movement.h"

void Movement::setID(int newID)
{
    if (newID>=0)
        id=newID;
}

void Movement::setUserID(int newUserID)
{
        userID=newUserID;
}

void Movement::setItem(int newItem)
{
        item=newItem;
}

void Movement::setAmount(double newAmount)
{
        amount=newAmount;
}

void Movement::setDate(string newDate)
{
        date=newDate;
}

void Movement::setName(string newName)
{
        name=newName;
}

int Movement::getID()
{
    return id;
}

int Movement::getUserID()
{
    return userID;
}

int Movement::getItem()
{
    return item;
}

double Movement::getAmount()
{
    return amount;
}

string Movement::getDate()
{
    return date;
}

string Movement::getName()
{
    return name;
}
