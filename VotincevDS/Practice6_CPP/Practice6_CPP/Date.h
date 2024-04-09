#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>

class Date {
public:
    std::string str;
    int d;
    int m;
    int y;

    Date();
    Date(std::string);
    Date(Date&);
    
    int date_is_correct();
    void make_good_date();
    //void show_dates(Date& naznach, Date& postup);
    friend std::ostream& operator<<(std::ostream& out, Date& date);
};