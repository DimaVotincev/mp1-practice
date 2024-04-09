#include "Name.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void make_good_name(Name* name) {
    // i - индекс по name
    // j - индекс по str
    int i = 0, j = 0; 
    char* str = (char*)malloc(30);
    char el = name->fullname[i];
    while (el != '\0' && el != ' ' && el != '\n' && el != EOF) {
        str[j] = el;
        i++;
        j++;
        el = name->fullname[i];
    }
    str[j] = '\0';
    i++;
    j = 0;

    name->F = _strdup(str);

    free(str);
    str = (char*)malloc(30);

    el = name->fullname[i];
    while (el != '\0' && el != ' ' && el != '\n' && el != EOF) {
        str[j] = el;
        i++;
        j++;
        el = name->fullname[i];
    }
    str[j] = '\0';
    i++;
    j = 0;
    name->I = _strdup(str);

    free(str);
    str = (char*)malloc(30);

    el = name->fullname[i];
    while (el != '\0' && el != ' ' && el != '\n' && el != EOF) {
        str[j] = el;
        i++;
        j++;
        el = name->fullname[i];
    }
    if (j == 0) {
        str[j] = ' ';
        j++;
    }
    str[j] = '\0';
    name->O = _strdup(str);
    free(str);
}