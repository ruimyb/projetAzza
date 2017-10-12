#include "database-2.hpp"
#include <fstream>
#include "Database.h"
#include "Product.h"
#include "Seller.h"
#include "Shipper.h"
#include "Customer.h"
using namespace std;

int main()

{

	
    /*	test de la lecture */
    
    Database database;
	ifstream db;
	db.open("db.txt");
	database.readDatabase(db);
	db.close();

    /*	test de l'ecriture */
	
	ofstream newDatabase;
	newDatabase.open("newDatabase.txt");
	database.writeDatabase(newDatabase);
	newDatabase.close(); //Mise à jour de la database visible dans le fichier newdatabase.txt


    /*	test des fonctions "get" */
	
	Product* prod = database.getProduct(18);
	prod->printProduct();
	Seller* sell = database.getSeller(3);
	sell->printSeller();
	Shipper* ship = database.getShipper(1);
	ship->printShipper();
	Customer* cust = database.getCustomer(9);
	cust->printCustomer();

    /*	test des fonctions "add" */

	database.addCustomer(10, "Francis", "Desmoutis", "6 rue des lices");
	database.myCustomers.back()->printCustomer();
	database.addSeller(9, "Jean Baptiste");
	database.mySellers.back()->printSeller();
	database.addShipper(5, "Jo");
	database.myShippers.back()->printShipper();

	return 0;
}
