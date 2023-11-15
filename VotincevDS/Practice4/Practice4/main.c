#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define n 13

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





int main() {
    int i;
    int check[n] = { 0 };
    char codes[n][5]; // ������� � n ��������
    // � 5 ���������
    system("chcp 1251");
    char* names[n] = { "Banana","Crisps","Chicken","Garlic",
    "Garlic Bread","Vine","Snickers","Coconuts","Milk",
    "Cheese","Ferrero Rocher","Kinder","Rice(500g)" };
    int prices[n] = { 12,67,320,5,34,3238,56,16,245,143,1199,62,136 };
    double discounts[n];

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

    // �������� 
    //for (i = 0; i < n;i++)
    //    printf("%s\n", codes[i]);

    srand((unsigned int)time(0)); // �������� ������
    for (i = 0; i < n;i++) {
        discounts[i] = ((1 + (rand() % 50)) * 0.01);
    }
    
    printf("-------------------\n");
    printf("������� ��� ��������\n");
    
    while (1) {
        char code[5];
        i = 0;
        scanf("%s", &code);

        for (; i < n;i++) {
            int same_codes = same(codes[i], code);
            if (same_codes) {

                printf("%s - %d ���/�� - %.0lf%% ������ \n",
                    names[i], prices[i], discounts[i] * 100);

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
                break;
            }
        }

        if ((i == n) && !same(codes[n - 1], code)) {
            printf("��� ����� ����� ����� �����������\n");
        }
        
        printf("����� ��� ��������� ������? ��/���\n");
        char ans[10];
        scanf("%10s", &ans);
        if (same(ans, "���")) {
            printf("\n\t\t��� ���:\n\n");

            // ���������� ���� 
            // � ������� ����� ����� � ������
            int snd = 0; // summa no discount
            int s = 0; // summa with discount
            for (i = 0; i < n;i++) {
                if (check[i] != 0) {

                    printf("%s - %d ���/�� - %d ���� - %.0lf ����� ��������� \n",
                        names[i], prices[i], check[i], prices[i] * check[i] * (1.0 - discounts[i]));

                    snd += prices[i] * check[i];
                    s += prices[i] * check[i] * (1.0 - discounts[i]);

                }
            }

            printf("\n����� � ������: %d ���\n", snd);
            printf("� ������ ������ (%.2lf%%): %d ���\n", ( 1.0 - (s * 1.0 / snd)) * 100, s);
            printf("\t��������� � ��� ��� ! <3 \n");
            printf("\n\n-------------------");
            return 0;
        }
        
        printf("������� ��� ���������� ������\n");
        
    }

}