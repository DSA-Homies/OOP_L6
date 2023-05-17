//
// Created by Luca Tudor on 17.05.2023.
//

#ifndef OOP_L6_CSVREPO_H
#define OOP_L6_CSVREPO_H

#include "../CRUDRepo/CRUDRepo.h"

class CSVRepo : public CRUDRepo<Scooter>{
private:
    string filename;
    void loadFromFile();
    void writeToFile();

public:
    explicit CSVRepo(const string& filename);

    void add(const Scooter& scooter) override;
    bool remove(const Scooter& scooter) override;
    void update(int index, const Scooter& newScooter) override;
    void updateStatus(int index, Status status) override;
    int getIndexOf(const Scooter& scooter) override;
    Scooter getScooterAtIndex(int index) override;
    vector<Scooter> getAll() override;

};


#endif //OOP_L6_CSVREPO_H
