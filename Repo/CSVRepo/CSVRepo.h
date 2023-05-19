//
// Created by Luca Tudor on 17.05.2023.
//

#ifndef OOP_L6_CSVREPO_H
#define OOP_L6_CSVREPO_H

#include "../CRUDRepo/CRUDRepo.h"
#include "../Utils/Utils.h"

namespace repo {
    class CSVRepo : public CRUDRepo<Scooter> {
    private:
        string filename_;

        void saveToFile(const vector<Scooter> &scooterList);

        void loadFromFile();

    public:
        explicit CSVRepo(string filename);

        void add(const Scooter &scooter) override;

        bool remove(const Scooter &scooter) override;

        void removeAtIndex(int index) override;

        void update(int index, const Scooter &newScooter) override;

        void updateStatus(int index, Status status) override;

        int getIndexOf(const Scooter &scooter) override;

        Scooter getScooterAtIndex(int index) override;

        vector<Scooter> getAll() override;



    };
}

#endif //OOP_L6_CSVREPO_H
