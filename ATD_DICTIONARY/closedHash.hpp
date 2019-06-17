//
//  closedHash.hpp
//  ATD_DICTIONARY
//
//  Created by Тимур Гарипов on 27/03/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#ifndef closedHash_hpp
#define closedHash_hpp

#include <stdio.h>

#define ER_POS -1
namespace closedHash {

    struct elem
    {
        char *name;
        elem() { name = nullptr; }
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
        static elem arr[SIZE];
        
        int countKey(const char *name) const;
        int countHash(int key, int iter) const;
        
        int searchFreePos(int hs, int key, const char *nm); // поиск свободной позиции для вставки
        int searchName(int hs, int key, const char *nm) const; //поиск элемента в массиве. Возврат позиции этого элемента
    };
}

#endif /* closedHash_hpp */
