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



void Date::set_str(std::string& str) {
    this->str = str;
}

std::string& Date::get_str() {
    return this->str;
}

int Date::get_d() { return this->d; };
int Date::get_m() { return this->m; };
int Date::get_y() { return this->y; };


//Date& operator=(Date& date) {
//
//}

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

int Date::is_old(Gender& gender) {
    int age;
    time_t currentTime;
    struct tm* localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    // d,m,y - current time
    int d = localTime->tm_mday;
    int m = localTime->tm_mon + 1;
    int y = localTime->tm_year + 1900;


    if (gender == FEMALE) {
        age = 58;
    }
    else {
        age = 63;
    }

    if ((y - this->y) > age) {
        return 1;
    }

    if ((y - this->y) == age) {
        if (this->m < m) {
            return 1;
        }
        if (this->m == m && this->d <= d) {
            return 1;
        }
    }
    return 0;
}