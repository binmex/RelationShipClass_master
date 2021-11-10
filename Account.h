//
// Created by Jairo Riaño on 13/04/20.
//

#ifndef PRJBANK_ACCOUNT_H
#define PRJBANK_ACCOUNT_H

#include <string>
#include "Customer.h"

class Customer;//esperara a que la clase customer este lista

class Account {
public:
    const static double minResidue;
    Account();//constructor vacio
    Account(Customer*, const std::string &number, double residue); //constructor con parametros
    void setCustomer( Customer* );
    void setNumber(const std::string &number);
    const std::string &getNumber() const;
    double getResidue() const;
    int getConsignments() const;
    int getWithdrawals() const;
    Customer* getCustomer(); //retorna u apuntador del cliente
    void consign(double);
    bool withDraw(double);
    bool transfer(Account*, double);
    static std::string parseNum(double);//pasar de un valor numerico a String
    std::string toString();
    virtual ~Account();

private:
    std::string number;
    double residue;
    int consignments;
    int withdrawals; //retiros
    Customer* customer; //referencia al cliente (Asociacion con un cliente)

    void setResidue( double );
};


#endif //PRJBANK_ACCOUNT_H
