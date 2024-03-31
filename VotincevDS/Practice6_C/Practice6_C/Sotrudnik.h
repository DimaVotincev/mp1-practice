#pragma once
#include "Passport.h"
#include "Date.h"

typedef struct {
    char* name;
    Passport passport;
    char* obrazov;
    char* specialnost;
    char* podrazd;
    char* dolznost;
    int oklad;
    struct Date* postuplenie;
    struct Date* naznachenie;
    char* is_old;
} Sotrudnik;


void alloc_data(Sotrudnik* s);
void get_sotrudnik(char* filename, Sotrudnik* s);
void get_data(char* filename, Sotrudnik* s);