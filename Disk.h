#include "Product.h"
#ifndef PMM_KAB_DISK_H
#define PMM_KAB_DISK_H


/******************** Disk *******************/

class Disk : public Product {
public:
    float size;
    bool ssd;

    void printProduct();
    void readProduct(string line);
    string writeProduct();
};





#endif //PMM_KAB_DISK_H
