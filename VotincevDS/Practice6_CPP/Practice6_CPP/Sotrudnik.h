#pragma once
#include "Date.h"
#include "Passport.h"
class Sotrudnik {
public:
    std::string name;
    std::string gender;
    Passport passport;
    std::string obrazov;
    std::string specialnost;
    std::string podrazd;
    std::string dolznost;
    int oklad;
    Date postuplenie;
    Date naznachenie;
    int is_old;
};


