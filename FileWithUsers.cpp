#include "FileWithUsers.h"
#include "Markup.h"
#include <cstdlib>

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;
    bool fileExist = xml.Load( FILE_WITH_USERS_NAME );

    if (!fileExist)
    {
        xml.AddElem( "USERS" );
    }

    xml.FindElem();
    xml.IntoElem();
        xml.AddElem( "User ID", user.getID());
        xml.AddElem( "User name", user.getUserName());
        xml.AddElem( "Password", user.getPassword());
        xml.AddElem( "Name", user.getRealName());
        xml.AddElem( "Surname", user.getRealSurname());
        xml.OutOfElem();

    xml.Save(FILE_WITH_USERS_NAME);
}


vector <User> FileWithUsers::loadAllUsersFromFile()
{
    vector <User> users;

    CMarkup xml;
    bool fileExist = xml.Load( FILE_WITH_USERS_NAME );
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();


    while (xml.FindElem("User"))
    {
    User user;
    string IdAsString=xml.GetElemContent();
    user.setID(AuxiliaryMethods::convertStringToInt(IdAsString));


    xml.FindElem();
    user.setUserName(xml.GetElemContent());
    xml.FindElem();
    user.setPassword(xml.GetElemContent());
    xml.FindElem();
    user.setRealName(xml.GetElemContent());
    xml.FindElem();
    user.setRealSurname(xml.GetElemContent());
    users.push_back(user);
    }
    return users;
}

