#include "database-2.hpp"
#ifndef PMM_KAB_SHIPPER_H
#define PMM_KAB_SHIPPER_H


class Shipper {
public:
    string name;
    float ID;

    void printShipper();
    void readShipper(string line);
    string writeShipper();
};


#endif //PMM_KAB_SHIPPER_H
