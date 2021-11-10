//
// Created by Jairo Riaño on 13/04/20.
//

#include <sstream>
#include "Account.h"

const double Account::minResidue = 50000;

Account::Account() {
    this->number = std::string();
    this->customer = NULL;
    this->residue = 0;
    this->consignments = 0;
    this->withdrawals = 0;
}

Account::Account(Customer* customer, const std::string &number, double residue) : number(number), residue(residue) {
    //asignando valores de forma manual
    setNumber( number );
    setCustomer( customer );
    setResidue( residue);
    //inicializar contadores
    this->consignments = 0;
    this->withdrawals = 0;
}

void Account::setNumber(const std::string &number) {
    Account::number = number;
}

void Account::setCustomer(Customer *customer) {
    Account::customer = customer;
}

void Account::setResidue(double residue) {
    Account::residue = residue;
}

std::string Account::parseNum(double value) {
    std::ostringstream aux;
    aux << value;

    return aux.str();
}

const std::string &Account::getNumber() const {
    return number;
}

double Account::getResidue() const {
    return residue;
}

int Account::getConsignments() const {
    return consignments;
}

int Account::getWithdrawals() const {
    return withdrawals;
}

//consignar
void Account::consign(double value) {
    setResidue( getResidue() + value ); //establescer el residuo
    consignments++;
}

//retirar
bool Account::withDraw(double value) {
    if ( value <= getResidue() - Account::minResidue ){ //valor ingresado es menor que el saldo actual menos el saldo minimo
        setResidue( getResidue() - value );//el valor actual get - lo que deseo retirar
        withdrawals++;

        return true;
    }

    return false;
}

//tarnsferencia
bool Account::transfer(Account* account, double value) { //cuenta de destino y valor a transferir
    if ( withDraw( value) ){ //si puedo retirar el valor "value", es cierto
        account->consign( value );

        return true;
    }

    return false;
}

std::string Account::toString() {
    return "Account[number=" + number +", residue=" + parseNum( residue ) + ", consignments=" +
           parseNum( consignments) + ", withdrawals=" + parseNum( withdrawals) +"]\n";
}

Customer* Account::getCustomer() {
    return customer;
}

Account::~Account() {

}

