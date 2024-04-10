#pragma once
#include "Passport.h"
#include "Date.h"
#include "Name.h"

typedef enum
{
    MALE = 0,
    FEMALE = 1
} Gender;

typedef struct {
    Name name;
    char* gender; // Gender gender;
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

