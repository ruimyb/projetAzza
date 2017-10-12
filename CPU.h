#include "database-2.hpp"
#include "Product.h"
#ifndef PMM_KAB_CPU_H
#define PMM_KAB_CPU_H


class CPU : public Product {
public:
    int cores;
    float frequency;

    void printProduct();
    void readProduct(string line);
    string writeProduct();
};





#endif //PMM_KAB_CPU_H
