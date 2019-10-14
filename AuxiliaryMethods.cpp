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
    string dayAsString="", monthAsString="", yearAsString="",  wholeDate;
    cout<<"Insert the data according to: YYYY-MM-DD"<<endl<<endl;

    while(isTheYearCorrect(atoi( yearAsString.c_str()))==false)
    {
     cout<<"Year: "; cin>>yearAsString;
     if (isTheYearCorrect(atoi( yearAsString.c_str()))==false)
     {
         cout<<"Uncorrect year! Try again!";
         Sleep (900); system("cls");
     }
    }
    while(isTheMonthCorrect(atoi( monthAsString.c_str()))==false)
    {
     cout<<"Month: "; cin>>monthAsString;
     if (isTheMonthCorrect(atoi( monthAsString.c_str()))==false)
     {
        cout<<"Uncorrect month! Try again!";
        Sleep (900); system("cls");
        cout<<"Year: "<<yearAsString<<endl;
     }
    }
    do
    {
     cout<<"Day: "; cin>>dayAsString;
     if (isTheDayCorrect( atoi( yearAsString.c_str()) , atoi(monthAsString.c_str()) , atoi(dayAsString.c_str()))==false)
     {
         cout<<"Uncorrect day! Try again!"<<endl;
         Sleep(900); system("cls");
         cout<<"Year: "<<yearAsString<<"  Month: "<<monthAsString<<endl;
     }
    } while(isTheDayCorrect( atoi( yearAsString.c_str()) , atoi(monthAsString.c_str()) , atoi(dayAsString.c_str()) )==false);
    cout<<"Introduced date!"<<endl;
    Sleep(500);
    wholeDate=organizeWholeDate(yearAsString, dayAsString, monthAsString);
    return wholeDate;
}

string AuxiliaryMethods::organizeWholeDate(string yearAsString, string dayAsString, string monthAsString)
{
    string wholeDate="";
    wholeDate+=yearAsString+"-";

    if (monthAsString.length()==2)
    wholeDate+= monthAsString+"-";
    else if (monthAsString.length()<2)
    wholeDate+="0" + monthAsString+"-";

    if (dayAsString.length()==2)
    wholeDate+= dayAsString;
    else if (dayAsString.length()<2)
    wholeDate+="0" + dayAsString;
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
    string DateAsString="";

    SYSTEMTIME st;
    GetSystemTime(&st);
    DateAsString+=convertIntToString(st.wYear);
    DateAsString+="-";

    if (st.wMonth>=10)
        DateAsString+=convertIntToString(st.wMonth);
    else
    {
        DateAsString+="0";
        DateAsString+=convertIntToString(st.wMonth);
    }
    DateAsString+="-";

    if (st.wDay>=10)
        DateAsString+=convertIntToString(st.wDay);
    else
    {
        DateAsString+="0";
        DateAsString+=convertIntToString(st.wDay);
    }
    return DateAsString;
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

string AuxiliaryMethods::getInfoAboutCurrentMonth()
{
    string monthInfo="";

    SYSTEMTIME st;
    GetSystemTime(&st);
    monthInfo+=convertIntToString(st.wYear);
    monthInfo+="-";

    if (st.wMonth>=10)
        monthInfo+=convertIntToString(st.wMonth);
    else
    {
        monthInfo+="0";
        monthInfo+=convertIntToString(st.wMonth);
    }

    return monthInfo;
}

string AuxiliaryMethods::getInfoAboutPreviousMonth()
{
    string monthInfo="";

    SYSTEMTIME st;
    GetSystemTime(&st);
    monthInfo+=convertIntToString(st.wYear);
    monthInfo+="-";
    int previousMonth = st.wMonth-1;
    if (previousMonth>=10)
        monthInfo+=convertIntToString(previousMonth);
    else
    {
        monthInfo+="0";
        monthInfo+=convertIntToString(previousMonth);
    }

    return monthInfo;
}

string AuxiliaryMethods::transformFirstLetterToBigAndOthersToSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
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
