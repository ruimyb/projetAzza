

#include "Laptop.h"

Laptop::Laptop(CPU cpu1, Memory memory1, Disk disk1, Graphics gpu1){
    cpu = cpu1;
    memory = memory1;
    disk = disk1;
    gpu = gpu1;
}

Laptop::Laptop(){

}

void Laptop::printProduct() {
    cout << "Laptop | ";
    printProduct();
    cout << " | " << "CPU: " << this->cpu.ID;
    cout << " | " << "Memory: " << this->memory.ID;
    cout << " | " << "Disk: " << this->disk.ID;
    cout << " | " << "GPU: " << this->gpu.ID;

}


void Laptop::readProduct(string line) {
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
        else if(field == "CPI"){
            stringstream(value) >> this->cpu.ID;
        }
        else if(field == "MEI"){
            stringstream(value) >> this->memory.ID;
        }
        else if(field == "DII"){
            stringstream(value) >> this->disk.ID;
        }
        else if(field == "GRI"){
            stringstream(value) >> this->gpu.ID;
        }
        else if(field == "SEI"){
            stringstream(value) >> this->seller.ID;
        }
        else if(field == "SHI"){
            stringstream(value) >> this->shipper.ID;
        }
    }
}


string Laptop::writeProduct() {
    stringstream s;
    s << "KI" << US << "LAPTOP";
    writeProduct();
    for(vector<categories>::iterator it = this->category.begin(); it != this->category.end(); it++){
        s << RS << "CA" << US << *it;
    }
    s << RS << "CPI" << US << this->cpu.ID;
    s << RS << "MEI" << US << this->memory.ID;
    s << RS << "DII" << US << this->disk.ID;
    s << RS << "GRI" << US << this->gpu.ID;
    s << RS << "SEI" << US << this->seller.ID;
    s << RS << "SHI" << US << this->shipper.ID;
    return s.str();
}