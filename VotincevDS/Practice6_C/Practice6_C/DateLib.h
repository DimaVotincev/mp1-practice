#pragma once
#include "Date.h"

typedef struct {
    int n;
    Date* dates;
} DateLib;

void alloc_datelib(DateLib* datelib, int n);