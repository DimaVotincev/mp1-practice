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

Date& Passport::get_birthday() {
    return this->birthday;
}

std::ifstream& operator>>(std::ifstream& inf, Passport& pass) {
    std::string tmp;

    // �����
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.seria = stoi(tmp);
    
    // �����
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.nomer = stoi(tmp);

    // ���
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.kem = tmp;

    // �����
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.kogda.set_str(tmp);
    pass.kogda.make_good_date();

    // ��
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.birthday.set_str(tmp);
    pass.birthday.make_good_date();

    // ��������
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    pass.propiska = tmp;


    //date.make_good_date();
    return inf;
}