#include "Product.h"

#ifndef PMM_KAB_GRAPHICS_H
#define PMM_KAB_GRAPHICS_H


class Graphics : public Product {
public:
    bool PCIe;

    void printProduct();
    void readProduct(string line);
    string writeProduct();
};


#endif //PMM_KAB_GRAPHICS_H
