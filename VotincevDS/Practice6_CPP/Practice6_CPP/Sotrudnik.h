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
    Sotrudnik(Sotrudnik& sotr);

    void print_sotr();
    void print_dates();
    void print_generalinfo();
    int get_old() { return this->is_old; };
    Name& get_name() { return this->name; }
    Passport& get_pass() { return this->passport;  }

    void define_old();

    Sotrudnik& operator=(Sotrudnik& sotr);
    
    friend std::ifstream& operator>>(std::ifstream& inf, Sotrudnik&);

};

