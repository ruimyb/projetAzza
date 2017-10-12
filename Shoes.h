

#ifndef PMM_KAB_SHOES_H
#define PMM_KAB_SHOES_H

#include "Product.h"

class Shoes : public Product {
public:
    color c;

    void printProduct();
    void readProduct(string line);
    string writeProduct();
};


#endif //PMM_KAB_SHOES_H
