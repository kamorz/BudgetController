#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>

#include "fileWithUsers.h"
#include "User.h"

using namespace std;

class UserMenager
{
    FileWithUsers fileWithUsers;
    int loggedUserID;
    vector <User> users;


public:
    UserMenager(string fileWithUsersName) : fileWithUsers(fileWithUsersName)
    {
        loggedUserID=0;
    };
    int getLoggedUserID();



};



#endif
