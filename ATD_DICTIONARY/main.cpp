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

#define ERROR -1
#define GOODGUYS "goodguys.txt"
#define BADGUYS "badguys.txt"

int count_N(const char *filename1, const char *filename2);

const int N = count_N(GOODGUYS, BADGUYS); //мощность множества

using namespace std;

namespace openedHash {
    
    struct elem
    {
        char name[10];
        elem* next;
        elem(){};
        elem(char* nm, elem* nxt) {
            strcpy(name, nm);
            next = nxt;
        }
    };
    
    class dictionary
    {
    public:
        void insert(char *value); //вставка значения в список
        void del(char *value); //удаление значения из списка
        bool member(char *value); //проверка, есть ли value во множестве
        void makenull(); //очистка списка
        void print(); //вывод списка
        
    private:
        static const int SIZE = 20;
        static elem arr[SIZE];
        static int space;
        
        static const int B; //кол-во классов
        
        elem* head;
        
                    
        
    };
}

int openedHash:: dictionary:: space = 0;
const int openedHash:: dictionary:: B = N % 10; // делим на классы
openedHash:: elem openedHash:: dictionary:: arr[SIZE];


//________________________________________________________________________________________
//________________________________________________________________________________________

namespace closedHash {
    
}


using namespace openedHash;


int count_N(const char *filename1, const char *filename2) //считает можность множеств из файлов
{
    ifstream f1, f2;
    
    f1.open(filename1);
    f2.open(filename2);
    
    if (!f1.is_open() && !f2.is_open())
    {
        cout << "Не удалось открыть файлы" << endl;
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

int main(int argc, const char * argv[]) {
    dictionary goodguys, badguys;
    
}
