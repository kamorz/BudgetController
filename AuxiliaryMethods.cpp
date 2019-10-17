#include "AuxiliaryMethods.h"

char AuxiliaryMethods::loadCharacter()
{
    string enter = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            sign = enter[0];
            break;
        }
        cout << "Uncorrect character. Try again." << endl;
    }
    return sign;
}

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::loadLine()
{
    string enter = "";
    getline(cin, enter);
    return enter;
}

string AuxiliaryMethods::convertDoubleToString(double numberAsDouble)
{
ostringstream strs;
strs << numberAsDouble;
string str = strs.str();
return str;
}

double AuxiliaryMethods::convertStringToDouble (string numberAsString)
{
    double number = atof(numberAsString.c_str());
    return number;
}



string AuxiliaryMethods::transformFirstLetterToBigAndOthersToSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
        for (int i=0; i<text.length();i++)
        {
            if (text[i]==' ')
            text[i+1]= toupper(text[i+1]);
        }
    }
    return text;
}

string AuxiliaryMethods::introducingPassword()
{
    string password="", confirmingPassword=" ";
    while(password!=confirmingPassword)
    {
        cout<<"Enter password: ";
        cin.sync();
        getline(cin, password);
        cout<<"Confirm password: ";
        cin.sync();
        getline(cin, confirmingPassword);

        if (password!=confirmingPassword)
        {
            cout<<"Password aren't the same!"<<endl;
            Sleep(1200);
            system("cls");
        }
    }
    return password;
}

double AuxiliaryMethods::introducingAmount()
{
    double amount;
    string newAmountAsString="", correctAmountAsString="", partBeforeSeparator="", partAfterSeparator="";
    int amountCorrection=0, separatorPlace=0;
    do
    {
        cin>>newAmountAsString;
        amountCorrection=1;

        separatorPlace=newAmountAsString.length();
        for (int position=0; position<newAmountAsString.length(); position++)
        {
            if (newAmountAsString[position]=='.' || newAmountAsString[position]==',')
                separatorPlace= position;
        }
        for (int position=0; position<separatorPlace; position++)
        {
            if (newAmountAsString[position]>=48 && newAmountAsString[position]<=57)
                partBeforeSeparator+=newAmountAsString[position];
            else
                amountCorrection=0;
        }
        for (int position=separatorPlace+1; position<newAmountAsString.length(); position++)
        {
            if (newAmountAsString[position]>=48 && newAmountAsString[position]<=57)
                partAfterSeparator+=newAmountAsString[position];
            else
                amountCorrection=0;
        }
        if (amountCorrection==1)
        {
            correctAmountAsString+=partBeforeSeparator;
            correctAmountAsString+=".";
            correctAmountAsString+=partAfterSeparator;
            amount=convertStringToDouble(correctAmountAsString);
        }
        else
        {
            newAmountAsString="", correctAmountAsString="", partBeforeSeparator="", partAfterSeparator="";
            cout<<"Uncorrect value! Try again:"<<endl;
        }
    }
    while (amountCorrection!=1);
    return amount;
}
