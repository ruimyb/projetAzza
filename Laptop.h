//
// Created by Ruimy Benjamin Mac on 12/10/2017.
//
#include "Product.h"
#include "CPU.h"
#include "Disk.h"
#include "Graphics.h"
#include "Memory.h"
#ifndef PMM_KAB_LAPTOP_H
#define PMM_KAB_LAPTOP_H


class Laptop : public Product {
public:
    CPU cpu;
    Memory memory;
    Disk disk;
    Graphics gpu;
    Laptop(CPU cpu1, Memory memory1, Disk disk1, Graphics gpu1);
    Laptop();
    void printProduct();
    void readProduct(string line);
    string writeProduct();
};


#endif //PMM_KAB_LAPTOP_H
