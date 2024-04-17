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


void show_pass(Passport* pass);
