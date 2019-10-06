#include "UserMenager.h"


int UserMenager::getLoggedUserID()
{
    return loggedUserID;
}

void UserMenager::userRegistration()
{
    User user = insertNewUserDatas();
    users.push_back(user);

    fileWithUsers.addUserToFile(user);
    cout << endl << "Registration succesfull" << endl << endl;
    system("pause");
}

User UserMenager::insertNewUserDatas()
{
    User user;

    user.setID(getNewUserID());
    string userName;
    do
    {
        cout << endl << "Podaj login: ";
        cin>>userName;
        user.setUserName(userName);
    }
    while (isUserNameExist(user.getUserName()) == true);
    string password;
    cout << "Insert Password: ";
    cin>>password;
    user.setPassword(password);

    return user;
}

int UserMenager::getNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getID() + 1;
}

bool UserMenager::isUserNameExist(string userName)
{
    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getUserName()==userName)
        {
            cout<<endl<<"This login is busy";
            return true;
        }

    }
    return false;
}
