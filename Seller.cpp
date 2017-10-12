#include "Seller.h"

void Seller::printSeller() {
    cout << "Seller | ";
    cout << "name : " << this->name;
    cout << " | " << "ID : " << this->ID << endl;
}

void Seller::readSeller(string line) {
    stringstream s(line);
    string field;
    string value;


    while(getline(s, field, US)){

        getline(s, value, RS);
        if(field == "ID"){
            stringstream(value) >> this->ID;
        }
        else if(field == "NA"){
            this->name = value;
        }
    }
}


string Seller::writeSeller() {
    stringstream s;
    s << "KI" << US << "SELLER";
    s << RS << "ID" << US << this->ID;
    s << RS << "NA" << US << this->name;
    return s.str();
}