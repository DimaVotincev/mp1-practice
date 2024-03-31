#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Sotrudnik.h"
#include "general.h"
#include <malloc.h>

void mkstr(char* str) {
    str = _strdup("Abc");
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");
    
    char filename[] = "test.txt";
    FILE* f2 = fopen(filename, "r");
    Sotrudnik s1;

    get_sotrudnik(filename,&s1);
    
    get_sotrudnik(filename, &s1);
    printf(" ");
    /*char* str1 = (char*)malloc(10);
    int i;
    
    char* str2 = (char*)malloc(10);
    for (i = 0; i < 5;i++) {
        str2[i] = 'a';
    }
    str2[5] = '\0';
    
    
    str1 = _strdup(str2);*/
    
    /*char str1[2];
    str1[0] = '1';
    str1[1] = '2';*/
    //printf("%d", s1.passport.birthday.y);
    // check_old(0);
    
    

    return 0;
}


