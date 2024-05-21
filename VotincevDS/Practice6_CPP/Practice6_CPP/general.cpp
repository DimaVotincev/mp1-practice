#include "general.h"

void make_good_str(std::string& str) {
    std::string res;
    int flag = 0;

    while (str.back() == ' ') {
        str.pop_back();
    }

    for (char el : str) {
        
        if (('a' <= el && el <= 'z') || ('A' <= el && el <= 'Z')
            || ('0' <= el && el <= '9') || el == '.' || el == '/') {
            res += el;
            flag = 1;
            continue;
        }
        if (el == ' ' && flag) {
            res += el;
            flag = 0;
            continue;
        }
        if (el == '\0' || el == EOF || el == '\n') {
            res += el;
            break;
        }
    }
    str = res;  
}