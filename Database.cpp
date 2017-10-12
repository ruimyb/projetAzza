//
// Created by Ruimy Benjamin Mac on 12/10/2017.
//
#include "Tshirt.h"
#include "Database.h"
#include "database-2.hpp"
#include "Shoes.h"
#include "Memory.h"
#include "Tshirt.h"
#include "Disk.h"
#include "Smartwatch.h"
#include "Graphics.h"
#include "Laptop.h"
void Database::readDatabase(istream& database){
    string kind;
    string product;
    string line;
    string fields;

    //cout << "lecture" << endl;
    while(getline(database, line)){

        stringstream s(line);
        getline(s, kind, US);

        if(kind == "KI"){
            getline(s, product, RS);
            getline(s, fields);
            if(product == "CUSTOMER"){
                Customer* customer = new Customer;
                customer->readCustomer(fields);
                this->myCustomers.push_back(customer);
                //cout << "customer read" << endl;
        }
        else if(product == "SELLER"){
            Seller* seller = new Seller;
            seller->readSeller(fields);
            this->mySellers.push_back(seller);
            //cout << "seller read" << endl;
        }
        else if(product == "SHIPPER"){
            Shipper* shipper = new Shipper;
            shipper->readShipper(fields);
            this->myShippers.push_back(shipper);
            //cout << "shipper read" << endl;
        }
        else if(product == "TSHIRT"){
            Tshirt* tshirt = new Tshirt;
            tshirt->readProduct(fields);
            this->myProducts.push_back(tshirt);
            //cout << "tshirt read" << endl;
        }
        else if(product == "SHOES"){
            Shoes* shoes = new Shoes;
            shoes->readProduct(fields);
            this->myProducts.push_back(shoes);
            //cout << "shoes read" << endl;
        }
        else if(product == "CPU"){
            CPU* cpu = new CPU;
            cpu->readProduct(fields);
            this->myProducts.push_back(cpu);
        }
        else if(product == "MEMORY"){
            Memory* memory = new Memory;
            memory->readProduct(fields);
            this->myProducts.push_back(memory);
         }
        else if(product == "DISK"){
            Disk* disk = new Disk;
            disk->readProduct(fields);
            this->myProducts.push_back(disk);
         }
        else if(product == "GRAPHICS"){
            Graphics* gpu = new Graphics;
            gpu->readProduct(fields);
            this->myProducts.push_back(gpu);
        }
        else if(product == "SMARTWATCH"){
            Smartwatch* smartwatch = new Smartwatch;
            smartwatch->readProduct(fields);
            this->myProducts.push_back(smartwatch);
        }
        else if(product == "LAPTOP"){
            Laptop* laptop = new Laptop;
            laptop->readProduct(fields);
            this->myProducts.push_back(laptop);
        }
            }
        }
}



void Database::writeDatabase(ostream& database){
    for(vector<Customer*>::iterator it = this->myCustomers.begin(); it != this->myCustomers.end(); it++){
        database << (*it)->writeCustomer() << endl;
    }
    for(vector<Seller*>::iterator it = this->mySellers.begin(); it != this->mySellers.end(); it++){
        database << (*it)->writeSeller() << endl;
    }
    for(vector<Shipper*>::iterator it = this->myShippers.begin(); it != this->myShippers.end(); it++) {
        database << (*it)->writeShipper() << endl;
    }
    for(vector<Product*>::iterator it = this->myProducts.begin(); it != this->myProducts.end(); it++){
        database << (*it)->writeProduct() << endl;
    }
}


Product* Database::getProduct(float ID){
    for(vector<Product*>::iterator it = this->myProducts.begin(); it != this->myProducts.end(); it++){
        if((*it)->ID == ID)	return *it;
    }
    return NULL;
}
// remplacer vector<> par map(float, Product*)

Seller* Database::getSeller(float ID){
    for(vector<Seller*>::iterator it = this->mySellers.begin(); it != this->mySellers.end(); it++){
        if((*it)->ID == ID)	return *it;
    }
    return NULL;
}


Shipper* Database::getShipper(float ID){
    for(vector<Shipper*>::iterator it = this->myShippers.begin(); it != this->myShippers.end(); it++){
        if((*it)->ID == ID)	return *it;
    }
    return NULL;
}


Customer* Database::getCustomer(float ID){
    for(vector<Customer*>::iterator it = this->myCustomers.begin(); it != this->myCustomers.end(); it++){
        if((*it)->ID == ID)	return *it;
    }
    return NULL;
}


/*	/!\	 FONCTIONS qui ne marchent pas pour l'instant	/!\	*/

void Database::addSeller(float ID, string name){
    Seller* seller = this->getSeller(ID);
    if(seller != NULL){
        cout << "Seller is already registered" << endl;
        return;	//the seller already exists in the database
    }
    else{
        seller->ID = ID;
        seller->name = name;
        this->mySellers.push_back(seller);
    }
}

void Database::addShipper(float ID, string name){
    Shipper* shipper = this->getShipper(ID);
    if(shipper != NULL){
        cout << "Shipper is already registered" << endl;
        return;	//the shipper already exists in the database
    }
    else{
        shipper->ID = ID;
        shipper->name = name;
        this->myShippers.push_back(shipper);
    }
}

