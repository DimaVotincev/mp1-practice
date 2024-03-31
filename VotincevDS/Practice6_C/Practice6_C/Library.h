#pragma once
#include "Sotrudnik.h"

typedef struct {
    int n;
    Sotrudnik* sotr;
} SLibr;


void alloc_lib(SLibr* sl, int n);
void get_libdata(char* filename, Sotrudnik* s);

