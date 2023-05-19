//
// Created by Luca Tudor on 17.05.2023.
//

#include <fstream>
#include <sstream>
#include "CSVRepo.h"
#include <algorithm>
#include <utility>

using namespace repo;

CSVRepo::CSVRepo(string filename) : filename_(std::move(filename)) {

}

void CSVRepo::add(const Scooter &scooter) {
    list.push_back(scooter);
    saveToFile(list);
}

bool CSVRepo::remove(const Scooter &scooter) {
    loadFromFile();
    auto it = find(list.begin(), list.end(), scooter);
    if (it != list.end()) {
        list.erase(it);
        saveToFile(list);
        return true;
    }
    return false;
}

void CSVRepo::update(int index, const Scooter &newScooter) {
    loadFromFile();
    if (index < 0 || index > list.size()) {
        throw out_of_range("CSVRepo::update(): Index out of range for index " + to_string(index));
    }

    list[index] = newScooter;
    saveToFile(list);
}

void CSVRepo::updateStatus(int index, Status status) {
    loadFromFile();
    if (index < 0 || index > list.size()) {
        throw out_of_range("CSVRepo::updateStatus(): Index out of range for index " + to_string(index));
    }

    list[index].setStatus(status);
    saveToFile(list);
}

int CSVRepo::getIndexOf(const Scooter &scooter) {
    loadFromFile();
    auto it = std::find(list.begin(), list.end(), scooter);
    if (it != list.end()) {
        return (int) std::distance(list.begin(), it);
    }
    return -1;
}

Scooter CSVRepo::getScooterAtIndex(int index) {
    loadFromFile();
    if (index < 0 || index > list.size()) {
        throw out_of_range("CSVRepo::getScooterAtIndex(): Index out of range for index " + to_string(index));
    }
    return list[index];
}

vector<Scooter> CSVRepo::getAll() {
    return list;
}

void CSVRepo::saveToFile(const vector<Scooter> &scooterList) {
    ofstream file(filename_, ios::out);
    if (file.is_open()) {
        for (const auto &scooter: scooterList) {
            file << scooter.getId() << "," << scooter.getModel() << "," << timeToStr(scooter.getCommissioningDate())
                 << ","
                 << scooter.getKilometer() << "," << scooter.getLocation() << "," << scooter.getStatus() << "\n";
        }
        file.close();
    } else {
        throw runtime_error("Could not open file!");
    }
}

void CSVRepo::loadFromFile() {
    ifstream file(filename_);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string id, model, commissioningDate, kilometer, location, status;
            if (getline(iss, id, ',') && getline(iss, model, ',') &&
                getline(iss, commissioningDate) && getline(iss, kilometer) &&
                getline(iss, location) && getline(iss, status)) {
                list.emplace_back(id, model, strToTime(commissioningDate), stof(kilometer), location,
                                  Status(stoi(status)));
            }
        }
        file.close();
    } else {
        throw runtime_error("Could not open file!");
    }
}

void CSVRepo::removeAtIndex(int index) {
    loadFromFile();
    if (index < 0 || index > list.size())
        throw out_of_range("CSVRepo::removeAtIndex(): Index out of range for index " + to_string(index));

    list.erase(list.begin() + index);
    saveToFile(list);
}
