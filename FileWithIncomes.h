#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>

using namespace std;

class FileWithIncomes : public FileWithMovements
{
    string fileName;

public:
    FileWithIncomes //(string nazwaPliku) : PlikTekstowy(nazwaPliku)
    {
        fileName="incomes.xml";
    };


};




#endif
