#pragma once
#include "Sotrudnik.h"
class SotrLibr {
private:
    int n;
    Sotrudnik* sotr;

public:
    SotrLibr();
    SotrLibr(int n);
    ~SotrLibr();
    void set_size(int);
    int get_size() { return this->n; };

    SotrLibr& operator=(SotrLibr& sl);
    friend std::ifstream& operator>>(std::ifstream& inf, SotrLibr& sl);
};


