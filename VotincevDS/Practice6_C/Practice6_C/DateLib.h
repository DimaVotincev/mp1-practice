#pragma once
#include "Date.h"

typedef struct {
    int n;
    Date* dates;
} DateLib;

void alloc_datelib(DateLib* datelib, int n);
void realloc_datelib(DateLib* datelib, int n);
show_dates(DateLib* naznach, DateLib* postup);
