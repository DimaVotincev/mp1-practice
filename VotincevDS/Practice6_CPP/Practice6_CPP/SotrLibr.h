#pragma once
#include "Sotrudnik.h"
class SotrLibr {
private:
    int n;
    Sotrudnik* sotr;

public:
    SotrLibr();
    SotrLibr(const SotrLibr&);
    SotrLibr(const SotrLibr& , int);
    SotrLibr(int n);
    ~SotrLibr();

    Sotrudnik* get_sotr() { return this->sotr; };
    

    int get_size() { return this->n; };
    friend std::ifstream& operator>>(std::ifstream& inf, SotrLibr& sl);
};


