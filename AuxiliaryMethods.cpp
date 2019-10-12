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

string AuxiliaryMethods::introducingDate()
{
    string dayAsString="", monthAsString="", yearAsString="",  wholeDate="";
    cout<<"Insert the data according to: YYYY-MM-DD"<<endl<<endl;

    while(isTheYearCorrect(atoi( yearAsString.c_str()))==false)
    {
     cout<<"Year: "; cin>>yearAsString;
    }
    while(isTheMonthCorrect(atoi( monthAsString.c_str()))==false)
    {
     cout<<"Month: "; cin>>monthAsString;
    }

    do
    {
     cout<<"Day: "; cin>>dayAsString;
    } while(isTheDayCorrect( atoi( yearAsString.c_str()) , atoi(monthAsString.c_str()) , atoi(dayAsString.c_str()) )==false);
    cout<<"Introduced date!"<<endl;
    wholeDate+=yearAsString+"-"+monthAsString+"-"+dayAsString;
    return wholeDate;
}

bool AuxiliaryMethods::isTheYearLeap(int year)
{
    if (year%4==0)
        return true;
    else
        return false;
}


bool AuxiliaryMethods::isTheYearCorrect(int year)
{
    if (year>=2000 && year<=2099)
        return true;
    else
        return false;
}


bool AuxiliaryMethods::isTheMonthCorrect(int month)
{
    if (month>=1 && month<=12)
        return true;
    else
        return false;
}

bool AuxiliaryMethods::isTheDayCorrect(int year, int month, int day)
{
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
    {
        if (day>=1 && day<=31)
            return true;
            else
                return false;
    }
    else if (month==4 || month==6 || month==9 || month==11)
    {
        if (day>=1 && day<=30)
            return true;
            else
                return false;
    }
    else if (month==2)
    {
        if ( (isTheYearLeap(year) &&(day>=1 && day<=29)) || ((!isTheYearLeap(year)) && (day>=1 && day<=28)) )
            return true;
        else
            return false;
    }
}

string AuxiliaryMethods::loadSystemDate()
{
    string dateAsString="";

    SYSTEMTIME st;
    GetSystemTime(&st);
    dateAsString+=convertIntToString(st.wYear);
    dateAsString+="-";

    if (st.wMonth>=10)
        dateAsString+=convertIntToString(st.wMonth);
    else
    {
        dateAsString+="0";
        dateAsString+=convertIntToString(st.wMonth);
    }
    dateAsString+="-";

    if (st.wDay>=10)
        dateAsString+=convertIntToString(st.wDay);
    else
    {
        dateAsString+="0";
        dateAsString+=convertIntToString(st.wDay);
    }
    return dateAsString;
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
