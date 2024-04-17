#pragma once
#include "stdio.h"

typedef struct {
    char* str;
    int d;
    int m;
    int y;

} Date;

void alloc_date(Date* date);
void make_good_date(Date* date);
int date_is_correct(Date* date);
int is_old(Date* date,enum Gender gender);
show_dates(Date* naznach, Date* postup);
//int is_date(char* str);
