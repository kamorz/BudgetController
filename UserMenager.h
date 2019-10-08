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
    User insertNewUserDatas();
    int getNewUserID();
    bool isUserNameExist(string userName);


public:
    UserMenager(string fileWithUsersName) : fileWithUsers(fileWithUsersName)
    {
        loggedUserID=0;
        users= fileWithUsers.loadAllUsersFromFile();
    };
    int getLoggedUserID();
    void userRegistration();
    void displayAllUsers();
    User loadOneUserDatas();
    int userLogIn();
    bool isUserLoggedIn();


};



#endif
