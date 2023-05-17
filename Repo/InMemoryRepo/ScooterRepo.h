#ifndef OOP_L5_SCOOTERREPO_H
#define OOP_L5_SCOOTERREPO_H

#include <vector>
#include "Scooter.h"

using namespace std;
using namespace domain;

namespace repo {

    class ScooterRepo {
    private:
        vector<Scooter> scooterList;
        Scooter myScooter{};

    public:
        [[nodiscard]] Scooter getMyScooter() const;

        void setMyScooter(const Scooter &_myScooter);

        explicit ScooterRepo(vector<Scooter> initList = {});

        void add(const Scooter &scooter);

        bool remove(const Scooter &scooter);

        void remove(int index);

        void update(int index, const Scooter &newScooter);

        void updateStatus(int index, Status status);

        int getIndexOf(const Scooter &scooter);

        Scooter getScooterAtIndex(int index);

        vector<Scooter> getAll();
    };
}

#endif //OOP_L5_SCOOTERREPO_H
