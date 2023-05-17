//
// Created by Luca Tudor on 17.05.2023.
//

#ifndef OOP_L6_CRUDREPO_H
#define OOP_L6_CRUDREPO_H


template <class T>
class CRUDRepo {

private:
    virtual void add(const T& scooter) = 0;
};


#endif //OOP_L6_CRUDREPO_H
