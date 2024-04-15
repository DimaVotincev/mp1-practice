#pragma once
#include "Date.h"
#include "Passport.h"
#include "Gender.h"
#include "Name.h"


class Sotrudnik {
private:
    Name name;
    Gender gender;
    Passport passport;
    std::string obrazov;
    std::string specialnost;
    std::string podrazd;
    std::string dolznost;
    int oklad;
    Date postuplenie;
    Date naznachenie;
    int is_old;
public:
    Sotrudnik();
    
    void define_old();
    friend std::ostream& operator<<(std::ostream& out, Sotrudnik& Sotrudnik);
    friend std::ifstream& operator>>(std::ifstream& inf, Sotrudnik&);

};


