//
// Created by Luca Tudor on 17.05.2023.
//

#include <fstream>
#include <sstream>
#include "CSVRepo.h"

CSVRepo::CSVRepo(const string &filename) : filename_(filename){

}

void CSVRepo::add(const Scooter &scooter) {

    vector <Scooter> scooterList;
    scooterList.push_back(scooter);
    saveToFile(scooterList);
}

bool CSVRepo::remove(const Scooter &scooter) {

    vector <Scooter> scooterList = loadFromFile();
    auto it = std::find(scooterList.begin(), scooterList.end(), scooter);
    if(it != scooterList.end()) {
        scooterList.erase(it);
        saveToFile(scooterList);
        return true;
    }
    return false;
}

void CSVRepo::update(int index, const Scooter &newScooter) {

    vector <Scooter> scooterList = loadFromFile();
    if(index < 0 || index > scooterList.size()) {
        throw out_of_range("CSVRepo::update(): Index out of range for index " + to_string(index));
    }

    scooterList[index] = newScooter;
    saveToFile(scooterList);
}

void CSVRepo::updateStatus(int index, Status status) {

        vector <Scooter> scooterList = loadFromFile();
        if(index < 0 || index > scooterList.size()) {
            throw out_of_range("CSVRepo::updateStatus(): Index out of range for index " + to_string(index));
        }

        scooterList[index].setStatus(status);
        saveToFile(scooterList);
}

int CSVRepo::getIndexOf(const Scooter &scooter) {

    vector <Scooter> scooterList = loadFromFile();
    auto it = std::find(scooterList.begin(), scooterList.end(), scooter);
    if(it != scooterList.end()) {
        return std::distance(scooterList.begin(), it);
    }
    return -1;
}

Scooter CSVRepo::getScooterAtIndex(int index) {

    vector <Scooter> scooterList = loadFromFile();
    if(index < 0 || index > scooterList.size()) {
        throw out_of_range("CSVRepo::getScooterAtIndex(): Index out of range for index " + to_string(index));
    }
    return scooterList[index];
}

vector<Scooter> CSVRepo::getAll() {

    return loadFromFile();
}

void CSVRepo::saveToFile(const vector<Scooter> &scooterList) {
    ofstream file(filename_);
    if(file.is_open()) {
        for(const auto& scooter : scooterList) {
            file << scooter.getId() << "," << scooter.getModel() << "," << timeToStr(scooter.getCommissioningDate()) << ","
            << scooter.getKilometer() << "," << scooter.getLocation() << "," << scooter.getStatus() << "\n";
        }
        file.close();
    } else {
        throw runtime_error("Could not open file!");
    }
}

vector<Scooter> CSVRepo::loadFromFile() {

    std::ifstream file(filename_);
    vector <Scooter> scooterList;

    if(file.is_open()) {
        string line;
        while(getline(file, line)) {
            stringstream iss(line);
            string id, model, commissioningDate, kilometer, location, status;
            if (std::getline(iss, id, ',') && std::getline(iss, model, ',') &&
            std::getline(iss, commissioningDate) && std::getline(iss, kilometer) &&
            std::getline(iss, location) && std::getline(iss, status)) {
                scooterList.emplace_back(id, model, strToTime(commissioningDate, kilometer, location, Status(std::stoi(status)));
            }
        }
        file.close();
    } else {
        throw runtime_error("Could not open file!");
    }
    return scooterList;
}
