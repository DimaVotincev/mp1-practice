#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include "Gender.h"

class Date {
private:
    std::string str;
    int d;
    int m;
    int y;
public:
    Date();
    Date(const std::string&);
    Date(const Date&);

    void set_str(const std::string& str);
    void set_str(std::string& str);
    std::string& get_str();
    int get_d() { return this->d; };
    int get_m() { return this->m; };
    int get_y() { return this->y; };

    void set_d(int _d) { this->d = _d; };
    void set_m(int _m) { this->m = _m; };
    void set_y(int _y) { this->y = _y; };


    int date_is_correct();
    int is_old(Gender&);
    void make_good_date();
    //void show_dates(Date& naznach, Date& postup);
    Date& operator=(const Date& date);
    friend std::ostream& operator<<(std::ostream& out, Date& date) 
    {
        out << date.str;
        return out;
    };
    friend std::ifstream& operator>>(std::ifstream& inf, Date& date);
};