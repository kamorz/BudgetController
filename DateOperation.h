#ifndef DATEOPERATION_H
#define DATEOPERATION_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <winbase.h>
#include <cstdlib>
#include <string>
#include <algorithm>

#include "AuxiliaryMethods.h"

using namespace std;

class DateOperation
{
public:
    string introducingDate();
    string loadSystemDate();
    bool isTheYearCorrect(string year);
    bool isTheMonthCorrect(string month);
    bool isTheDayCorrect(int year, int month, string day);
    bool isTheYearLeap(int year);
    string getInfoAboutCurrentMonth();
    string getInfoAboutPreviousMonth();
    string organizeWholeDate(string yearAsString, string dayAsString, string MonthAsString);

};

#endif
