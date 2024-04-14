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

std::ifstream& operator>>(std::ifstream& inf, Name& name) {
    std::string tmp;
    inf >> tmp;
    getline(inf, tmp);
    make_good_str(tmp);
    name.fullname = tmp;
    name.make_good_name();
    return inf;
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