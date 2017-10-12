
#include "database-2.hpp"
#ifndef PMM_KAB_CUSTOMER_H
#define PMM_KAB_CUSTOMER_H


class Customer {
public:
    string first_name;
    string last_name;
    string address;
    float ID;

    void printCustomer();
    void readCustomer(string line);
    string writeCustomer();
};


#endif //PMM_KAB_CUSTOMER_H
