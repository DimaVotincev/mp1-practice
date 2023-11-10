#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void cr_number(int *digits,int n,int *d) {
    int i = 0,digit;
    digit = 1 + rand() % 9;
    for (i; i < n; i++) {
        
        while (d[digit] == 0) {
            digit = rand() % 10;
        }
        *digits += digit;
        *digits *= 10;
        d[digit]--;

    }
    *digits /= 10;
}

void cr_number_mas(int number,int n,int *sm) {
    int i;
    for (i = (n - 1); i >= 0; i--) {
        sm[i] = (number)% 10;
        (number) /= 10;
    }
}

//void get_n(int *n) {
//    do {
//        scanf("%d", &n);
//    } while (n < 2 || n>5);
//}


int main() {
    int attempts = 0; // ���-�� �������
    int n;
    int digits = 0; // ����� ������� ��������� ����������
    int d[10] = { 1,1,1,1,1,1,1,1,1,1 }; 
    // ������ � ���������� ������� (������ == �����)
    // �������� ��������� �.�. ������ ����� ����� ���. 1 ���
    int cows = 0, bulls = 0;
    int cb = 0; // cows & bulls
    int suggest = 0; // ������������� ������
    int dm[5]; // ������ �����
    int sm[5]; // ������ ������������� ������
    
    printf("Welcome! This is 'Cow and Bull' game!\n");
    printf("Lets start with amout of bulls you'll guess\n Type it\n");
    printf("(it must be 2,3,4, or 5, no more!)\n");
    
    do {
        scanf("%d", &n);
    } while (n < 2 || n>5);

    printf("Good! Now lets play\n");
    srand((unsigned int)time(0));

    
    cr_number(&digits, n, &d);
    
    
    
    // create number     function call
    

    // create massive of 'digits'     function call
    cr_number_mas(digits, n, &dm);
    // 1) ���� �����  
    // 2) n - ����� ����� 
    // 3) dm - ������, ������� ����������� ������� �����
    

    printf("Type number with %d  different digits\n", n);
    
    while (bulls != n) {
        scanf("%d", &suggest);
        int i, j;
        int bc = 0; // bulls & cows
        cows = 0, bulls = 0;

        // create massive of 'suggest'    function call
        cr_number_mas(suggest, n, &sm);
        
        for (i = 0; i < n;i++) {
            for (j = 0; j < n;j++) {
                if (dm[i] == sm[j]) {
                    bc++;

                }
            }
        }
        for (i = 0; i < n;i++) {
            if (dm[i] == sm[i]) {
                bulls++;
            }
        }
        
        cows = bc - bulls;
        // ������ ���-�� ����������� ���� 
        // ������� ���-�� �����  � ������� ���-�� �����
        // gg

        printf("cows    _%d_\n", cows);
        printf("bulls   _%d_\n", bulls);
        attempts++;
    }
    printf("Good game!\n");
    printf("You did it for only %d attempts!\n",attempts);
    return 0;
}
/*
����������� ����� ����������� ���� ����-������
�������
1) ������ 2 ������ 1 ��� 1 ����
2) ����� �������� ����� n ����������� ����� �� 2 �� 5
3) �� ���������� n ������� ����� � ���������������� �������
4) ����� ������ ������� �������� ����� - ������ n ������� �����
� ���������������� �������
5) �� �������� ������� ���� ������� ��� ���������� � �� ��������� � �����
( ��� ���-�� �����) � ������� ������� ������ �� ������� � ���������� ����� (��� ���-�� �����)
123
524   -  1 ��� 0 �����
251  -  0 �����  2 ������
6) ����� ������ ������� , ���� �� �������� ��� ������������������
n = 4
3219

2310
2 ������ 1 ���
(2 � 3 - ������ , 1 - ���)

*/