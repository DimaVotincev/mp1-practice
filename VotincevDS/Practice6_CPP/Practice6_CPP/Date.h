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
    Date(std::string, int,int,int);
    Date(Date&);
    
    void show_date();
    friend std::ostream& operator<<(std::ostream& out, Date& date);
};