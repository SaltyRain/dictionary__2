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
    int pos = ER_POS;
    int iter = 0;
    int original_hash = hs;
    
    while (arr[hs].name != nullptr)
    {
        if (strcmp(arr[hs].name, nm) == 0) //строки совпали
            return ER_POS; //значит вставить не можем, позиция занята
        
        //выполняем повторное хеширование
        iter++;
        hs = countHash(key, iter); //считаем новый хэш

        if (arr[hs].name != nullptr && arr[hs].name[0] == '\0')
            pos = hs; //запоминаем позицию для дальнейшей вставки

        if (hs == original_hash)
            break;
    }
    
    if (pos == ER_POS) //если не нашли позицию удаленного элемента
        pos = hs; //то возвращаем позицию элемента nullptr
  
    return pos;
}

void closedHash:: dictionary:: insert(const char *name)
{
    int key = countKey(name);
    int hash = countHash(key, 0);
    
    if (arr[hash].name == nullptr) //значение пустое
    {
        arr[hash].name = new char[20];
        strcpy(arr[hash].name, name); //копируем строку в массив
        return;
    }
    
    int pos = searchFreePos(hash, key, name); //Ищем позицию вставки
    if (pos !=  ER_POS)
    {
        if (arr[pos].name == nullptr)
            arr[pos].name = new char[20]; //не выделяем память для удаленной до этого строки
        
        strcpy(arr[pos].name, name); //копируем строку в массив
    }
}

int closedHash:: dictionary:: searchName(int hs, int key, const char *nm) const
{
    int original_hash = hs;
    int iter = 0;
    
    while (arr[hs].name != nullptr) //пока не закончился класс
    {
        if (strcmp(arr[hs].name, nm) == 0)
            return hs;
        
        //выполняем повторное хеширование
        iter++;
        hs = countHash(key, iter); //считаем новый хэш
        if (hs == original_hash) //вернулись к исходному хэшу -> класс закончился
            break;
    }
    return ER_POS;
}

void closedHash:: dictionary:: del(const char *name)
{
    int key = countKey(name);
    int hash = countHash(key, 0);
    
    if (arr[hash].name == nullptr) //строка пустая
        return;

    //поиск строки
    int pos = searchName(hash, key, name);
    if (pos != ER_POS)
        arr[pos].name[0] = '\0';
}

bool closedHash:: dictionary:: member(const char *name) const
{
    int key = countKey(name);
    int hash = countHash(key, 0);
    
    if (arr[hash].name == nullptr) //строка пустая
        return false;
    //поиск строки
    int pos = searchName(hash, key, name);
    return pos != ER_POS;
}

void closedHash:: dictionary:: makenull()
{
    for(int i=0 ; i < SIZE; i++)
    {
        delete[] arr[i].name; // Удаляем данные из ячейки
        arr[i].name = nullptr;
    }
}

void closedHash:: dictionary:: print() const
{
    for (int i=0; i < SIZE; i++)
    {
        if (arr[i].name != nullptr && arr[i].name[0] != '\0')
            cout << i << ")" << arr[i].name << endl;
    }
    cout << endl;
}
