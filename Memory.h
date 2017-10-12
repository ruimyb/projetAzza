//
// Created by Ruimy Benjamin Mac on 12/10/2017.
//
#include "Product.h"
#ifndef PMM_KAB_MEMORY_H
#define PMM_KAB_MEMORY_H


class Memory : public Product {
public:
    float size;

    void printProduct();
    void readProduct(string line);
    string writeProduct();
};


#endif //PMM_KAB_MEMORY_H
