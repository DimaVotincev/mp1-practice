#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sotrudnik.h"
#include "general.h"
#include "Date.h"
#include "Library.h"

void alloc_lib(SLibr* sl,int n) {
    sl->n = n;
    sl->sotr = (Sotrudnik*)malloc(n*sizeof(Sotrudnik));
}


void get_libdata(char* filename, SLibr* sl) {
    int i;
    int n = 150;
    char* str1 = (char*)malloc(n);
    int razm;
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        abort();
    }
    
    fscanf(f, "%s", str1);
    fscanf(f, "%s", str1);
    razm = atoi(str1);
    alloc_lib(sl,razm);
    for (i = 0; i < sl->n;i++) {
        Sotrudnik* s = &sl->sotr[i];

        // получение имени
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->name = _strdup(str1);
        make_good_str(s->name, n);

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

        if (is_old(&s->passport.birthday)) {
            s->is_old = "yes";
        }
        else {
            s->is_old = "no";
        }





        // пока скипаю даты поступления
        fgets(str1, n, f);
        fgets(str1, n, f);
        fgets(str1, n, f);
    }
    
    
    

    // получение кем выдан пасспорт
    /*fscanf(f, "%s", str1);
    fgets(str1, n, f);
    sl->sotr->passport.kem = _strdup(str1);
    make_good_str(sl->sotr->passport.kem, n);*/

    

}



//void get_sotrudnik(char* filename, Sotrudnik* s) {
//    FILE* f = fopen(filename, "r");
//    if (f == NULL) {
//        abort();
//    }
//    char* str1 = (char*)malloc(200);
//
//    get_data(filename, s);
//
//    if (is_old(&s->passport.birthday)) {
//        s->is_old = "yes";
//    }
//    else {
//        s->is_old = "no";
//    }
//
//
//}

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