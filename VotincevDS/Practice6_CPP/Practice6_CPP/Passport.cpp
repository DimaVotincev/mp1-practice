#include <iostream>
#include <fstream>
#include <string>
#include "Passport.h"
#include "Date.h"
#include "general.h"


Passport::Passport() {
    Date date;
    this->seria = 0;
    this->nomer = 0;  
    this->kem = "";
    this->kogda = date;
    this->birthday = date;
    this->propiska = "";
     
}

Passport::Passport(const Passport& p) {
    this->seria = p.seria;
    this->nomer = p.nomer;
    this->kem = p.kem;
    this->kogda = p.kogda;
    this->birthday = p.birthday;
    this->propiska = p.propiska;
}

Date Passport::get_birthday() const {
    return this->birthday;
}

const Passport& Passport::operator=(const Passport& pass) {
    this->seria = pass.seria;
    this->nomer = pass.nomer;
    this->kem = pass.kem;
    this->kogda = pass.kogda;
    this->birthday = pass.birthday;
    this->propiska = pass.propiska;
    return *this;
}

std::ifstream& operator>>(std::ifstream& inf, Passport& pass) {
    std::string tmp;

    // серия
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.seria = stoi(tmp);
    
    // номер
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.nomer = stoi(tmp);

    // кем
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.kem = tmp;

    // когда
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.kogda.set_str(tmp);
    pass.kogda.make_good_date();

    // др
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.birthday.set_str(tmp);
    pass.birthday.make_good_date();

    // прописка
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.propiska = tmp;


    //date.make_good_date();
    return inf;
}

std::ostream& operator<<(std::ostream& out, Passport& pass) {
    std::cout << "Серия: " << pass.seria << '\n';
    std::cout << "Номер: " << pass.nomer << '\n';
    std::cout << "Кем выдан: " << pass.kem << '\n';
    std::cout << "Когда выдан: " << pass.kogda << '\n';
    std::cout << "Дата рождение: " << pass.birthday << '\n';
    std::cout << "Прописка: " << pass.propiska << '\n';
    return out;
}

std::ostream& operator<<(std::ostream& out, Passport pass) {
    std::cout << "Серия: " << pass.seria << '\n';
    std::cout << "Номер: " << pass.nomer << '\n';
    std::cout << "Кем выдан: " << pass.kem << '\n';
    std::cout << "Когда выдан: " << pass.kogda << '\n';
    std::cout << "Дата рождение: " << pass.birthday << '\n';
    std::cout << "Прописка: " << pass.propiska << '\n';
    return out;
}