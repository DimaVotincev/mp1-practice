#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include "Sotrudnik.h"
#include "general.h"
#include "SotrLibrary.h"



int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");
    char filename[] = "test.txt"; 
    int i,k;
    SLibr sl;
    Sotrudnik* sotrudnik;
    fill_libdata(filename,&sl);

    while (1) {
        printf("\t\tВ базе данных хранится информация ");
        printf("о %d сотрудниках:\n", sl.n);
        for (i = 0; i < sl.n;i++) {
            printf("%d: %s \n", i+1, sl.sotr[i].name);
        }
        printf("\t\tО каком сотруднике необходима информация?\n");
        printf("(введите -1 для завершения)\n");
        scanf("%d", &k);

        if (k == -1) {
            return 0;
        }

        if (k > 0 && k <= sl.n) {
            k--; // тк индекс на 1 меньше
            sotrudnik = &sl.sotr[k];

            printf("\t\tКакая информация нужна?\n");
            printf("1: паспорт \n");
            printf("2: общая информация \n");
            printf("3: даты назначения и поступления\n");
            printf("4: всю информацию\n");
            scanf("%d", &k);
            k--;
            get_sotrudnik(sotrudnik, k);

        }
        printf("\n\n\n\n\n");
    }  
    return 0;
}

