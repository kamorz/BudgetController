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

void User::setRealName (string newRealName)
{
    realName=newRealName;
}

void User::setRealSurname (string newRealSurname)
{
    realSurname=newRealSurname;
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

string User::getRealName()
{
    return realName;
}

string User::getRealSurname()
{
    return realSurname;
}

string User::getPassword()
{
    return password;
}
