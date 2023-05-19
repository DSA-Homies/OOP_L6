//
// Created by Luca Tudor on 17.05.2023.
//

#ifndef OOP_L6_CRUDREPO_H
#define OOP_L6_CRUDREPO_H


#include <vector>
#include "../Domain/Scooter.h"


using namespace domain;

template <class T>
class CRUDRepo {
protected:
    vector<T> list;
public:
    explicit CRUDRepo(vector<T> initLIst){};
    virtual T getMyScooter() = 0;
    virtual void setMyScooter(const T& obj) = 0;
    virtual void add(const T& obj) = 0;
    virtual bool remove(const T& obj) = 0;
    virtual void removeAtIndex(int index) = 0;
    virtual void update(int index, const T& newObj) = 0;
    virtual void updateStatus(int index, Status status) = 0;
    virtual int getIndexOf(const T& obj) = 0;
    virtual T getScooterAtIndex(int index) = 0;
    virtual std::vector<T> getAll() = 0;
    virtual ~CRUDRepo() = default;
};


#endif //OOP_L6_CRUDREPO_H
