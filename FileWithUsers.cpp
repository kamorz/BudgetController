#include "FileWithUsers.h"
#include "Markup.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;
    bool fileExist = xml.Load( "users.xml" );

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

    xml.Save("users.xml");
}

