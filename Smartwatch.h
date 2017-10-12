//
// Created by Ruimy Benjamin Mac on 12/10/2017.
//
#include "Product.h"
#include "CPU.h"
#include "Memory.h"
#ifndef PMM_KAB_SMARTWATCH_H
#define PMM_KAB_SMARTWATCH_H


class Smartwatch : public Product {
public:
    CPU cpu;
    Memory memory;
    color c;
    void printProduct();
    void readProduct(string line);
    string writeProduct();
};



#endif //PMM_KAB_SMARTWATCH_H
