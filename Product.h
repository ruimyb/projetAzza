#include "Shipper.h"
#include "Seller.h"
#ifndef PMM_KAB_PRODUCT_H
#define PMM_KAB_PRODUCT_H



enum color { black, white, red, green, blue };

enum categories { Electronics, Clothing };

class Product {
public:
    float price;
    float weight;
    string description;
    Seller seller;
    Shipper shipper;
    float ID;
    vector<categories> category;

    virtual void printProduct() = 0;	//display the content of the product's fields in the terminal
    virtual void readProduct(string line) = 0;		//read a line of the database and fill the fields of the corresponding product class
    virtual string writeProduct() = 0;	//write in the database the content of the product's fields with the appropriate format
};


#endif //PMM_KAB_PRODUCT_H
