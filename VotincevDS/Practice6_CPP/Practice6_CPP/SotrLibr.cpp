
#include <string>
#include <iostream>
#include <fstream>
#include "SotrLibr.h"



SotrLibr::SotrLibr() {
    this->n = 0;
    this->sotr = nullptr;
}

SotrLibr::SotrLibr(int n) {
    this->n = n;
    this->sotr = new Sotrudnik[n];
}

SotrLibr::SotrLibr(const SotrLibr& sl) {
    this->n = sl.n;
    this->sotr = new Sotrudnik[this->n]; 
    for (int i = 0; i < this->n;i++) {
        this->sotr[i] = sl.sotr[i];
    }
}


SotrLibr::SotrLibr(const SotrLibr& sl, int k) {
    int count = 0;
    if (k) {
        
        for (int i = 0; i < sl.n;i++) {
            if (sl.sotr[i].get_old() == 1) {
                count++;
            }
        }
    }
    else {
        std::cout << "Данный оператор предназначен" <<
            " только для библиотеки пенсионеров!";
        abort();
    }
    this->n = count;
    this->sotr = new Sotrudnik[this->n];
    count = 0;
    for (int i = 0; i < sl.n;i++) {
        if (sl.sotr[i].get_old() == 1) {
            this->sotr[count] = sl.sotr[i];
            count++;
            if (count == this->n) {
                return;
            }
        }
    }
}

SotrLibr::~SotrLibr() {
    if (this->sotr == nullptr) {

    }
    delete[]this->sotr;
    this->n = 0;
}


std::ifstream& operator>>(std::ifstream& inf, SotrLibr& sl) {
    
    std::string tmp;
    sl.sotr = new Sotrudnik[sl.n];
    for (int i = 0; i < sl.n;i++) {
        inf >> sl.sotr[i];
        getline(inf, tmp);
    }

    return inf;
}
