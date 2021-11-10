#include <iostream>
#include "ManagementBank.h"

using namespace std;
//ManagementBank* bank;

void setup();
void addClient();

void addAcounts();

void consig();

void withDraw();

void transfer();

ManagementBank* bank;

int main() {
    addClient();
    addAcounts();
    consig();
    withDraw();
    transfer();
    return EXIT_SUCCESS;
}

void transfer() {
    setup();
    if(bank->transfer("555555","666666",150000)){
        cout<<"Hecho se realizo la transferencia"<<endl;
        cout<<bank->findAccount("555555")->toString();
        cout<<bank->findAccount("666666")->toString();
    } else{
        cout<<"Error transferencia imposible"<<endl;
    }
}

void withDraw() {
    setup();
    if(bank->withDraw("555555",120000)){
        cout<<"Retiro realizado"<<endl;
        cout<<bank->findAccount("555555")->toString();
    } else{
        cout<<"error no se retiro de la cuenta"<<endl;
    }
}

void consig() {
    setup(); ///datos iniciales
    if (bank->consign("555555",2000)){
        cout<<"Consignacion exitosa"<<endl;
        cout<<bank->findAccount("555555")->toString();

    }
}

void addAcounts() {
    setup();
    if(bank->addAccount("000000","8965855",785822)){
        cout<<"cuenta agregada"<<endl;
    } else{
        cout<<"Error Cuenta no Agregada"<<endl;
    }

    /*for(Account* account : bank->getAccounts()){
        cout<<account->toString()<<"-->"<<account->getCustomer()->toString();
    }*/
}

void setup(){
     bank = new ManagementBank();
    bank->addCustomer("897645", "juan Pablo", "peres Gomez", EGender::MALE,"335522");
    bank->addCustomer("784505", "Maria Auxilio", "Dolores Perez", EGender::FEMALE,"34545478");
    bank->addCustomer("897645", "juan Pablo", "peres Gomez", EGender::MALE,"335522");

    bank->addAccount("897645", "555555", 600000);
    bank->addAccount("897645", "666666", 500000);
    bank->addAccount("784505","777777", 350000);
}

void addClient(){
    setup();
    for(Account* account : bank->getAccounts()){
        cout<<account->toString()<<"-->"<<account->getCustomer()->toString();
    }
}
