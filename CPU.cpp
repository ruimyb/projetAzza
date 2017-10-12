

#include "CPU.h"

void CPU::printProduct() {
    cout << "CPU | ";
    printProduct();
    cout << " | " << "number of cores: " << this->cores;
    cout << " | " << "frequency: " << this->frequency;

}


void CPU::readProduct(string line) {
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
        else if(field == "CO"){
            stringstream(value) >> this->cores;
        }
        else if(field == "HZ"){
            stringstream(value) >> this->frequency;
        }
        else if(field == "SEI"){
            stringstream(value) >> this->seller.ID;
        }
        else if(field == "SHI"){
            stringstream(value) >> this->shipper.ID;
        }
    }
}


string CPU::writeProduct() {
    stringstream s;
    s << "KI" << US << "CPU";
    writeProduct();
    for(vector<categories>::iterator it = this->category.begin(); it != this->category.end(); it++){
        s << RS << "CA" << US << *it;
    }
    s << RS << "CO" << US << this->cores;
    s << RS << "HZ" << US << this->frequency;
    s << RS << "SEI" << US << this->seller.ID;
    s << RS << "SHI" << US << this->shipper.ID;
    return s.str();
}