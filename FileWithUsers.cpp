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
    xml.AddElem("user");
    xml.IntoElem();
        xml.AddElem( "UserID", user.getID());
        xml.AddElem( "UserName", user.getUserName());
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

    while (xml.FindElem("user"))
    {
    xml.IntoElem();
    xml.FindChildElem();
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

    xml.OutOfElem();
    users.push_back(user);
    }
    return users;
}

void FileWithUsers::updateFileAfterChangingPassword(string newPassword, int loggedUserID)
{
    CMarkup xml;
    bool fileExist = xml.Load( FILE_WITH_USERS_NAME );
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("user"))
    {
    xml.IntoElem();
    xml.FindChildElem();
    cout<<xml.GetElemContent()<<endl<<loggedUserID<<endl;
    system("pause");
    if( xml.GetElemContent() == AuxiliaryMethods::convertIntToString(loggedUserID))
    {
     xml.FindElem();
     xml.FindElem();
     xml.RemoveElem();
     xml.AddElem( "Password", newPassword);
    }
    xml.OutOfElem();
    }
    xml.Save(FILE_WITH_USERS_NAME);
}


