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
    Sotrudnik(const Sotrudnik& sotr);
    
    
    void print_dates(); // вывод даты назначения и поступления
    void print_generalinfo(); // вывод общей информации
    int get_old() { return this->is_old; };
    Name& get_name() { return this->name; }
    Passport& get_pass() { return this->passport;  }

    void define_old();

    Sotrudnik& operator=(const Sotrudnik& sotr);
    
    friend std::ifstream& operator>>(std::ifstream& inf, Sotrudnik&);
    friend std::ostream& operator<<(std::ostream& out, Sotrudnik&);
};

