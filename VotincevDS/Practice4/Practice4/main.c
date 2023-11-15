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
    char codes[n][5]; // матрица с n строками
    // и 5 столбцами
    system("chcp 1251");
    char* names[n] = { "Banana","Crisps","Chicken","Garlic",
    "Garlic Bread","Vine","Snickers","Coconuts","Milk",
    "Cheese","Ferrero Rocher","Kinder","Rice(500g)" };
    int prices[n] = { 12,67,320,5,34,3238,56,16,245,143,1199,62,136 };
    double discounts[n];

    for (i = 0; i < n; i++) {
        sprintf(codes[i], "%04d", i + 1);
        // преобразовывает число i+1 в строку
        // с форматом %04d (строку длиной в 4 символа)
        // если число меньше 4 символов,
        // то функция дополняет число нулями спереди
        // до длины в 4 символа

        // функция возвращает не только строку,
        // но и символ \0 (конец строки)
        // поэтому матрица с 5 столбцами,а не 4
    }

    // проверка 
    //for (i = 0; i < n;i++)
    //    printf("%s\n", codes[i]);

    srand((unsigned int)time(0)); // создание скидок
    for (i = 0; i < n;i++) {
        discounts[i] = ((1 + (rand() % 50)) * 0.01);
    }
    
    printf("-------------------\n");
    printf("Введите код продукта\n");
    
    while (1) {
        char code[5];
        i = 0;
        scanf("%s", &code);

        for (; i < n;i++) {
            int same_codes = same(codes[i], code);
            if (same_codes) {

                printf("%s - %d руб/шт - %.0lf%% скидка \n",
                    names[i], prices[i], discounts[i] * 100);

                printf("Добавить в чек? да/нет\n");
                char ans[10];
                scanf("%10s", &ans);
                char* ptr = strstr(ans, "да");
                if (ptr != NULL) {
                    int skoka;
                    printf("Сколько добавить?\n");
                    scanf("%d", &skoka);
                    check[i] += skoka;
                    printf("Добавлено %d штук\n", skoka);
                }
                break;
            }
        }

        if ((i == n) && !same(codes[n - 1], code)) {
            printf("Под таким кодом товар отсутствует\n");
        }
        
        printf("Будем ещё добавлять товары? да/нет\n");
        char ans[10];
        scanf("%10s", &ans);
        if (same(ans, "нет")) {
            printf("\n\t\tВаш чек:\n\n");

            // заполнение чека 
            // и подсчёт общей суммы к оплате
            int snd = 0; // summa no discount
            int s = 0; // summa with discount
            for (i = 0; i < n;i++) {
                if (check[i] != 0) {

                    printf("%s - %d руб/шт - %d штук - %.0lf общая стоимость \n",
                        names[i], prices[i], check[i], prices[i] * check[i] * (1.0 - discounts[i]));

                    snd += prices[i] * check[i];
                    s += prices[i] * check[i] * (1.0 - discounts[i]);

                }
            }

            printf("\nВсего к оплате: %d руб\n", snd);
            printf("С учетом скидки (%.2lf%%): %d руб\n", ( 1.0 - (s * 1.0 / snd)) * 100, s);
            printf("\tПриходите к нам ещё ! <3 \n");
            printf("\n\n-------------------");
            return 0;
        }
        
        printf("Введите код очередного товара\n");
        
    }

}