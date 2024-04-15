
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

SotrLibr::~SotrLibr() {
    if (this->sotr == nullptr) {

    }
    delete[]this->sotr;
    this->n = 0;
}

//void SotrLibr::set_size(int) {
//
//}
//
//SotrLibr& SotrLibr::operator=(SotrLibr& sl) {
//    if (this->sotr != nullptr) {
//        delete []this;
//    }
//    this->n = sl.n;
//    this->sotr = new Sotrudnik[this->n];
//    for (int i = 0; i < this->n;i++) {
//        this->sotr[i] = sl.sotr[i];
//    }
//    
//    return *this;
//}

std::ifstream& operator>>(std::ifstream& inf, SotrLibr& sl) {
    if (sl.sotr != nullptr) {
        delete []sl.sotr;
    }
    std::string tmp;
    inf >> tmp;
    getline(inf,tmp);
    sl.n = stoi(tmp);
    sl.sotr = new Sotrudnik[sl.n];
    for (int i = 0; i < sl.n;i++) {
        inf >> sl.sotr[i];
        getline(inf, tmp);
    }

    return inf;
}
