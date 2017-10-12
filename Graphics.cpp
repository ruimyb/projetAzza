
#include "Graphics.h"

void Graphics::printProduct() {
    cout << "Graphics | ";
    printProduct();
    cout << " | " << "PCIe: " << this->PCIe;
}


void Graphics::readProduct(string line) {
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
        else if(field == "PE"){
            stringstream(value) >> this->PCIe;
        }
        else if(field == "SEI"){
            stringstream(value) >> this->seller.ID;
        }
        else if(field == "SHI"){
            stringstream(value) >> this->shipper.ID;
        }
    }
}


string Graphics::writeProduct() {
    stringstream s;
    s << "KI" << US << "GRAPHICS";
    writeProduct();
    for(vector<categories>::iterator it = this->category.begin(); it != this->category.end(); it++){
        s << RS << "CA" << US << *it;
    }
    s << RS << "PE" << US << this->PCIe;
    s << RS << "SEI" << US << this->seller.ID;
    s << RS << "SHI" << US << this->shipper.ID;
    return s.str();
}