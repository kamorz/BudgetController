#include "UserMenager.h"


int UserMenager::getLoggedUserID()
{
    return loggedUserID;
}

void UserMenager::userRegistration()
{
    system("cls");
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
        cout << endl << "Enter login: ";
        cin>>userName;
        user.setUserName(userName);
    }
    while (isUserNameExist(user.getUserName()) == true);
    string password=" ", name, surname;

    password=AuxiliaryMethods::introducingPassword();

    user.setPassword(password);
    cout << "Enter your name: ";
    cin.sync();
    getline(cin,name);
    user.setRealName(AuxiliaryMethods::transformFirstLetterToBigAndOthersToSmall(name));
    cout << "Enter your surname: ";
    cin>>surname;
    user.setRealSurname(AuxiliaryMethods::transformFirstLetterToBigAndOthersToSmall(surname));

    return user;
}


bool UserMenager::isUserLoggedIn()
{
    if (loggedUserID>0)
        return true;
    else
        return false;
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
        cout<<"Login: "<<users[i].getUserName()<<endl;
        cout<<"Password: "<<users[i].getPassword()<<endl;
        cout<<"Name: "<<users[i].getRealName()<<endl;
        cout<<"Surname: "<<users[i].getRealSurname()<<endl;
    }
}


void UserMenager::changeUserPassword(int loggedUserID)
{
    cin.sync();
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int searcher = 0; searcher< users.size(); searcher++)
    {
        if (users[searcher].getID() == loggedUserID)
        {
            users[searcher].setPassword(newPassword);
            cout << "Password changed succesfully!" << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.updateFileAfterChangingPassword(newPassword, loggedUserID);
}

int UserMenager::userLogIn()
{
    cin.sync();
    User user;
    string login = "", password = "";

    cout << endl << "Insert login: ";
    login = AuxiliaryMethods::loadLine();

    int searcher = 0; //users.begin();
    while (searcher < users.size())
    {
        if (users[searcher].getUserName() == login)
        {
            for (int trialsNumber = 3; trialsNumber > 0; trialsNumber--)
            {
                cout << "Insert password. Your trials: " << trialsNumber << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[searcher].getPassword() == password)
                {
                    cout << endl << "You've logged in!" << endl << endl;
                    system("pause");
                    loggedUserID= users[searcher].getID();
                    return loggedUserID;
                }
            }
            cout << "Inserted wrong password 3 times!" << endl;
            system("pause");
            return 0;
        }
        searcher++;
    }
    cout << "This login doesn't exist!" << endl << endl;

    system("pause");
    system("cls");
    return 0;
}


int UserMenager::userLogOut()
{
    loggedUserID = 0;
    system("cls");
    return loggedUserID;
}
