//
// Created by Jairo Riaño on 13/04/20.
//

#include "ManagementBank.h"

ManagementBank::ManagementBank() {

}
//buscar cliente
Customer *ManagementBank::findCustomer(std::string idCustomer) {
    //for each, defino la clase-objeto - arreglo que voy a recorrer
    for( Customer* customer : customers ){
        if( customer->getIdCustomer().compare( idCustomer ) == 0 ){
            return customer;
        }
    }

    return NULL;
}
//agregar cliente
bool ManagementBank::addCustomer(std::string idCustomer, std::string firstName, std::string lastName, EGender gender, std::string phone) {
    if ( !findCustomer(idCustomer) ){
        customers.push_back(new Customer(idCustomer,firstName,lastName,gender,phone));

        return true;
    }

    return false;
}

//cuentas buscar
Account *ManagementBank::findAccount(std::string number) {
    for( Account* account : accounts ){
        if ( account->getNumber().compare(number) == 0 ){
            return account;
        }
    }

    return NULL;
}


//Agregar cuentas
bool ManagementBank::addAccount(std::string idCustomer, std::string number, double value) {
    //variable local customer apuntador a Customer
    Customer* customer = findCustomer( idCustomer);
    if ( customer ){
        if ( !findAccount( number ) ){
            Account* account = new Account(customer,number,value);//crear cuenta
            accounts.push_back( account );//agregar al arreglo de cuentas
            customer->addAccount( account ); //al cliente le agrego la cuenta que cree en la linea

            return true;
        }

        return false;
    }

    return false;
}
//consignar
bool ManagementBank::consign(std::string number, double value) {
    Account* account = findAccount( number ); //referencia de la cuenta
    if( account ){
        account->consign( value );

        return true;
    }

    return false;
}

//retirar -- recibo numero de la cuenta y el valor
bool ManagementBank::withDraw(std::string number, double value) {
    Account* account = findAccount( number );
    if( account ){
        return account->withDraw( value );
    }
    return false;
}

//transferir -- buscar cuenta origen y destino - valor
bool ManagementBank::transfer(std::string source, std::string target, double value) {
    Account* ctaSource = findAccount(source);
    Account* ctaTarget = findAccount(target);
    if(ctaSource && ctaTarget){
       return ctaSource->transfer( ctaTarget, value );
    }

    return false;
}

//retorna clientes
std::vector<Customer *> ManagementBank::getCustomers() {
    return std::vector<Customer *>(customers);
}

ManagementBank::~ManagementBank() {

}

//retorna cuentas
std::vector<Account *> ManagementBank::getAccounts() {
    return std::vector<Account *>( accounts );
}

