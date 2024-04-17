#pragma once
#include "Passport.h"
#include "Date.h"
#include "Name.h"
#include "Gender.h"


typedef struct {
    Name name;
    Gender gender;
    Passport passport;
    char* obrazov;
    char* specialnost;
    char* podrazd;
    char* dolznost;
    int oklad;
    Date postuplenie;
    Date naznachenie;
    int is_old;
} Sotrudnik;

void sotr_cpy(Sotrudnik* sl, Sotrudnik* olds);
void show_other(Sotrudnik* s);
void get_sotrudnik(Sotrudnik* s, int k);

