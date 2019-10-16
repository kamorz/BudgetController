#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <winbase.h>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{


public:
    static char loadCharacter();
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static string loadLine();
    static string introducingDate();
    static string loadSystemDate();
    static bool isTheYearCorrect(string year);
    static bool isTheMonthCorrect(string month);
    static bool isTheDayCorrect(int year, int month, string day);
    static bool isTheYearLeap(int year);
    static string convertDoubleToString(double numberAsDouble);
    static double convertStringToDouble (string numberAsString);
    static string getInfoAboutCurrentMonth();
    static string getInfoAboutPreviousMonth();
    static string organizeWholeDate(string yearAsString, string dayAsString, string MonthAsString);
    static string transformFirstLetterToBigAndOthersToSmall(string text);
    static string introducingPassword();
    static double introducingAmount();

};





#endif
