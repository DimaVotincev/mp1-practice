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
    Passport(const Passport&);

    Date get_birthday() const;
    const Passport& operator=(const Passport& pass);
    friend std::ifstream& operator>>(std::ifstream& inf, Passport& pass);
    friend std::ostream& operator<<(std::ostream& out, Passport& pass);
    friend std::ostream& operator<<(std::ostream& out, Passport pass);
};