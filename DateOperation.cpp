#include "DateOperation.h"

string DateOperation::introducingDate()
{
    string dayAsString="", monthAsString="", yearAsString="",  wholeDate;
    cout<<"Insert the data according to: YYYY-MM-DD"<<endl<<endl;

    while(isTheYearCorrect(yearAsString)==false)
    {
     cout<<"Year: "; cin>>yearAsString;
     if (isTheYearCorrect(yearAsString)==false)
     {
         cout<<"Uncorrect year! Try again!";
         Sleep (900); system("cls");
     }
    }
    while(isTheMonthCorrect( monthAsString)==false)
    {
     cout<<"Month: "; cin>>monthAsString;
     if (isTheMonthCorrect(monthAsString)==false)
     {
        cout<<"Uncorrect month! Try again!";
        Sleep (900); system("cls");
        cout<<"Year: "<<yearAsString<<endl;
     }
    }
    do
    {
     cout<<"Day: "; cin>>dayAsString;
     if (isTheDayCorrect( atoi( yearAsString.c_str()) , atoi(monthAsString.c_str()) , dayAsString)==false)
     {
         cout<<"Uncorrect day! Try again!"<<endl;
         Sleep(900); system("cls");
         cout<<"Year: "<<yearAsString<<"  Month: "<<monthAsString<<endl;
     }
    } while(isTheDayCorrect( atoi(yearAsString.c_str()) , atoi(monthAsString.c_str()) , dayAsString)==false);
    cout<<"Introduced date!"<<endl;
    Sleep(500);
    wholeDate=organizeWholeDate(yearAsString, dayAsString, monthAsString);
    return wholeDate;
}

string DateOperation::organizeWholeDate(string yearAsString, string dayAsString, string monthAsString)
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

bool DateOperation::isTheYearLeap(int year)
{
    if ((year%4==0 && year%100!=0) || (year%400==0))
        return true;
    else
        return false;
}


bool DateOperation::isTheYearCorrect(string year)
{
    if (AuxiliaryMethods::convertStringToInt(year)>=1900 && AuxiliaryMethods::convertStringToInt(year)<=2099 && year.length()==4)
        return true;
    else
        return false;
}


bool DateOperation::isTheMonthCorrect(string month)
{
    if (AuxiliaryMethods::convertStringToInt(month)>=1 && AuxiliaryMethods::convertStringToInt(month)<=12 && month.length()<=2 &&
        month[month.length()-1]>=48 && month[month.length()-1]<=57 )
        return true;
    else
        return false;

}

bool DateOperation::isTheDayCorrect(int year, int month, string day)
{
    if (day[day.length()-1]<48 || day[day.length()-1]>57)
    {
        return false;
    }
    else
    {
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
    {
        if (AuxiliaryMethods::convertStringToInt(day)>=1 && (AuxiliaryMethods::convertStringToInt(day)<=31)&& day.length()<=2)
            return true;
            else
                return false;
    }
    else if (month==4 || month==6 || month==9 || month==11)
    {
        if (AuxiliaryMethods::convertStringToInt(day)>=1 && (AuxiliaryMethods::convertStringToInt(day)<=30) && day.length()<=2)
            return true;
            else
                return false;
    }
    else if (month==2)
    {
        if ( (isTheYearLeap(year) &&((AuxiliaryMethods::convertStringToInt(day)>=1 && (AuxiliaryMethods::convertStringToInt(day)<=29)))) && day.length()<=2 ||
              ((!isTheYearLeap(year)) && ((AuxiliaryMethods::convertStringToInt(day)>=1 && (AuxiliaryMethods::convertStringToInt(day)<=28)))) && day.length()<=2)
            return true;
        else
            return false;
    }
    }
}

string DateOperation::loadSystemDate()
{
    string DateAsString="";

    SYSTEMTIME st;
    GetSystemTime(&st);
    DateAsString+=AuxiliaryMethods::convertIntToString(st.wYear);
    DateAsString+="-";

    if (st.wMonth>=10)
        DateAsString+=AuxiliaryMethods::convertIntToString(st.wMonth);
    else
    {
        DateAsString+="0";
        DateAsString+=AuxiliaryMethods::convertIntToString(st.wMonth);
    }
    DateAsString+="-";

    if (st.wDay>=10)
        DateAsString+=AuxiliaryMethods::convertIntToString(st.wDay);
    else
    {
        DateAsString+="0";
        DateAsString+=AuxiliaryMethods::convertIntToString(st.wDay);
    }
    return DateAsString;
}

string DateOperation::getInfoAboutCurrentMonth()
{
    string monthInfo="";

    SYSTEMTIME st;
    GetSystemTime(&st);
    monthInfo+=AuxiliaryMethods::convertIntToString(st.wYear);
    monthInfo+="-";

    if (st.wMonth>=10)
        monthInfo+=AuxiliaryMethods::convertIntToString(st.wMonth);
    else
    {
        monthInfo+="0";
        monthInfo+=AuxiliaryMethods::convertIntToString(st.wMonth);
    }

    return monthInfo;
}

string DateOperation::getInfoAboutPreviousMonth()
{
    string monthInfo="";

    SYSTEMTIME st;
    GetSystemTime(&st);
    monthInfo+=AuxiliaryMethods::convertIntToString(st.wYear);
    monthInfo+="-";
    int previousMonth = st.wMonth-1;
    if (previousMonth>=10)
        monthInfo+=AuxiliaryMethods::convertIntToString(previousMonth);
    else
    {
        monthInfo+="0";
        monthInfo+=AuxiliaryMethods::convertIntToString(previousMonth);
    }

    return monthInfo;
}
