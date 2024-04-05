#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sotrudnik.h"
#include "general.h"
#include "Date.h"
#include "DateLib.h"


//void free_sotr(Sotrudnik s) {
//    
//    free_pass(s.passport);
//    free(s.name);
//    free(s.obrazov);
//    free(s.specialnost);
//    free(s.podrazd);
//    free(s.dolznost);
//    free_date(s.postuplenie);
//    free_date(s.naznachenie);
//    
//}

void show_other(Sotrudnik* s) {
    printf("Образование: %s\n", s->obrazov);
    printf("Специальность: %s\n", s->specialnost);
    printf("Подразделение: %s\n", s->podrazd);
    printf("Должность: %s\n", s->dolznost);
    printf("Оклад: %d руб\n", s->oklad);
    if (is_old) {
        printf("Пенсионер: да\n");
    }
    else {
        printf("Пенсионер: нет\n");
    }
    
}


void get_sotrudnik(Sotrudnik* s,int k) {
    switch (k)
    {

    case 1:
        show_pass(&s->passport);
        break;
    case 2:
        show_other(s);
        break;
    case 3:
        show_dates(&s->naznachenie,&s->postuplenie);
        break;

    case 4:
        show_pass(&s->passport);
        show_other(s);
        show_dates(&s->naznachenie, &s->postuplenie);
        break;
    default:
        break;
    }
    return;
}


void sotr_cpy(Sotrudnik* sl1, Sotrudnik* sl2) {
    // из sl1 в sl2
    sl2->name = _strdup(sl1->name);
    sl2->passport.seria = sl1->passport.seria;
    sl2->passport.nomer = sl1->passport.nomer;
    sl2->passport.kem = _strdup(sl1->passport.kem);
    sl2->passport.kogda.str = _strdup(sl1->passport.kogda.str);
    make_good_date(&sl2->passport.kogda);
    sl2->passport.birthday.str = _strdup(sl1->passport.birthday.str);
    make_good_date(&sl2->passport.birthday);
    sl2->passport.propiska = _strdup(sl1->passport.propiska);

    sl2->obrazov = _strdup(sl1->obrazov);
    sl2->specialnost = _strdup(sl1->specialnost);
    sl2->podrazd = _strdup(sl1->podrazd);
    sl2->dolznost = _strdup(sl1->dolznost);
    sl2->oklad = sl1->oklad;
    sl2->postuplenie.str = _strdup(sl1->postuplenie.str);
    make_good_date(&sl2->postuplenie);
    sl2->naznachenie.str = _strdup(sl1->naznachenie.str);
    make_good_date(&sl2->naznachenie);
    sl2->is_old = sl1->is_old;
}
//char* name;
//Passport passport;
// 
// 
//char* obrazov;
//char* specialnost;
//char* podrazd;
//char* dolznost;
//int oklad;
//Date postuplenie; // Date !!
//Date naznachenie; // Date !!   
//int is_old;
//
//int seria;
//int nomer;
//char* kem;
//Date kogda;
//Date birthday;
//char* propiska;
//
//char* str;
//int d;
//int m;
//int y;