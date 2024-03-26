#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Sotrudnik.h"


int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");
    
    char filename[] = "test.txt";
    FILE* f2 = fopen(filename, "r");
    Sotrudnik s1;

    get_sotrudnik(filename,&s1);
    
    
    
    /*char str1[2];
    str1[0] = '1';
    str1[1] = '2';*/
    //printf("%d", s1.passport.birthday.y);
    // check_old(0);
    
    

    return 0;
}


