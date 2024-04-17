#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "general.h"

void make_good_str(char* input,int n) {
    char* output;
    int i;
    char el;
    int k = 0;  // ���������� ������ ��������

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

    // ����� ����� k = ����� - 1
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
        printf("���������� ����������� ��������:\n", sl->n);
        for (i = 0; i < sl->n;i++) {
            printf("%d: %s \n", i + 1, sl->sotr[i].name.fullname);
        }
        return 0;
    }
    printf("\t� ���� ������ �������� ���������� ");
    printf("� %d �����������:\n", sl->n);
    for (i = 0; i < sl->n;i++) {
        printf("%d: %s \n", i + 1, sl->sotr[i].name.fullname);
    }

}

void ask_info() {
    // ����������, ����� ����������
    // ����� � ������������

    printf("\t\t����� ���������� �����?\n");
    printf("1: ������� \n");
    printf("2: ����� ���������� \n");
    printf("3: ���� ���������� � �����������\n");
    printf("4: ��� ����������\n");
}

void show_sotr(Sotrudnik* sotr, int k) {
    ask_info();
    scanf("%*c%d", &k);
    get_sotrudnik(sotr, k);
}