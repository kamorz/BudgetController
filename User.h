#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string userName;
    string realName;
    string realSurname;
    string password;

public:
    void setID(int newID);
    void setUserName (string newUserName);
    void setRealName (string newRealName);
    void setRealSurname (string newRealSurname);
    void setPassword (string newPassword);

    int getID();
    string getUserName();
    string getRealName();
    string getRealSurname();
    string getPassword();

    //friend int logowanieUzytkownika();
};



#endif
