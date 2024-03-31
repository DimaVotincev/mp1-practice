#include <stdlib.h>
#include <string.h>
#include "DateLib.h"
#include "Date.h"

void alloc_datelib(DateLib* datelib, int n) {
    datelib->n = n;
    datelib->dates = (Date*)malloc(n * sizeof(Date));
}

void realloc_datelib(DateLib* datelib, int n) {
    DateLib tmp;
    tmp.dates = (Date*)malloc(n * sizeof(Date));
    tmp.n = n;
    int i;
    for (i = 0; i < n;i++) {
        tmp.dates[i].str = datelib->dates[i].str;
        tmp.dates[i].d = datelib->dates[i].d;
        tmp.dates[i].m = datelib->dates[i].m;
        tmp.dates[i].y = datelib->dates[i].y;
    }
    
    for (i = 0; i < n;i++) {
        datelib->dates[i].str = _strdup(tmp.dates[i].str);
        datelib->dates[i].d = tmp.dates[i].d;
        datelib->dates[i].m = tmp.dates[i].m;
        datelib->dates[i].y = tmp.dates[i].y;

    }
    datelib->n = tmp.n;
}


show_dates(DateLib* naznach , DateLib* postup) {
    int i;
    printf("Даты назначения: ");
    for (i = 0; i < naznach->n;i++) {
        printf("%s ", naznach->dates[i].str);
    }   
    printf("\nДаты поступления: ");
    for (i = 0; i < postup->n;i++) {
        printf("%s ", postup->dates[i].str);
    }
}
