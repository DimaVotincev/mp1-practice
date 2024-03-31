#pragma once
#include "Passport.h"
#include "Date.h"
#include "DateLib.h"
typedef struct {
    char* name;
    Passport passport;
    char* obrazov;
    char* specialnost;
    char* podrazd;
    char* dolznost;
    int oklad;
    DateLib postuplenie;
    DateLib naznachenie;
    char* is_old;
} Sotrudnik;

void show_other(Sotrudnik* s);
void get_sotrudnik(Sotrudnik* s, int k);

