//
//  openedHash.cpp
//  ATD_DICTIONARY
//
//  Created by Тимур Гарипов on 27/03/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include <iostream>
#include <cstring>

#include "openedHash.hpp"


using namespace std;

openedHash:: elem openedHash:: dictionary:: arr[SIZE];


int openedHash:: dictionary:: countKey(const char *name) const //подсчет ключа
{
    int key = 0;
    for (int i=0; i < strlen(name); i++)
        key += name[i];
    
    return key;
}

int openedHash:: dictionary:: countHash(int key, int B) const //подсчет хэша
{
    return key % B;
}

bool openedHash:: dictionary:: existArrName(int hs) const
{
    return arr[hs].name != nullptr;
}

bool openedHash:: dictionary:: existListName(int hs, const char *name) const
{
    elem *temp = arr[hs].next; //первый элемент списка
    while (temp != nullptr)
    {
        if (strcmp(temp->name, name) == 0) //проверка на совпадение
            return true;
        temp = temp->next;
    }
    return false;
}


void openedHash:: dictionary:: insert(const char *name)
{
    int key = countKey(name);
    int hash = countHash(key, B);
    if (existArrName(hash)) // Если элемент с таким хэшем существует
    {
        if (strcmp(arr[hash].name, name) == 0) // Такой элемент уже есть в массиве
            return; //завершаем функцию
        
        //проверяем в списке (классе)
        if (arr[hash].next != nullptr) //если есть элементы класса
        {
            if (existListName(hash, name)) //если элемент в списке уже есть
                return; //выходим из функции
        }
        //Добаляем элемент в список
        elem *el = new elem(name, arr[hash].next);
        arr[hash].next = el;
        return;
    }
    //Добавляем элемент в массив
    arr[hash].name = new char[20];
    strcpy(arr[hash].name, name);
}

void openedHash:: dictionary:: print() const
{
    elem *temp;
    for (int i=0; i < SIZE; i++)
    {
        if (arr[i].name != nullptr)
        {
            cout << i << ")" << arr[i].name;
            if (arr[i].next != nullptr)
            {
                cout << " [";
                temp = arr[i].next;
                while (temp != nullptr)
                {
                    cout << temp->name << ", ";
                    temp = temp->next;
                }
                cout << "]";
            }
            cout << endl;
        }
    }
}
