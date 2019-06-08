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


openedHash:: elem* openedHash:: dictionary:: searchPrevFromSecond(int hs, const char *name) const
{
    elem *prev = arr[hs].next;
    elem *temp = arr[hs].next->next; //второй элемент списка
    while (temp != nullptr)
    {
        if (strcmp(temp->name, name) == 0) //проверка на совпадение
            return prev;
        temp = temp->next;
        prev = prev->next;
    }
    return nullptr;
}

void openedHash:: dictionary:: delHead(int hs) //удаление головы списка
{
    elem *delEl = arr[hs].next;
    arr[hs].next = arr[hs].next->next;
    delete delEl;
}

 void openedHash:: dictionary:: del(const char *name)
{
    int key = countKey(name);
    int hash = countHash(key, B);
    if (existArrName(hash) == false) // Если элемент с таким хэшем не существует
        return; //удалять нечего -> выходим из функции
    
    if (strcmp(arr[hash].name, name) == 0) //если искомый элемент находится в массиве
    {
        if (arr[hash].next != nullptr) //если имеются элементы списка
        {
            //необходимо перенести данные из головы списка в массив, а головной элемент удалить
            arr[hash].name = arr[hash].next->name; // перенесли имя в массив
            elem* delEl = arr[hash].next;
            arr[hash].next = arr[hash].next->next; // соеденили указатель из массива со следующим от головы списка
            delete delEl; //удаляем голову
        }
        else //списка нет -> просто удаляем элемент массива
        {
            delete arr[hash].name;
            arr[hash].name = nullptr;
        }
    }
    else //не нашли элемент в массиве, ищем в списках
    {
        cout << "ищем элемент в списках" << endl;
        if (arr[hash].next == nullptr) //если список пуст
        {
            cout << "если список пуст" << endl;
            return; //выходим из функции, удалять нечего
        }
        
        
        if (strcmp(arr[hash].next->name, name) == 0) //если элемент - это голова списка
        {
            delHead(hash); // удаляем голову
        }
        else
        {
            elem *prevEl = searchPrevFromSecond(hash, name);
            if (prevEl->next == nullptr) //если следующий элемент не совпадает
                return; //ничего не нашли
            elem *el = prevEl->next;
            prevEl->next = el->next; //связали предыдущий со следующим
            delete el;
        }

    }
}


bool openedHash:: dictionary:: member(const char *name) const
{
    int key = countKey(name);
    int hash = countHash(key, B);
    if (existArrName(hash)) //проверяет, есть ли такой хэш в массиве
    {
        if (strcmp(arr[hash].name, name) == 0) //если элемент массива - искомый
            return true;
        if (arr[hash].next != nullptr) //если имеются члены списка
            return existListName(hash, name); //ищем этот элемент в
        
    }
    return false;
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
                    cout << " " << temp->name;
                    temp = temp->next;
                }

                 cout << " ]";
            }
            cout << endl;
        }
    }
    cout << endl;
}

void openedHash:: dictionary:: delList(int i)
{
    elem *temp1, *temp2 = arr[i].next;
    while (temp2 != nullptr)
    {
        temp1 = temp2;
        temp2 = temp2->next;
        delete[] temp1->name;
        delete temp1;
    }
    arr[i].next = nullptr;
}

void openedHash:: dictionary:: delArr()
{
    for (int i=0; i < SIZE; i++)
    {
        if (arr[i].name != nullptr) //если класс не пустой
        {
            if (arr[i].next != nullptr) //если список не пустой
            {
                delList(i); //удаляем список i элемента массива
            }
            delete[] arr[i].name;
            arr[i].name = nullptr;
        }
    }
}

void openedHash:: dictionary:: makenull()
{
    delArr();
    cout << "Список очищен" << endl;
}


