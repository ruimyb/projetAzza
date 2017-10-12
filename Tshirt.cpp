//
// Created by Ruimy Benjamin Mac on 12/10/2017.
//

#include "Tshirt.h"

Tshirt::Tshirt(string brand1){
    brand = brand1;
}

Tshirt::Tshirt(){
    cout << "To Change";

}




void Tshirt::printTshirt() {
    cout << "Tshirt | ";
    printProduct();
// Ici j'essaye de réutiliser la fonction print de la classe parente afin de ne pas avoir chaque fois à redéfinir le meme code.
// De manière générale, j'essaie d' éviter la duplication de code, ça évite de dupliquer les erreurs ou d'en faire sur des bouts de code équivalent.
    cout << " | " << "brand: " << this->brand;
}
// j'aimerai bien faire la meme chose avec les fonctions read, mais e ne vois vraiment pas comment faire.
void Tshirt::readProduct(string line) {
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
        else if(field == "BR"){
            this->brand = value;
        }
        else if(field == "SEI"){
            stringstream(value) >> this->seller.ID;
        }
        else if(field == "SHI"){
            stringstream(value) >> this->shipper.ID;
        }
    }
}


string Tshirt::writeProduct() {
    stringstream s;
    s << "KI" << US << "TSHIRT";
    writeProduct();
    for(vector<categories>::iterator it = this->category.begin(); it != this->category.end(); it++){
        s << RS << "CA" << US << *it;
    }
    s << RS << "BR" << US << this->brand;
    s << RS << "SEI" << US << this->seller.ID;
    s << RS << "SHI" << US << this->shipper.ID;
    return s.str();
}