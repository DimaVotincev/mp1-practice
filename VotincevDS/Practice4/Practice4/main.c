#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define n 13


// using data
char codes[n][5];
char* names[n] = { "Banana","Crisps","Chicken","Garlic",
    "Garlic Bread","Vine","Snickers","Coconuts","Milk",
    "Cheese","Ferrero Rocher","Kinder","Rice(500g)" };
double prices[n] = { 12,67,320,5,34,3238,56,16,245,143,1199,62,136 };
double discounts[n];
int check[n];



void make_codes();
// ������ �����-����

void make_discounts();
// ������ ������

void print_product(int i);
// ������� ���������� � ��������

void ask_and_add(int i);
// ���������� ������������
// � ������� ������� ������� � ���

void check_code(char* code);
// ��������� �����-���
// �� ������������� � data

void print_fmsg(int snd, int s);
// ������� ��������� ���������

void fill_check();
// ��������� ���




int main() {
    int i;
    system("chcp 1251");

    make_codes();
    // ����� �����-����
    
    make_discounts();
    // ������ ������

    
    // ��������� � ������ ������ ���������
    printf("-------------------\n");
    printf("������� ��� ��������\n");
    


    // ���� ������ ���������
    while (1) {
        char code[5];
        char ans[10];
        
        i = 0;

        // �������� �����-���
        scanf("%s", &code); 
        
        // ����������� �����-���
        check_code(&code);      
        
        printf("����� ��� ��������� ������? ��/���\n");
        
        scanf("%10s", &ans);
        if (strcmp(ans, "���") == 0) {
            printf("\n\t\t��� ���:\n\n");                           
            fill_check();
            return 0;
        }
        
        printf("������� ��� ���������� ������\n");    
        
    }

    return 0;
}


void make_codes() {
    int i = 0;
    for (i = 0; i < n; i++) {
        sprintf(codes[i], "%04d", i + 1);
        // ��������������� ����� i+1 � ������
        // � �������� %04d (������ ������ � 4 �������)
        // ���� ����� ������ 4 ��������,
        // �� ������� ��������� ����� ������ �������
        // �� ����� � 4 �������

        // ������� ���������� �� ������ ������,
        // �� � ������ \0 (����� ������)
        // ������� ������� � 5 ���������,� �� 4
    }
}


void make_discounts() {
    int i;
    srand((unsigned int)time(0)); // �������� ������
    for (i = 0; i < n;i++) {
        discounts[i] = ((1 + (rand() % 50)) * 0.01);
    }
}

void print_product(int i) {
    printf("%s - %.0lf ���/�� - %.0lf%% ������ \n",
        names[i], prices[i], discounts[i] * 100);
}


void ask_and_add(int i) {
    char ans[10];
    printf("�������� � ���? ��/���\n");
    scanf("%10s", &ans);
    char* ptr = strstr(ans, "��");
    if (ptr != NULL) {
        int skoka;
        printf("������� ��������?\n");
        scanf("%d", &skoka);
        check[i] += skoka;
        printf("��������� %d ����\n", skoka);
    }
}

void check_code(char* code) {
    int i = 0;

    for (; i < n;i++) {
        if (strcmp(codes[i], code) == 0) {
            print_product(i);
            ask_and_add(i);
            return;
        }
    }

    if ((i == n) && strcmp(codes[n - 1], code) != 0) {
        printf("��� ����� ����� ����� �����������\n");
    }

}



void print_fmsg(double snd, double s) {
    printf("\n����� � ������: %.0lf ���\n", snd);
    printf("� ������ ������ (%.2lf%%): %.0lf ���\n",
        (1.0 - (s * 1.0 / snd)) * 100, s);
    printf("\t��������� � ��� ��� ! <3 \n");
    printf("\n\n-------------------");
}

void fill_check() {
    int snd = 0; // summa no discount
    int s = 0; // summa with discount
    int i = 0;
    for (;i < n; i++) {
        if (check[i] != 0) {

            printf("%s - %.0lf ���/�� - %d ���� - %.0lf ����� ��������� \n",
                names[i], prices[i], check[i],
                prices[i] * check[i] * (1.0 - discounts[i]));

            snd += prices[i] * check[i];
            s += prices[i] * check[i] * (1.0 - discounts[i]);

        }
       
    }
    print_fmsg(snd, s); // ������� ��������� ���������
}