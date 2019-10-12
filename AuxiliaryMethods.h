#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <winbase.h>
#include <cstdlib>
#include <string>

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
    static bool isTheYearCorrect(int year);
    static bool isTheMonthCorrect(int month);
    static bool isTheDayCorrect(int year, int month, int day);
    static bool isTheYearLeap(int year);
    static string convertDoubleToString(double numberAsDouble);
    static double convertStringToDouble (string numberAsString);

};





#endif
