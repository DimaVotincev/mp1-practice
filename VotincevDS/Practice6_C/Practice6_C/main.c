#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include "Sotrudnik.h"
#include "general.h"
#include "SotrLibrary.h"



int main(int argc, char** argv) {
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");
    int size ;
    char* filename; 
    if (argc == 3) {
        size = atoi(argv[1]);
        filename = argv[2]; 
    }
    else {
        printf("Ќеверное кол-во аргументов командной строки");
        return -1;
    }
    
    
    int k;
    SLibr sl;
    SLibr slold;
    Sotrudnik* sotrudnik;
    fill_libdata(filename,&sl,size);
    
    fill_oldlibdata(&sl,&slold);

    while (1) {
        // выводит библиотеку сотрудников        
        show_slibr(&sl,0);
        // 2-й параметр:       
        // 1 - вывод дл€ библиотеки пенсионеров
        // 0 - вывод дл€ библиотеки всех сотрудников

        printf("\tќ каком сотруднике необходима информаци€?\n");
        printf("≈сли нужен список сотрудников пенсионного возраста ");
        printf("введите 0 \n");
        printf("(введите -1 дл€ завершени€ программы)\n");
        scanf("%d", &k);

        if (k == -1) {
            return 0;
        }

        // информаци€ о сотрудниках
        if (k > 0 && k <= sl.n) {
            k--; // тк индекс на 1 меньше
            sotrudnik = &sl.sotr[k];

            // спрашивает и выводит 
            // информацию на консоль
            // о сотруднике
            show_sotr(sotrudnik,k);   

            printf("------------------------\n");
            continue;
        }

        // информаци€ о сотрудниках пенсионного возраста
        if (k == 0) {
            show_slibr(&slold, 1);
            printf("ќ каком сотруднике необходима информаци€?\n");
            scanf("%*c%d", &k);
            if (k > 0 && k <= slold.n) {
                k--; // тк индекс на 1 меньше
                sotrudnik = &slold.sotr[k];

                show_sotr(sotrudnik,k);

            }
        }
        printf("------------------------\n");
    }
    free(slold.sotr);
    free(sotrudnik);
    return 0;
}

