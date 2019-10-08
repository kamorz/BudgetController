#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "windows.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers
{
    const string FILE_WITH_USERS_NAME;

public:
    FileWithUsers (string fileName) : FILE_WITH_USERS_NAME(fileName) {};
    void addUserToFile(User user);
    vector <User> loadAllUsersFromFile();

};




#endif
