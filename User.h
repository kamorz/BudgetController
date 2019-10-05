#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string userName;
    string password;

public:
    void setID(int newID);
    void setUserName (string newUserName);
    void setPassword (string newPassword);

    int getID();
    string getUserName();
    string getPassword();

    //friend int logowanieUzytkownika();
};



#endif
