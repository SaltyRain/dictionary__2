//
//  closedHash.cpp
//  ATD_DICTIONARY
//
//  Created by Тимур Гарипов on 27/03/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include "closedHash.hpp"

#include <iostream>
#include <cstring>

using namespace std;

closedHash:: elem closedHash:: dictionary:: arr[SIZE];


int closedHash:: dictionary:: countKey(const char *name) const //подсчет ключа
{
    int key = 0;
    for (int i=0; i < strlen(name); i++)
        key += name[i];
    
    return key;
}

int closedHash:: dictionary:: countHash(int key, int iter) const
{
    return (key + iter) % SIZE;
}

int closedHash:: dictionary:: searchFreePos(int hs, int key, const char *nm)
{
    // при запуске этой функции мы изначально знаем, что такой hs в массиве есть
    int pos = BUSY;
    int iter = 0;
    int original_hash = hs;
    for (int i=0; i < SIZE; i++)
    {
        if (strcmp(arr[hs].name, nm) == 0) //строки совпали
            return BUSY; //значит вставить не можем, позиция занята
        
        //выполняем повторное хеширование
        iter++;
        hs = countHash(key, iter); //считаем новый хэш
        if (arr[hs].name[0] == '\0')
            pos = hs; //запоминаем позицию для дальнейшей вставки
        
        if (hs == original_hash)
            break;
        
        if (arr[hs].name == nullptr) //прошлись по всему классу
        {
            if (arr[pos].name[0] != '\0') //если мы до этого не нашли удаленное место
                pos = hs; //то вставку придется осуществить в пустое место
            break;
        }
    }
    return pos;
}

void closedHash:: dictionary:: insert(const char *name)
{
    int key = countKey(name);
    int hash = countHash(key, 0);
    
    if (arr[hash].name == nullptr) //значение пустое
    {
        arr[hash].name = name;
        return;
    }
    
    int insert_pos = searchFreePos(hash, key, name); //Ищем позицию вставки
    if (insert_pos !=  BUSY)
         arr[hash].name = name;
}

void closedHash:: dictionary:: del(const char *name)
{
    
}

bool closedHash:: dictionary:: member(const char *name) const
{
    return false;
}

void closedHash:: dictionary:: makenull()
{
    
}

void closedHash:: dictionary:: print() const
{
    
}
