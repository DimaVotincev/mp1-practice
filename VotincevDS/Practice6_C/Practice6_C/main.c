#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include "Sotrudnik.h"
#include "general.h"
#include "Library.h"



int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");

    char filename[] = "test.txt";
    FILE* f2 = fopen(filename, "r");
    /*Sotrudnik s1;
    get_sotrudnik(filename, &s1);
    get_sotrudnik(filename, &s1);
    printf(" ");*/

    SLibr sl;
    get_libdata(filename,&sl);



    return 0;
}


