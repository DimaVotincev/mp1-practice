#pragma once
#include "Date.h"

class Passport {
private:
    int seria;
    int nomer;
    std::string kem;
    Date kogda;
    Date birthday;
    std::string propiska;
public:
    Passport();
    
    void show_pass();
};