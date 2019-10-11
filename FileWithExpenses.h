#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>

using namespace std;

class FileWithExpenses : public FileWithMovements
{
    string fileName;

public:
    FileWithExpenses //(string nazwaPliku) : PlikTekstowy(nazwaPliku)
    {
        fileName="expenses.xml";
    };


};




#endif
