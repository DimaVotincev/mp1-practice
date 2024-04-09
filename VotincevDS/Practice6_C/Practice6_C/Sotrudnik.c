#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sotrudnik.h"
#include "general.h"
#include "Date.h"



void show_other(Sotrudnik* s) {
    printf("Образование: %s\n", s->obrazov);
    printf("Специальность: %s\n", s->specialnost);
    printf("Подразделение: %s\n", s->podrazd);
    printf("Должность: %s\n", s->dolznost);
    printf("Оклад: %d руб\n", s->oklad);
    if (s->is_old == 1) {
        printf("Пенсионер: да\n");
    }
    else {
        printf("Пенсионер: нет\n");
    }
    
}


void get_sotrudnik(Sotrudnik* s,int k) {
    printf("\t\tСотрудник \n");
    printf("Фамилия: %s \n", s->name.F);
    printf("Имя: %s \n",s->name.I);
    if (s->name.O[0] != ' ') {
        printf("Отчество: %s \n",s->name.O);
    }
    else {
        printf("Отчество: - \n");
    }
    
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
    sl2->name.fullname = _strdup(sl1->name.fullname);
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