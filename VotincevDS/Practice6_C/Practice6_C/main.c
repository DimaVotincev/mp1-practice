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
        // выводит библиотеку сотрудников        
        show_slibr(&sl,0);
        // 2-й параметр:       
        // 1 - библиотека пенсионеров
        // 0 - библиотека всех сотрудников

        printf("\tО каком сотруднике необходима информация?\n");
        printf("Если нужен список сотрудников пенсионного возраста ");
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

            // спрашивает и показывает информацию
            // о сотруднике
            show_sotr(sotrudnik,k);   

            printf("------------------------\n");
            continue;
        }

        // информация о сотрудниках пенсионного возраста
        if (k == 0) {
            show_slibr(&slold, 1);
            printf("О каком сотруднике необходима информация?\n");
            scanf("%*c%d", &k);
            if (k > 0 && k <= slold.n) {
                k--; // тк индекс на 1 меньше
                sotrudnik = &slold.sotr[k];

                show_sotr(sotrudnik,k);

            }
        }
        printf("------------------------\n");
    }

    return 0;
}

