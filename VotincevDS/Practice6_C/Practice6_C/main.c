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
        printf("\t� ���� ������ �������� ���������� ");
        printf("� %d �����������:\n", sl.n);
        for (i = 0; i < sl.n;i++) {
            printf("%d: %s \n", i+1, sl.sotr[i].name);
        }
        printf("\t� ����� ���������� ���������� ����������?\n");
        printf("���� ����� ������ ����������� ����������� ��������\n");
        printf("������� 0 \n");
        printf("(������� -1 ��� ���������� ���������)\n");
        scanf("%d", &k);
        
        if (k == -1) {
            return 0;
        }

        // ���������� � �����������
        if (k > 0 && k <= sl.n) {
            k--; // �� ������ �� 1 ������
            sotrudnik = &sl.sotr[k];

            printf("\t\t����� ���������� �����?\n");
            printf("1: ������� \n");
            printf("2: ����� ���������� \n");
            printf("3: ���� ���������� � �����������\n");
            printf("4: ��� ����������\n");
            scanf("%*c%d", &k);  
            printf("\n\n");
            get_sotrudnik(sotrudnik, k);
            printf("\n\n\n");
            continue;

        }

        // ���������� � ����������� ����������� ��������
        if (k == 0) {
            printf("���������� ����������� ��������:\n", slold.n);
            for (i = 0; i < slold.n;i++) {
                printf("%d: %s \n", i + 1, slold.sotr[i].name);
            }
            printf("� ����� ���������� ���������� ����������?\n");
            scanf("%*c%d", &k);
            if (k > 0 && k <= slold.n) {
                k--; // �� ������ �� 1 ������
                sotrudnik = &slold.sotr[k];

                printf("\t����� ���������� �����?\n");
                printf("1: ������� \n");
                printf("2: ����� ���������� \n");
                printf("3: ���� ���������� � �����������\n");
                printf("4: ��� ����������\n");

                scanf("%*c%d", &k);
                get_sotrudnik(sotrudnik, k);

            }
        }       
        printf("\n\n\n");
    }  
    return 0;
}

