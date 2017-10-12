
#include "Smartwatch.h"



void Smartwatch::printProduct() {
    cout << "Smartwatch | ";
    printProduct();
    cout << " | " << "CPU: " << this->cpu.ID;
    cout << " | " << "Memory: " << this->memory.ID;
    cout << " | " << "color: " << this->c;
}


void Smartwatch::readProduct(string line) {
    stringstream s(line);
    string field;
    string value;
    int category;
    int colors;

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
        else if(field == "CPI"){
            stringstream(value) >> this->cpu.ID;
        }
        else if(field == "MEI"){
            stringstream(value) >> this->memory.ID;
        }
        else if(field == "CO"){
            stringstream(value) >> colors;
            this->c = (color)colors;
        }
        else if(field == "SEI"){
            stringstream(value) >> this->seller.ID;
        }
        else if(field == "SHI"){
            stringstream(value) >> this->shipper.ID;
        }
    }
}


string Smartwatch::writeProduct() {
    stringstream s;
    s << "KI" << US << "SMARTWATCH";
    writeProduct();
    for(vector<categories>::iterator it = this->category.begin(); it != this->category.end(); it++){
        s << RS << "CA" << US << *it;
    }
    s << RS << "CPI" << US << this->cpu.ID;
    s << RS << "MEI" << US << this->memory.ID;
    s << RS << "CO" << US << this->c;
    s << RS << "SEI" << US << this->seller.ID;
    s << RS << "SHI" << US << this->shipper.ID;
    return s.str();
}
