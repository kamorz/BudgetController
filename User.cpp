#include "User.h"

void User::setID(int newID)
{
    if (newID>=0)
        id=newID;
}

void User::setUserName (string newUserName)
{
    userName=newUserName;
}

void User::setPassword (string newPassword)
{
    password=newPassword;
}

int User::getID()
{
    return id;
}

string User::getUserName()
{
    return userName;
}

string User::getPassword()
{
    return password;
}
