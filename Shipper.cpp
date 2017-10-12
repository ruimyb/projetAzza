

#include "Shipper.h"
void Shipper::printShipper() {
    cout << "Shipper | ";
    cout << "name : " << this->name;
    cout << " | " << "ID : " << this->ID << endl;
}

void Shipper::readShipper(string line) {
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


string Shipper::writeShipper() {
    stringstream s;
    s << "KI" << US << "SHIPPER";
    s << RS << "ID" << US << this->ID;
    s << RS << "NA" << US << this->name;
    return s.str();
}