//
// Created by Ruimy Benjamin Mac on 12/10/2017.
//
#include "Product.h"
#include "Seller.h"
#include "Shipper.h"
#include "Customer.h"
#include "CPU.h"
#ifndef PMM_KAB_DATABASE_H
#define PMM_KAB_DATABASE_H


class Database {
public:
    vector<Product*> myProducts;
    vector<Customer*> myCustomers;
    vector<Seller*> mySellers;
    vector<Shipper*> myShippers;

    void readDatabase(istream& database); 	//reads from a database
    void writeDatabase(ostream& database);	//writes in a database
    Product* getProduct(float ID);			//Returns the product with the corresponding ID
    Seller* getSeller(float ID);			//Returns the Seller with the corresponding ID
    Shipper* getShipper(float ID);			//Returns the Shipper with the corresponding ID
    Customer* getCustomer(float ID);		//Returns the customer with the corresponding ID

    void addTshirt(float ID, float price, float weight, string description, string brand, float sellerID, float shipperID);
    void addShoes(float ID, float price, float weight, string description, color c, Seller seller, Shipper shipper);
    void addCPU(float ID, float price, float weight, string description, int cores, float frequency, Seller seller, Shipper shipper);
    void addMemory(float ID, float price, float weight, string description, float size, Seller seller, Shipper shipper);
    void addDisk(float ID, float price, float weight, string description, float size, bool ssd, Seller seller, Shipper shipper);
    void addGPU(float ID, float price, float weight, string description, bool PCIe, Seller seller, Shipper shipper);
    void addLaptop(float ID, float price, float weight, string description, CPU cpu, Seller seller, Shipper shipper);
    void addSmartwatch();
    void addSeller(float ID, string name);
    void addShipper(float ID, string name);
    void addCustomer(float ID, string first_name, string last_name, string address);

};


#endif //PMM_KAB_DATABASE_H
