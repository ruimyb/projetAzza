#include "string.h"
#include "Customer.h"



void Customer::printCustomer() {
    cout << "Customer | ";
    cout << "name : " << this->first_name;
    cout << " " << this->last_name;
    cout << " | " << "adresse: " << this->address;
    cout << " @ " << "ID : " << this->ID << endl;
}

void Customer::readCustomer(string line) {
    stringstream s(line);
    string field;
    string value;

    while(getline(s, field, US)){

        getline(s, value, RS);
        if(field == "ID"){
            stringstream(value) >> this->ID;
        }
        else if(field == "AD"){
            this->address = value;
        }
        else if(field == "FN"){
            this->first_name = value;
        }
        else if(field == "LN"){
            this->last_name = value;
        }
    }
}


string Customer::writeCustomer() {
    stringstream s;
    s << "KI" << US << "CUSTOMER";
    s << RS << "ID"<< US<<this->ID;
    s << RS << "AD" << US << this->address;
    s << RS << "FN" << US << this->first_name;
    s << RS << "LN" << US << this->last_name;
    return s.str();
}