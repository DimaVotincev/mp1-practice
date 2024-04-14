#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Date.h"
#include "Gender.h"


void alloc_date(Date* date) {
    date->str = (char*)malloc(sizeof(char)*10);
}


show_dates(Date* naznach, Date* postup) {
    printf("Дата назначения: %s \n", naznach->str);
    printf("Дата поступления: %s \n", postup->str);

}


void make_good_date(Date* date) {
    int i = 0, j = 0, k = 0;

    char tmp[5];
    // j - index for tmp
    // k:
    // k == 0  =>  date.d
    // k == 1  =>  date.m
    // k == 2  =>  date.y
    
    for (; i < 11; i++) {
        char el = date->str[i];
        
        if (el == '\0') {
            date->y = atoi(tmp);
            break;           
        }

        if ('0' <= el && el <= '9') {
            tmp[j] = el;
            j++;
        }

        if (el == '/' || el == '.') {
            if (k == 0) {
                date->d = atoi(tmp);
            }
            else if (k == 1) {
                date->m = atoi(tmp);
            }
            
            tmp[1] = '\0';
            k++;
            j = 0;
        }

    }  
    if (date_is_correct(date)) {
        return;
    }
    else {
        printf("Polsovatel vruska\n");
        printf("(wrong date)\n");
        abort();
    }
}

int date_is_correct(Date* date) {
    int day = date->d;
    int month = date->m;
    int year = date->y;
    if ( day < 1 || day > 32 ||
        month < 1 || month > 12) {
        return 0;
    }
   
    if (year % 400 == 0 ||
        ((year % 4 == 0) && (year % 100 != 0))) {
        if (month == 2 && day > 30) {
            return 0;
        }
    }
    
    if (month == 1 || month == 3
        || month == 5 || month == 7
        || month == 8 || month == 10
        || month == 12) {
        if (day > 31) {
            return 0;
        }
    }

    if (month == 2 || month == 4
        || month == 6 || month == 9
        || month == 11 ) {
        if (day > 30) {
            return 0;
        }
    }
    return 1;    
}


int is_old(Date* date, enum Gender gender) {
    int age;
    time_t currentTime;
    struct tm* localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    // d,m,y - current time
    int d = localTime->tm_mday;
    int m = localTime->tm_mon + 1;
    int y = localTime->tm_year + 1900;
    
    
    if (gender == FEMALE) {
        age = 58;
    }
    else {
        age = 63;
    }

    if ((y - date->y) > age) {
        return 1;
    }

    if ((y - date->y) == age) {
        if (date->m < m) {
            return 1;
        } 
        if (date->m == m && date->d <= d) {
            return 1;
        }
    }
    return 0;    
}



int is_date(char* str) {
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n' && str[i] != EOF) {
        if (str[i] == '.' || str[i] == '/') {
            return 1;
        }
        i++;
    }
    return 0;
}


