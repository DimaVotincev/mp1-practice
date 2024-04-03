#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sotrudnik.h"
#include "general.h"
#include "Date.h"
#include "DateLib.h"


void free_sotr(Sotrudnik s) {
    
    free_pass(s.passport);
    free(s.name);
    free(s.obrazov);
    free(s.specialnost);
    free(s.podrazd);
    free(s.dolznost);
    free_date(s.postuplenie);
    free_date(s.naznachenie);
    
}

void show_other(Sotrudnik* s) {
    printf("�����������: %s\n", s->obrazov);
    printf("�������������: %s\n", s->specialnost);
    printf("�������������: %s\n", s->podrazd);
    printf("���������: %s\n", s->dolznost);
    printf("�����: %d ���\n", s->oklad);
    printf("���������: %s\n", s->is_old);
}


void get_sotrudnik(Sotrudnik* s,int k) {
    switch (k)
    {

    case 0:
        show_pass(&s->passport);
        break;
    case 1:
        show_other(s);
        break;
    case 2:
        show_dates(&s->naznachenie,&s->postuplenie);
        break;

    case 3:
        show_pass(&s->passport);
        show_other(s);
        show_dates(&s->naznachenie, &s->postuplenie);
        break;
    default:
        break;
    }
    return;
}
