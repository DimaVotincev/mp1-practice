#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sotrudnik.h"
#include "general.h"
#include "Date.h"
#include "SotrLibrary.h"

void alloc_lib(SLibr* sl,int n) {
    sl->n = n;
    sl->sotr = (Sotrudnik*)malloc(n*sizeof(Sotrudnik));
}


void fill_libdata(char* filename, SLibr* sl) {
    int i;
    int n = 150;
    char* str1 = (char*)malloc(n);
    int razm;
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        abort();
    }
    
    // считываю кол-во сотрудников
    fscanf(f, "%s", str1);
    fscanf(f, "%s", str1);
    razm = atoi(str1);
    alloc_lib(sl,razm);
    for (i = 0; i < sl->n;i++) {
        int date_count = 0; 
        // понадобится для дат поступления(назначения)

        Sotrudnik* s = &sl->sotr[i];
        alloc_datelib(&s->postuplenie, 10);
        alloc_datelib(&s->naznachenie,10);
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
        make_good_date(&s->passport.kogda);

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

       
        // получение дат поступления
        fscanf(f, "%s", str1);
        fscanf(f, "%s", str1);
        while (is_date(str1)) {
            if (s->postuplenie.n < date_count) {
                realloc_datelib(&s->postuplenie, date_count*2);
            }
            s->postuplenie.dates[date_count].str = _strdup(str1);
            make_good_date(&s->postuplenie.dates[date_count].str);
            date_count++;
            fscanf(f, "%s", str1);
        }
        realloc_datelib(&s->postuplenie, date_count);
        date_count = 0; // для дат назначения
        
        
        // получение дат назначения
        fscanf(f, "%s", str1);
        while (is_date(str1)) {
            if (s->naznachenie.n < date_count) {
                realloc_datelib(&s->naznachenie, date_count*2);
            }
            s->naznachenie.dates[date_count].str = _strdup(str1);
            make_good_date(&s->naznachenie.dates[date_count].str);
            date_count++;
            
            fscanf(f, "%s", str1);
        }
        realloc_datelib(&s->naznachenie, date_count);
        // проверка на возвраст
        // (пенсионер или нет)
        if (is_old(&s->passport.birthday)) {
            s->is_old = "yes";
        }
        else {
            s->is_old = "no";
        }
    }
    
}
