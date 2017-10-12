

#ifndef PMM_KAB_SELLER_H
#define PMM_KAB_SELLER_H

#include "database-2.hpp"

class Seller {
public:
    string name;
    float ID;

    void printSeller();
    void readSeller(string line);
    string writeSeller();
};


#endif //PMM_KAB_SELLER_H