void Database::addCustomer(float ID, string first_name, string last_name, string address){
    Customer* customer = this->getCustomer(ID);
    if(customer != NULL){
        cout << "Customer is already registered" << endl;
        return; //the customer already exists in the database
    }
    else{
        customer->ID = ID;
        customer->first_name = first_name;
        customer->last_name = last_name;
        customer->address = address;
        this->myCustomers.push_back(customer);
    }
}


void Database::addTshirt(float ID, float price, float weight, string description, string brand, float sellerID, float shipperID){

    for(vector<Product*>::iterator it = this->myProducts.begin(); it != this->myProducts.end(); it++)
        if((*it)->ID == ID)	{cout << "product already registered" << endl;} //the product already exists

    Tshirt *tshirt=new Tshirt;
    tshirt->ID = ID;
    tshirt->price = price;
    tshirt->weight = weight;
    tshirt->description = description;
    tshirt->brand = brand;
    myProducts.push_back(tshirt);

    for(vector<Seller*>::iterator it = this->mySellers.begin(); it != this->mySellers.end(); it++){
        if((*it)->ID == ID)	{
            cout << "product has been added" << endl;
        }
    }
}

//Pareil que Tshirt

void Database::addShoes(float ID, float price, float weight, string description, color c, Seller seller, Shipper shipper){
    for(vector<Product*>::iterator it = this->myProducts.begin(); it != this->myProducts.end(); it++)
        if((*it)->ID == ID)	{cout << "product already exists" << endl;} //the product already exists

    Shoes *shoes= new Shoes;
    shoes->ID = ID;
    shoes->price = price;
    shoes->weight = weight;
    shoes->description = description;
    shoes->c = c;
    myProducts.push_back(shoes);

    for(vector<Seller*>::iterator it = this->mySellers.begin(); it != this->mySellers.end(); it++) {
        if ((*it)->ID == ID) { cout << "product has been added" << endl; };
    }

}


void Database::addCPU(float ID, float price, float weight, string description, int cores, float frequency, Seller seller, Shipper shipper) {
    // Autre méthode: ajouter des pointers sur Seller et Shipper et modifier l'objet directement.



    for (vector<Product *>::iterator it = this->myProducts.begin(); it != this->myProducts.end(); it++)
        if ((*it)->ID == ID) {
            cout << "product already exists" << endl;
        } //the product already exists

    CPU *pu = new CPU;
    pu->ID = ID;
    pu->price = price;
    pu->weight = weight;
    pu->description = description;
    pu->cores = cores;
    pu->frequency = frequency;
    myProducts.push_back(pu);

    for(vector<Seller*>::iterator it = this->mySellers.begin(); it != this->mySellers.end(); it++){
        if((*it)->ID == ID)	{cout << "product has been added" << endl;}
        }
}

void Database::addMemory(float ID, float price, float weight, string description, float size, Seller seller, Shipper shipper){
    for(vector<Product*>::iterator it = this->myProducts.begin(); it != this->myProducts.end(); it++)
        if((*it)->ID == ID)	{cout << "product already exists" << endl;} //the product already exists
    Memory *memory= new Memory;
    memory->ID = ID;
    memory->price = price;
    memory->weight = weight;
    memory->description = description;
    memory->size = size;
    myProducts.push_back(memory);

    for(vector<Seller*>::iterator it = this->mySellers.begin(); it != this->mySellers.end(); it++){
        if((*it)->ID == ID)	{cout << "product has been added" << endl;}
    }
}



void Database::addDisk(float ID, float price, float weight, string description, float size, bool ssd, Seller seller, Shipper shipper){

    for(vector<Product*>::iterator it = this->myProducts.begin(); it != this->myProducts.end(); it++)
        if((*it)->ID == ID)	{cout << "product already exists" << endl;} //the product already exists

    Disk *disk= new Disk;
    disk->ID = ID;
    disk->price = price;
    disk->weight = weight;
    disk->description = description;
    disk->size = size;
    disk->ssd = ssd;
    myProducts.push_back(disk);

    for(vector<Seller*>::iterator it = this->mySellers.begin(); it != this->mySellers.end(); it++){
        if((*it)->ID == ID)	{cout << "product has been added" << endl;}
    }
}


void Database::addGPU(float ID, float price, float weight, string description, bool PCIe, Seller seller, Shipper shipper){

    for(vector<Product*>::iterator it = this->myProducts.begin(); it != this->myProducts.end(); it++){
        if((*it)->ID == ID){
            cout << "product already exists" << endl;
        }
    }
    Graphics *gpu= new Graphics;
    gpu->ID = ID;
    gpu->price = price;
    gpu->weight = weight;
    gpu->description = description;
    gpu->PCIe = PCIe;
    myProducts.push_back(gpu);

    for(vector<Seller*>::iterator it = this->mySellers.begin(); it != this->mySellers.end(); it++){
        if((*it)->ID == ID)	{
            cout << "product has been added" << endl;
        }
    }
}
