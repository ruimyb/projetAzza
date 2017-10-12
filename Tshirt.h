//
// Created by Ruimy Benjamin Mac on 12/10/2017.
//
#include "Product.h"
#ifndef PMM_KAB_TSHIRT_H
#define PMM_KAB_TSHIRT_H


class Tshirt : public Product {
public:
    Tshirt();
    Tshirt(string brand1);
    string brand;
    void printTshirt();
    void printProduct();
    void readProduct(string line);
    string writeProduct();
};


#endif //PMM_KAB_TSHIRT_H
