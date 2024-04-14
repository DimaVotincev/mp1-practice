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

    
    void set_str(std::string& str);
    std::string& get_str();
    int get_d();
    int get_m();
    int get_y();

    int date_is_correct();
    int is_old(Gender&);
    void make_good_date();
    //void show_dates(Date& naznach, Date& postup);
    friend void operator=(Date& date);
    friend std::ifstream& operator>>(std::ifstream& inf, Date& date);
};