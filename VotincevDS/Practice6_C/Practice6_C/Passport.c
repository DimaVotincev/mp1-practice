#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Passport.h"





//void get_passport(char* filename, Sotrudnik* s) {
//    FILE* f = fopen(filename, "r");
//    if (f == NULL) {
//        abort();
//    }
//    char* str1 = (char*)malloc(200);
//
//    alloc_pass(&s->passport);
//    alloc_other(&s);
//    // ��������� �����
//    fscanf(f, "%s", str1);
//    fscanf(f, "%s", str1);
//    s->passport.seria = atoi(str1);
//
//    // ��������� ������
//    fscanf(f, "%s", str1);
//    fscanf(f, "%s", str1);
//    s->passport.nomer = atoi(str1);
//
//    // ��������� ��� ����� ��������
//    fscanf(f, "%s", str1);
//    fgets(str1, 200, f);
//    s->passport.kem = _strdup(str1);
//    make_good_str(s->passport.kem, 200);
//
//    // ��������� ����� ����� ��������
//    fscanf(f, "%s", str1);
//    fgets(str1, 200, f);
//    s->passport.kogda.str = _strdup(str1);
//    make_good_str(s->passport.kogda.str, 200);
//    make_good_date(&s->passport.kogda);
//
//    // ��������� ��� ��������
//    fscanf(f, "%s", str1);
//    fgets(str1, 200, f);
//    s->passport.birthday.str = _strdup(str1);
//    make_good_str(s->passport.birthday.str, 200);
//    make_good_date(&s->passport.birthday);
//
//    // ��������� ��������
//    fscanf(f, "%s", str1);
//
//    s->passport.propiska = _strdup(str1);
//    make_good_str(s->passport.propiska, 200);
//
//    //// ��������� ������ �����������
//    //fscanf(f, "%s", str1);
//    //fgets(str1, 200, f);
//    //s->obrazov = _strdup(str1);
//    //make_good_str(s->obrazov, 200);
//
//    //// ��������� ������ �������������
//    //fscanf(f, "%s", str1);
//    //fgets(str1, 200, f);
//    //s->specialnost = _strdup(str1);
//    //make_good_str(s->specialnost, 200);
//
//    //// ��������� ������ �������������
//    //fscanf(f, "%s", str1);
//    //fgets(str1, 200, f);
//    //s->podrazd = _strdup(str1);
//    //make_good_str(s->podrazd, 200);
//
//    //// ��������� ������ ���������
//    //fscanf(f, "%s", str1);
//    //fgets(str1, 200, f);
//    //s->dolznost = _strdup(str1);
//    //make_good_str(s->dolznost, 200);
//
//    //// ��������� ������ ������
//    //fscanf(f, "%s", str1);
//    //fscanf(f, "%s", str1);
//    //s->oklad = atoi(str1);
//
//}