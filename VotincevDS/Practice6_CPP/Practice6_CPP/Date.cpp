#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "Date.h"
#include "general.h"

Date::Date() {
    this->str = "";
    this->d = 0;
    this->m = 0;
    this->y = 0;
}

Date::Date(const std::string& str) {
    Date date;
    date.set_str(str); 
    date.make_good_date();
    *this = date;
}

Date::Date(const Date& d) {
    this->str = d.str;
    this->d = d.d;
    this->m = d.m;
    this->y = d.y;
}

void Date::set_str(std::string& str) {
    this->str = str;
}

void Date::set_str(const std::string& str) {
    this->str = str;
}

std::string& Date::get_str() {
    return this->str;
}

void Date::set_d(int _d) {
    if (_d >= 1 && _d <= 32 || _d == 0) {
        this->d = d;
        return;
    }
    
    throw "wrong day";
}

void Date::set_m(int _m) {
    if (_m <= 12 && _m >= 1 || _m == 0) {
        this->m = _m;
        return;
    }
    throw "wrong month";
    
}

void Date::set_y(int _y)  {
    int age;
    time_t currentTime;
    struct tm* localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    // d,m,y - current time
    int y = localTime->tm_year + 1900;

    if (_y >= 1900 && _y <= y || _y == 0) {
        this->y = _y;
        return;
    }
    
    throw "wrong month";
}

const Date& Date::operator=(const Date& date) {
    this->set_str(date.str);
    this->set_d(date.d);
    this->set_m(date.m);
    this->set_y(date.y);
    return *this;
}

std::ifstream& operator>>(std::ifstream& inf, Date& date) {
    inf >> date.str; 
    getline(inf,date.str);
    make_good_str(date.str);
    date.make_good_date();
    return inf;
}

void Date::make_good_date() {
    std::string tmp;
    for (char el : this->str) {
        if (el != '.' && el != '/') {
            tmp += el;
        }
        else {
            if (this->d == 0) {
                this->d = stoi(tmp);
                tmp.clear();
                continue;
            }

            if (this->m == 0) {
                this->m = stoi(tmp);
                tmp.clear();
                continue;
            }
        }

    }
    this->y = stoi(tmp);
    if (this->date_is_correct() == 0) {
        std::cout << "Polsovatel vruska\n";
        std::cout << "Wrong date\n";
        abort();
    }
}




int Date::date_is_correct() {
    int day = this->d;
    int month = this->m;
    int year = this->y;
    if (day < 1 || day > 32 ||
        month < 1 || month > 12) {
        return 0;
    }

    if (year % 400 == 0 ||
        ((year % 4 == 0) && (year % 100 != 0))) {
        if (month == 2 && day > 30) {
            return 0;
        }
    }

    if (month == 1 || month == 3
        || month == 5 || month == 7
        || month == 8 || month == 10
        || month == 12) {
        if (day > 31) {
            return 0;
        }
    }

    if (month == 2 || month == 4
        || month == 6 || month == 9
        || month == 11) {
        if (day > 30) {
            return 0;
        }
    }
    return 1;
}

