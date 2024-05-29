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
    
public:
    Sotrudnik();
    Sotrudnik(const Sotrudnik& sotr);
    

    void print_dates(); 
    // вывод даты назначения и поступления (определенный формат вывода)

    void print_generalinfo(); 
    // вывод общей информации 
    // (образование,специальность,подразделение,должность,оклад,пенсионер ли)
    
    
    Name get_name() const { return this->name; }
    Passport get_pass() const { return this->passport;  }

    int is_old() const;
    

    const Sotrudnik& operator=(const Sotrudnik& sotr);
    
    friend std::ifstream& operator>>(std::ifstream& inf, Sotrudnik&);
    friend std::ostream& operator<<(std::ostream& out, Sotrudnik&);
};

