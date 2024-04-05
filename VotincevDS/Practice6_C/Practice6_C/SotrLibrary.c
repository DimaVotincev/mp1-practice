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

//void free_lib(SLibr *sl) {
//    int i = 0;
//    for (; i < sl->n; i++) {
//        free_sotr(sl->sotr[i]);
//    }
//    
//}

//void realloc_lib(SLibr* sl, int n) {
//    SLibr s;
//    s.n = n;
//    s.sotr = (Sotrudnik*)malloc(n * sizeof(Sotrudnik));
//    sl->n = n;
//    for (int i = 0; i < n; i++) {
//        memcpy(&s.sotr[i],&sl->sotr[i],sizeof(Sotrudnik));
//        
//    }
//
//    free_lib(sl); // ����������� � s ����
//    // ������� ���� ����� s1 ���������
//    // ����������� � _strdup() �� �������� GG
//    sl->sotr = (Sotrudnik*)malloc(n * sizeof(Sotrudnik));
//    for (int i = 0; i < n; i++) {
//        sl->sotr[i] = s.sotr[i];
//    }
//}


void fill_libdata(char* filename, SLibr* sl) {
    int i;
    const int n = 150;
    char* str1 = (char*)malloc(n);
    int razm;
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        abort();
    }
    
    // �������� ���-�� �����������
    fscanf(f, "%s", str1);
    fscanf(f, "%s", str1);
    razm = atoi(str1);
    alloc_lib(sl,razm);
    for (i = 0; i < sl->n;i++) {
        int date_count = 0; 
        // ����������� ��� ��� �����������(����������)

        Sotrudnik* s = &sl->sotr[i];
        alloc_datelib(&s->postuplenie, 10);
        alloc_datelib(&s->naznachenie,10);
        // ��������� �����
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->name = _strdup(str1);
        make_good_str(s->name, n);

        // ��������� �����
        fscanf(f, "%s", str1);
        fscanf(f, "%s", str1);
        s->passport.seria = atoi(str1);

        // ��������� ������
        fscanf(f, "%s", str1);
        fscanf(f, "%s", str1);
        s->passport.nomer = atoi(str1);


        // ��������� ��� ����� ��������
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->passport.kem = _strdup(str1);
        make_good_str(s->passport.kem, n);

        // ��������� ����� ����� ��������
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->passport.kogda.str = _strdup(str1);
        make_good_str(s->passport.kogda.str, n);
        make_good_date(&s->passport.kogda);

        // ��������� ��� ��������
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->passport.birthday.str = _strdup(str1);
        make_good_str(s->passport.birthday.str, n);
        make_good_date(&s->passport.birthday);

        // ��������� ��������
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->passport.propiska = _strdup(str1);
        make_good_str(s->passport.propiska, n);

        // ��������� ������ �����������
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->obrazov = _strdup(str1);
        make_good_str(s->obrazov, n);

        // ��������� ������ �������������
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->specialnost = _strdup(str1);
        make_good_str(s->specialnost, n);

        // ��������� ������ �������������
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->podrazd = _strdup(str1);
        make_good_str(s->podrazd, n);

        // ��������� ������ ���������
        fscanf(f, "%s", str1);
        fgets(str1, n, f);
        s->dolznost = _strdup(str1);
        make_good_str(s->dolznost, n);

        // ��������� ������ ������
        fscanf(f, "%s", str1);
        fscanf(f, "%s", str1);
        s->oklad = atoi(str1);

       
        // ��������� ��� �����������
        fscanf(f, "%s", str1);
        fscanf(f, "%s", str1);
        s->postuplenie.str = _strdup(str1);       
        make_good_str(s->postuplenie.str, n);
        make_good_date(&s->postuplenie.str);
        
        // ��������� ��� ����������
        fscanf(f, "%s", str1);
        fscanf(f, "%s", str1);
        
        s->naznachenie.str = _strdup(str1);
        make_good_str(s->naznachenie.str, n);
        make_good_date(&s->naznachenie.str);

        fscanf(f, "%s", str1);
        // �������� �� ��������
        // (��������� ��� ���)
        if (is_old(&s->passport.birthday)) {
            s->is_old = 1;
        }
        else {
            s->is_old = 0;
        }
    }
    
}

void fill_oldlibdata(const SLibr* sl, SLibr* oldsl) {
    int sotr_count = 0;
    int k = 0;
    int i = 0;
    for (; i < sl->n; i++) {
        if (sl->sotr[i].is_old == 1) {

            sotr_count++;
        }
    }

    alloc_lib(oldsl, sotr_count);
    
    
    for (i = 0; i < sl->n; i++) {
        if (sl->sotr[i].is_old == 1) {

            sotr_cpy(&sl->sotr[i], &oldsl->sotr[k]);


            k++;
            if (k == sotr_count) {
                break;
            }
        }
    }
}









