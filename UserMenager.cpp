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
        cout << endl << "Insert login: ";
        cin>>userName;
        user.setUserName(userName);
    }
    while (isUserNameExist(user.getUserName()) == true);
    string password, name, surname;
    cout << "Insert Password: ";
    cin>>password;
    user.setPassword(password);
    cout << "Insert your name: ";
    cin>>name;
    user.setRealName(name);
    cout << "Insert your surname: ";
    cin>>surname;
    user.setRealSurname(surname);

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

void UserMenager::displayAllUsers()
{
    for (int i=0; i<users.size(); i++)
    {
        cout<<"ID: "<<users[i].getID()<<endl;
        cout<<"Login:"<<users[i].getUserName()<<endl;
        cout<<"Password: "<<users[i].getPassword()<<endl;
        cout<<"Name:"<<users[i].getRealName()<<endl;
        cout<<"Surname:"<<users[i].getRealSurname()<<endl;
    }
}
