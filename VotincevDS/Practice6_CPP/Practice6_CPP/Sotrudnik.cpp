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
    
}

Sotrudnik::Sotrudnik(const Sotrudnik& sotr) {
    this->name = sotr.name;
    this->gender = sotr.gender;
    this->passport = sotr.passport;
    this->obrazov = sotr.obrazov;
    this->specialnost = sotr.specialnost;
    this->podrazd = sotr.podrazd;
    this->dolznost = sotr.dolznost;
    this->oklad = sotr.oklad;
    this->postuplenie = sotr.postuplenie;
    this->naznachenie = sotr.naznachenie;  
}

int Sotrudnik::is_old() const {
    int age;
    time_t currentTime;
    struct tm* localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    // d,m,y - current time
    int d = localTime->tm_mday;
    int m = localTime->tm_mon + 1;
    int y = localTime->tm_year + 1900;


    if (gender == Gender::FEMALE) {
        age = 58;
    }
    else {
        age = 63;
    }
    
    if ((y - this->passport.get_birthday().get_y()) > age) {
        return 1;
    }

    if ((y - this->passport.get_birthday().get_y()) == age) {
        if (this->passport.get_birthday().get_m() < m) {
            return 1;
        }
        if (this->passport.get_birthday().get_m() == m && 
            this->passport.get_birthday().get_d() <= d) {
            return 1;
        }
    }
    return 0;
}



void Sotrudnik::print_generalinfo() {
    std::cout << "Образование: " << this->obrazov << '\n';
    std::cout << "Специальность: " << this->specialnost << '\n';    
    std::cout << "Подразделение: " << this->podrazd << '\n';
    std::cout << "Должность: " << this->dolznost << '\n';
    std::cout << "Оклад: " << this->oklad << '\n';
    if (this->is_old()) {
        std::cout << "Пенсионер: " << "да" << '\n';
        return;
    }
    std::cout << "Пенсионер: " << "нет" << '\n';
}

void Sotrudnik::print_dates() {
    std::cout << "Дата поступления: " << 
        this->postuplenie << "\n";
    std::cout << "Дата назначения: " <<
        this->naznachenie << "\n";
}



std::ostream& operator<<(std::ostream& out, Sotrudnik& sotr) {
    int k;
    std::cout << "\tКакая информация нужна о сотруднике?\n"
        << "1 - паспортные данные\n"
        << "2 - общую информацию\n"
        << "3 - даты поступления и назначения\n"
        << "4 - всю информацию\n";
    std::cin >> k;

    std::cout << "\tСотрудник\n";
    out << sotr.get_name(); 
    switch (k)
    {
    case 1:
        out << sotr.get_pass();

        break;
    case 2:
        sotr.print_generalinfo();
        break;
    case 3:
        sotr.print_dates();
        break;
    case 4:

        out << sotr.get_pass();
        sotr.print_generalinfo();
        sotr.print_dates();
        break;
    default:
        break;
    }
    return out;
}

const Sotrudnik& Sotrudnik::operator=(const Sotrudnik& sotr) {
    this->name = sotr.name;
    this->gender = sotr.gender;
    this->passport = sotr.passport;
    this->obrazov = sotr.obrazov;
    this->specialnost = sotr.specialnost;
    this->podrazd = sotr.podrazd;
    this->dolznost = sotr.dolznost;
    this->oklad = sotr.oklad;
    this->postuplenie = sotr.postuplenie;
    this->naznachenie = sotr.naznachenie;
    return *this;
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

    return inf;

}



//         SAVED FUNCTIONS 
//        (old functions)


//void print_sotr();

//void Sotrudnik::print_sotr() {
//    int k;
//    std::cout << "Какая информация нужна о сотруднике?\n"
//        << "1 - паспортные данные\n"
//        << "2 - общую информацию\n"
//        << "3 - даты поступления и назначения\n"
//        << "4 - всю информацию\n";
//    std::cin >> k;
//
//    std::cout << "\tСотрудник\n";
//    std::cout << "Фамилия: "
//        << this->get_name().get_F() << '\n';
//    std::cout << "Имя: "
//        << this->get_name().get_I() << '\n';
//    std::cout << "Отчество: "
//        << this->get_name().get_O() << '\n';
//    switch (k)
//    {
//    case 1:
//        this->get_pass().print_pass();
//        
//        break;
//    case 2:
//        this->print_generalinfo();
//        break;
//    case 3:
//        this->print_dates();
//        break;
//    case 4:
//        
//        this->get_pass().print_pass();
//        this->print_generalinfo();
//        this->print_dates();
//        break;
//    default:
//        break;
//    }
//}