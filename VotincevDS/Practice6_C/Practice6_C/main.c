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
        printf("�������� ���-�� ���������� ��������� ������");
        return -1;
    }
    
    
    int k;
    SLibr sl;
    SLibr slold;
    Sotrudnik* sotrudnik;
    fill_libdata(filename,&sl,size);
    
    fill_oldlibdata(&sl,&slold);

    while (1) {
        // ������� ���������� �����������        
        show_slibr(&sl,0);
        // 2-� ��������:       
        // 1 - ����� ��� ���������� �����������
        // 0 - ����� ��� ���������� ���� �����������

        printf("\t� ����� ���������� ���������� ����������?\n");
        printf("���� ����� ������ ����������� ����������� �������� ");
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

            // ���������� � ������� 
            // ���������� �� �������
            // � ����������
            show_sotr(sotrudnik,k);   

            printf("------------------------\n");
            continue;
        }

        // ���������� � ����������� ����������� ��������
        if (k == 0) {
            show_slibr(&slold, 1);
            printf("� ����� ���������� ���������� ����������?\n");
            scanf("%*c%d", &k);
            if (k > 0 && k <= slold.n) {
                k--; // �� ������ �� 1 ������
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

