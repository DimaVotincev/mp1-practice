#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"
#include "Sotrudnik.h"






void make_good_str(char* input,int n) {
    
    int i;
    char el;
    int k = 0;  // количество нужных символов

    for (i = 0; i < n;i++) {
        el = input[i];
        if (('a' <= el && el <= 'z') || ('A' <= el && el <= 'Z')
            || ('0' <= el && el <= '9') || el == '.' || el == '/') {
            
            k++;
            continue;
        }
        if (el == ' ' && input[i-1] != ' ' && i >1) {
            
            k++;
            continue;
        }
        if (el == '\0' || el == EOF || el == '\n') {
            k++;
            break;
        }
    }  
    char* output = (char*)malloc(sizeof(char)*(k)); 
    k = 0; 
    for (i = 0; i < n;i++) {
        el = input[i];
        if (('a' <= el && el <= 'z') || ('A' <= el && el <= 'Z') 
            || ('0' <= el && el <= '9') || el == '.' || el == '/') {
            output[k] = el;
            k++;
            continue;
        }
        if (el == ' ' && input[i - 1] != ' ' && i > 1) {
            output[k] = el;
            k++;
            continue;
        }
        if (el == '\0' || el == EOF || el == '\n') {           
            break;
        }
    }   
    output[k] = '\0';
    realloc(input, k);
    memcpy(input,output,k);
    free(output);
}








