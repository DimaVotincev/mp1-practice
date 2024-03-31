#pragma once

#include "Date.h"


typedef struct {
    int seria;
    int nomer;
    char* kem;
    Date kogda;
    Date birthday;
    char* propiska;

} Passport;


//void get_passport(char* filename, Sotrudnik* s);