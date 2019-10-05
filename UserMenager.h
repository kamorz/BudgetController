#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include "fileWithUsers.h"

using namespace std;

class UserMenager
{
    FileWithUsers fileWithUsers;
    int loggedUserID;


public:
    UserMenager(string fileWithUsersName) : fileWithUsers(fileWithUsersName)
    {
        loggedUserID=0;
    };
    int getLoggedUserID();



};



#endif
