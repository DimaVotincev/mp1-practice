#pragma once

typedef struct {
    char* fullname;
    char* F;
    char* I;
    char* O;
} Name;

void make_good_name(Name* name);