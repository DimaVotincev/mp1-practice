#include <iostream>
#include <fstream>
#include "Name.h"
#include "general.h"


Name::Name() {
    this->fullname = "";
    this->F = "";
    this->I = "";
    this->O = "";
}

Name::Name(const Name& n) {
    this->fullname = n.fullname;
    this->F = n.F;
    this->I = n.I;
    this->O = n.O;
}

Name& Name::operator=(const Name& name) {
    this->fullname = name.fullname;
    this->F = name.F;
    this->I = name.I;
    this->O = name.O;
    return *this;
}


std::ifstream& operator>>(std::ifstream& inf, Name& name) {
    std::string tmp;
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    name.fullname = tmp;
    name.make_good_name();
    return inf;
}

std::ostream& operator<<(std::ostream& out, Name& name) {
    out << "Фамилия: "
        << name.get_F() << '\n';
    out << "Имя: "
        << name.get_I() << '\n';
    out << "Отчество: "
        << name.get_O() << '\n';
    return out;
}

void Name::make_good_name() {
    std::string tmp;
    for (char el : this->fullname) {
        if (el != ' ') {
            tmp += el;
            continue;
        }
        if (this->F.empty()) {
            this->F = tmp;
            tmp.clear();
            continue;
        }
        if (this->I.empty()) {
            this->I = tmp;
            tmp.clear();
            continue;
        }
    }
    if (this->I.empty()) {
        this->I = tmp;
        tmp.clear();
    }

    if (tmp == "") {
        this->O = "-";
        return;
    }
    this->O = tmp;
}