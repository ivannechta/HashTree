// HashTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "HashTree.h"
HashTree h(5);

int main()
{
    
    h.Add(5);
    h.Add(2);
    h.Add(3);
    h.Add(7);
    h.Add(4);    
    h.Add(8);
    h.Add(15);
    h.Add(10);


    h.Vivod();
    //std::cout << h.Find(10)->data;    
}