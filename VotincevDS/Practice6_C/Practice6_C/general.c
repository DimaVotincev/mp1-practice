#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "general.h"

void make_good_str(char* input,int n) {
    char* output;
    int i;
    char el;
    int k = 0;  // количество нужных символов

    for (i = 0; i < n;i++) {
        el = input[i];
        if (('a' <= el && el <= 'z') || ('A' <= el && el <= 'Z')
            || ('0' <= el && el <= '9') || el == '.' || el == '/') {
            
            k++;
            continue;
        }
        if (el == ' ' && input[i-1] != ' ' && i >1) {
            
            k++;
            continue;
        }
        if (el == '\0' || el == EOF || el == '\n') {           
            k++; 
            break;
        }
    }  

    output = (char*)malloc(k*sizeof(char)); 
    k = 0; 
    for (i = 0; i < n;i++) {
        el = input[i];
        if (('a' <= el && el <= 'z') || ('A' <= el && el <= 'Z') 
            || ('0' <= el && el <= '9') || el == '.' || el == '/') {
            output[k] = el;
            k++;
            continue;
        }
        if (el == ' ' && input[i - 1] != ' ' && i > 1) {
            output[k] = el;
            k++;
            continue;
        }
        if (el == '\0' || el == EOF || el == '\n') {   
           
            break;
        }
    }   

    // после цикла k = длина - 1
    output[k] = '\0';
    k++; 
    for (i = 0; i < k;i++) {
        input[i] = output[i];
    }

    free(output);
}


void show_slibr(SLibr* sl, int k) {
    int i = 0;
    if (k) {
        printf("Сотрудники пенсионного возраста:\n", sl->n);
        for (i = 0; i < sl->n;i++) {
            printf("%d: %s \n", i + 1, sl->sotr[i].name.fullname);
        }
        return 0;
    }
    printf("\tВ базе данных хранится информация ");
    printf("о %d сотрудниках:\n", sl->n);
    for (i = 0; i < sl->n;i++) {
        printf("%d: %s \n", i + 1, sl->sotr[i].name.fullname);
    }

}

void ask_info() {
    // спрашивает, какая информация
    // нужна о пользователе

    printf("\t\tКакая информация нужна?\n");
    printf("1: паспорт \n");
    printf("2: общая информация \n");
    printf("3: даты назначения и поступления\n");
    printf("4: всю информацию\n");
}

void show_sotr(Sotrudnik* sotr, int k) {
    ask_info();
    scanf("%*c%d", &k);
    get_sotrudnik(sotr, k);
}