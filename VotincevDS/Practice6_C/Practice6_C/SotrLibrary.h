#pragma once
#include "Sotrudnik.h"

typedef struct {
    int n;
    Sotrudnik* sotr;
} SLibr;

typedef struct {
    int n;
    Sotrudnik* sotr;
} OldSLibr;

void free_lib(SLibr* sl);
void realloc_lib(SLibr* sl, int n);
void alloc_lib(SLibr* sl, int n);
void fill_libdata(char* filename, SLibr* s);
void fill_oldlibdata(SLibr* s, SLibr* olds);
// функция которая создает библиотеку
// пенсионеров