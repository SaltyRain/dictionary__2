//
//  main.cpp
//  ATD_DICTIONARY
//
//  Created by Тимур Гарипов on 27/03/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

  // МЕТОДИКА: Берем имя, считаем сумму его кода - получаем число. Делим его на кол-во классов получаем остаток - обращаемся к соотв элементу массива.

#include <iostream>
#include <cstring>
#include <fstream>

#include "constants.h"
#include "openedHash.hpp"
#include "closedHash.hpp"


using namespace std;
using namespace openedHash;

void readNamesFromFile(const char *filename, dictionary &dName)
{
    ifstream f;
    f.open(filename); //открываем файл
    if (!f.is_open()) //если не получилось открыть файл
    {
        cout << "Файл не открыт" << endl;
        f.close();
        return;
    }
    char nm[20];
    while (!f.eof())
    {
        f >> nm;
        dName.insert(nm);
    }
    f.close();
}


int main(int argc, const char * argv[]) {
    dictionary goodguys, badguys;
    
    readNamesFromFile(GOODGUYS, goodguys);
    goodguys.print();
    goodguys.del("Selina");
    goodguys.print();
    goodguys.del("Joker");
    goodguys.print();
    goodguys.del("Harvy");
    goodguys.print();
    
    goodguys.member("Batman") ? (cout << "Бэтмэн жив"<<endl) : (cout << "Бэтмэн умер"<<endl);
    goodguys.member("Harvy") ? (cout << "Харви жив"<<endl) : (cout << "Харви умер"<<endl);
    
    
    goodguys.makenull();
    goodguys.print();
}
