#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sotrudnik.h"
#include "general.h"
#include "Date.h"

void alloc_data(Sotrudnik* s) {

    s->passport.kem = (char*)malloc(100);
    s->passport.propiska = (char*)malloc(50);
    s->passport.birthday.str = (char*)malloc(12);
    s->passport.kogda.str = (char*)malloc(12);
    s->passport.birthday.str = (char*)malloc(12);

    s->obrazov = (char*)malloc(sizeof(char) * 50);
    s->specialnost = (char*)malloc(sizeof(char) * 50);
    s->podrazd = (char*)malloc(sizeof(char) * 50);
    s->dolznost = (char*)malloc(sizeof(char) * 50);
}


void get_data(char* filename, Sotrudnik* s) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        abort();
    }
    int n = 150;
    char* str1 = (char*)malloc(n);


    //alloc_data(s);

    //get_passport(filename,&s->passport);
    
    // получение серии
    fscanf(f, "%s", str1);
    fscanf(f, "%s", str1);
    s->passport.seria = atoi(str1);

    // получение номера
    fscanf(f, "%s", str1);
    fscanf(f, "%s", str1);
    s->passport.nomer = atoi(str1);

    // получение кем выдан пасспорт
    fscanf(f, "%s", str1);
    fgets(str1, n, f);
    s->passport.kem = _strdup(str1);    
    make_good_str(s->passport.kem, n);

    // получение когда выдан пасспорт
    fscanf(f, "%s", str1);
    fgets(str1, n, f);
    s->passport.kogda.str = _strdup(str1);
    make_good_str(s->passport.kogda.str, n);
    make_good_date(&s->passport.kogda.str);

    // получение дня рождения
    fscanf(f, "%s", str1);
    fgets(str1, n, f);
    s->passport.birthday.str = _strdup(str1);
    make_good_str(s->passport.birthday.str, n);
    make_good_date(&s->passport.birthday);

    // получение прописки
    fscanf(f, "%s", str1);
    fgets(str1, n, f);
    s->passport.propiska = _strdup(str1);
    make_good_str(s->passport.propiska, n);

    // получение данных образования
    fscanf(f, "%s", str1);
    fgets(str1, n, f);
    s->obrazov = _strdup(str1);
    make_good_str(s->obrazov, n);

    // получение данных специальности
    fscanf(f, "%s", str1);
    fgets(str1, n, f);
    s->specialnost = _strdup(str1);
    make_good_str(s->specialnost, n);

    // получение данных подразделения
    fscanf(f, "%s", str1);
    fgets(str1, n, f);
    s->podrazd = _strdup(str1);
    make_good_str(s->podrazd, n);

    // получение данных должности
    fscanf(f, "%s", str1);
    fgets(str1, n, f);
    s->dolznost = _strdup(str1);
    make_good_str(s->dolznost, n);

    // получение данных оклада
    fscanf(f, "%s", str1);
    fscanf(f, "%s", str1);
    s->oklad = atoi(str1);
    
}



void get_sotrudnik(char* filename, Sotrudnik* s) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        abort();
    }
    char* str1 = (char*)malloc(200);
      
    get_data(filename,s);

    if (is_old(&s->passport.birthday)) {
        s->is_old = "yes";
    }
    else {
        s->is_old = "no";
    }

    
}

/*
Seria: 1234   +
Nomer: 567890    +
Kem_vidan: MVD Moscow Raiona  +
When_vidan: 14.01.001   +
Birthday: 01/03/1996   +
Mesto_propiski: Karpov Street + 
Obrazovanie: Srednee obshee
Specialnost: Programni ingener
Podrazdelenie: otdel inzenerow
Dolznost: glavnui inziner
Oklad: 100000
Dates_postpuplenii_v_firmu:  14.03.2000 01.05.2000 14.05.2000
Dates_last_assignment: 11.02.2001 10.01.2001 11.03.2001


*/