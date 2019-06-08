//
//  constants.h
//  ATD_DICTIONARY
//
//  Created by Тимур Гарипов on 27/03/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#ifndef constants_h
#define constants_h

#include <iostream>
#include <fstream>

#define ERROR -1
#define GOODGUYS "goodguys.txt"
#define BADGUYS "badguys.txt"

using namespace std;

int count_N(const char *filename1, const char *filename2) //считает можность множеств из файлов
{
    ifstream f1, f2;
    
    f1.open(filename1);
    f2.open(filename2);
    
    if (!f1.is_open() && !f2.is_open())
    {
        cout << "Не удалось открыть файлы" << std::endl;
        f1.close();
        f2.close();
        return ERROR;
    }
    
    int n1 = 0, n2 = 0;
    f1 >> n1;
    f2 >> n2;
    
    int N = n1 + n2;
    return N;
}

const int N = count_N(GOODGUYS, BADGUYS); //мощность множества

#endif /* constants_h */
