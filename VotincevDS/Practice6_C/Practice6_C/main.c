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
    SLibr slold;
    Sotrudnik* sotrudnik;
    fill_libdata(filename,&sl);

    fill_oldlibdata(&sl,&slold);

    while (1) {
        printf("\tВ базе данных хранится информация ");
        printf("о %d сотрудниках:\n", sl.n);
        for (i = 0; i < sl.n;i++) {
            printf("%d: %s \n", i+1, sl.sotr[i].name);
        }
        printf("\tО каком сотруднике необходима информация?\n");
        printf("Если нужен список сотрудников пенсионного возраста\n");
        printf("введите 0 \n");
        printf("(введите -1 для завершения программы)\n");
        scanf("%d", &k);
        
        if (k == -1) {
            return 0;
        }

        // информация о сотрудниках
        if (k > 0 && k <= sl.n) {
            k--; // тк индекс на 1 меньше
            sotrudnik = &sl.sotr[k];

            printf("\t\tКакая информация нужна?\n");
            printf("1: паспорт \n");
            printf("2: общая информация \n");
            printf("3: даты назначения и поступления\n");
            printf("4: всю информацию\n");
            scanf("%*c%d", &k);  
            printf("\n\n");
            get_sotrudnik(sotrudnik, k);
            printf("\n\n\n");
            continue;

        }

        // информация о сотрудниках пенсионного возраста
        if (k == 0) {
            printf("Сотрудники пенсионного возраста:\n", slold.n);
            for (i = 0; i < slold.n;i++) {
                printf("%d: %s \n", i + 1, slold.sotr[i].name);
            }
            printf("О каком сотруднике необходима информация?\n");
            scanf("%*c%d", &k);
            if (k > 0 && k <= slold.n) {
                k--; // тк индекс на 1 меньше
                sotrudnik = &slold.sotr[k];

                printf("\tКакая информация нужна?\n");
                printf("1: паспорт \n");
                printf("2: общая информация \n");
                printf("3: даты назначения и поступления\n");
                printf("4: всю информацию\n");

                scanf("%*c%d", &k);
                get_sotrudnik(sotrudnik, k);

            }
        }       
        printf("\n\n\n");
    }  
    return 0;
}

