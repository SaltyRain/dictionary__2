//
//  openedHash.hpp
//  ATD_DICTIONARY
//
//  Created by Тимур Гарипов on 27/03/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#ifndef openedHash_hpp
#define openedHash_hpp

#include <stdio.h>
#include <cstring>

namespace openedHash {
    
    struct elem
    {
        char *name;
        elem *next;
        elem()
        {
            name = nullptr;
            next = nullptr;
        };
        elem(const char* nm, elem* nxt) {
            name = new char[20];
            strcpy(name, nm);
            next = nxt;
        }
    };
    
    class dictionary
    {
    public:
        void insert(const char *name); //вставка значения в список
        void del(const char *name); //удаление значения из списка
        bool member(const char *name) const; //проверка, есть ли value во множестве
        void makenull(); //очистка списка
        void print() const; //вывод списка
        
    private:
        static const int SIZE = 20;
        static const int B = SIZE/2; //кол-во классов
        static elem arr[SIZE];
    
        
        int countKey(const char *name) const; //подсчет ключа
        int countHash(int key, int B) const; //подсчет хэша
        
        bool existArrName(int hs) const; //проверяем, есть ли такое имя в массива
        bool existListName(int hs, const char *name) const; //проверяем, есть ли такое имя в списке (классе)
        
        
        
    };
}
#endif /* openedHash_hpp */
