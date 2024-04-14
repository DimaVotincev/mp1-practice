#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "time.h"
#include "Sotrudnik.h"
#include "general.h"

Sotrudnik::Sotrudnik() {
    std::string str;
    Name ntmp;
    Passport ptmp;
    Date dtmp;
    this->name = ntmp;
    this->gender = MALE;
    this->passport = ptmp;
    this->obrazov = str;
    this->specialnost = str;
    this->podrazd = str;
    this->dolznost = str;
    this->oklad = 0;
    this->postuplenie = dtmp;
    this->naznachenie = dtmp;
    this->is_old = -1;
}

void Sotrudnik::define_old() {
    Date date;
    date = this->passport.get_birthday();

    time_t currentTime;
    struct tm* localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    // d,m,y - current time
    int d = localTime->tm_mday;
    int m = localTime->tm_mon + 1;
    int y = localTime->tm_year + 1900;

    int age;
    if (gender == FEMALE) {
        age = 58;
    }
    else {
        age = 63;
    }

    if ((y - date.get_d()) > age) {
        this->is_old = 1;
        return;
    }

    if ((y - date.get_y()) == age) {
        if (date.get_m() < m) {
            this->is_old = 1;
            return ;
        }
        if (date.get_m() == m && date.get_d() <= d) {
            this->is_old = 1;
            return;
        }
    }
    this->is_old = 0;
    return;
}


std::ifstream& operator>>(std::ifstream& inf, Sotrudnik& Sotrudnik) {
    std::string tmp;
    
    // имя
    inf >> Sotrudnik.name;

    // пол
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    for (int i = 0; i < tmp.size();i++) {
        tmp[i] = tolower(tmp[i]);
    }
    if (tmp == "female") {
        Gender gender = FEMALE;
        Sotrudnik.gender = gender;
    }
    else {
        Gender gender = MALE;
        Sotrudnik.gender = gender;
    }

    // пасспорт
    inf >> Sotrudnik.passport;

    // образование
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    Sotrudnik.obrazov = tmp;

    // специальность
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    Sotrudnik.specialnost = tmp;

    // подразделение
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    Sotrudnik.podrazd = tmp;

    // должность
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    Sotrudnik.dolznost = tmp;

    // оклад
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    Sotrudnik.oklad = stoi(tmp);

    // поступление
    inf >> Sotrudnik.postuplenie;

    // назначение
    inf >> Sotrudnik.naznachenie;

    // is old ?
    Sotrudnik.define_old();

    return inf;

}

