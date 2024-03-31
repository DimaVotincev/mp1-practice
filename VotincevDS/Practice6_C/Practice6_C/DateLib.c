#include <stdlib.h>
#include "DateLib.h"

void alloc_datelib(DateLib* datelib, int n) {
    datelib->n = n;
    datelib->dates = (Date*)malloc(n * sizeof(Date));
}