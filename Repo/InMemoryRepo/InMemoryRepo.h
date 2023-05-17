#ifndef OOP_L5_SCOOTERREPO_H
#define OOP_L5_SCOOTERREPO_H

#include <vector>
#include "Scooter.h"

#include "../Domain/Scooter.h"
#include "../Repo/CRUDRepo/CRUDRepo.h"

using namespace std;
using namespace domain;

namespace repo {

    class InMemoryRepo : public CRUDRepo<Scooter>{
    private:
        vector<Scooter> scooterList;
        Scooter myScooter{};

    public:
        [[nodiscard]] Scooter getMyScooter() const;

        void setMyScooter(const Scooter &_myScooter);

        explicit InMemoryRepo(vector<Scooter> initList = {});

        void add(const Scooter& scooter) override;

        bool remove(const Scooter &scooter) override;

        void remove(int index);

        void update(int index, const Scooter &newScooter) override;

        void updateStatus(int index, Status status) override;

        int getIndexOf(const Scooter &scooter) override;

        Scooter getScooterAtIndex(int index) override;

        vector<Scooter> getAll() override;
    };
}

#endif //OOP_L5_SCOOTERREPO_H
