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
int prices[n] = { 12,67,320,5,34,3238,56,16,245,143,1199,62,136 };
double discounts[n];
int check[n];



// using functions
int same(char* a, char* b);
// ���������� ������

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
        i = 0;

        // �������� �����-���
        char code[5];
        scanf("%s", &code); 
        
        // ����������� �����-���
        check_code(&code);
        
        
        
        printf("����� ��� ��������� ������? ��/���\n");
        char ans[10];
        scanf("%10s", &ans);
        if (same(ans, "���")) {
            printf("\n\t\t��� ���:\n\n");

                           
            fill_check();

            return 0;
        }
        
        printf("������� ��� ���������� ������\n");
        
    }

}




// ������������� �������
int same(char* a, char* b) {
    int i = 0;
    int flag = 1;
    int len = strlen(a);
    for (; i < 4; i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
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
    printf("%s - %d ���/�� - %.0lf%% ������ \n",
        names[i], prices[i], discounts[i] * 100);
}


void ask_and_add(int i) {
    printf("�������� � ���? ��/���\n");
    char ans[10];
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
        int same_codes = same(codes[i], code);
        if (same_codes) {

            print_product(i);

            ask_and_add(i);
            return;
        }
    }

    if ((i == n) && !same(codes[n - 1], code)) {
        printf("��� ����� ����� ����� �����������\n");
    }

}



void print_fmsg(int snd, int s) {
    printf("\n����� � ������: %d ���\n", snd);
    printf("� ������ ������ (%.2lf%%): %d ���\n",
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

            printf("%s - %d ���/�� - %d ���� - %.0lf ����� ��������� \n",
                names[i], prices[i], check[i],
                prices[i] * check[i] * (1.0 - discounts[i]));

            snd += prices[i] * check[i];
            s += prices[i] * check[i] * (1.0 - discounts[i]);

        }
       
    }
    print_fmsg(snd, s); // ������� ��������� ���������
}