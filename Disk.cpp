//
// Created by Ruimy Benjamin Mac on 12/10/2017.
//

#include "Disk.h"

void Disk::printProduct() {
    cout << "Disk | ";
    printProduct();
    cout << " | " << "size: " << this->size;
    cout << " | " << "SSD: " << this->ssd;

}



void Disk::readProduct(string line) {
    stringstream s(line);
    string field;
    string value;
    int category;

    while(getline(s, field, US)){

        getline(s, value, RS);
        if(field == "ID"){
            stringstream(value) >> this->ID;
        }
        else if(field == "PR"){
            stringstream(value) >> this->price;
        }
        else if(field == "WE"){
            stringstream(value) >> this->weight;
        }
        else if(field == "DE"){
            this->description = value;
        }
        else if(field == "CA"){
            stringstream(value) >> category;
            this->category.push_back((categories)category);
        }
        else if(field == "BY"){
            stringstream(value) >> this->size;
        }
        else if(field == "SS"){
            stringstream(value) >> this->ssd;
        }
        else if(field == "SEI"){
            stringstream(value) >> this->seller.ID;
        }
        else if(field == "SHI"){
            stringstream(value) >> this->shipper.ID;
        }
    }
}


string Disk::writeProduct() {
    stringstream s;
    s << "KI" << US << "DISK";
    writeProduct();
    for(vector<categories>::iterator it = this->category.begin(); it != this->category.end(); it++){
        s << RS << "CA" << US << *it;
    }
    s << RS << "BY" << US << this->size;
    s << RS << "SS" << US << this->ssd;
    s << RS << "SEI" << US << this->seller.ID;
    s << RS << "SHI" << US << this->shipper.ID;
    return s.str();
}