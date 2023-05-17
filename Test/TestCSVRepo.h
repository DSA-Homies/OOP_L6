//
// Created by Luca Tudor on 17.05.2023.
//

#ifndef OOP_L6_TESTCSVREPO_H
#define OOP_L6_TESTCSVREPO_H

#include <iostream>
#include <cassert>
#include "../Repo/CSVRepo/CSVRepo.h"
#include "../Utils/Utils.h"

void testCSVRepo() {

    cout << "Testing CSV Repo..." << endl;

    CSVRepo repo("../Repo/DataBase/testDataBase1.csv");

    Scooter scooter1("aaa", "Bolt 4", "16-05-2023", 10.0, "Str. Blaga", Status::PARKED);

    repo.add(scooter1);

    assert(repo.getIndexOf(scooter1) == 0);

    cout << "CSV Repo tested successfully!" << endl;
}

#endif //OOP_L6_TESTCSVREPO_H
