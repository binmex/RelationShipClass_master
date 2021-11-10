//
// Created by Jairo Riaño on 13/04/20.
//

#ifndef PRJBANK_CUSTOMER_H
#define PRJBANK_CUSTOMER_H

#include <vector>
#include "Account.h"
#include "EGender.h"

class Account; //esperar a que la clase account este lista

class Customer {
public:
    Customer();

    Customer(const std::string &idCustomer, const std::string &firstName, const std::string &lastName, EGender gender,
             const std::string &phone);

    const std::string &getIdCustomer() const;

    void setIdCustomer(const std::string &idCustomer);

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    EGender getGender() const;

    void setGender(EGender gender);

    const std::string &getPhone() const;

    void setPhone(const std::string &phone);

    Account* findAccount( std::string );

    void addAccount( Account*  );

    std::vector<Account*> getAccounts();

    std::string toString();

    virtual ~Customer();

private:
    std::string idCustomer;
    std::string firstName;
    std::string lastName;
    EGender gender; //definir referencia a clase enum
    std::string phone;
    std::vector<Account*> accounts;//relacion con cuentas(Muchos)//va a almacenar objetos de cuentas / lo ultimo es el nombre(definir vector o coleccion)
};


#endif //PRJBANK_CUSTOMER_H
