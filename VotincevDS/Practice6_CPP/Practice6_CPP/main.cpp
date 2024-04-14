#include <iostream>
#include <fstream>
#include <string>
#include "general.h"
#include "Date.h"
#include "Passport.h"
#include "Name.h"
#include "Sotrudnik.h"


#include <cctype>
using namespace std;

void f1(ifstream& infs,string& str1) {
    getline(infs, str1);
}

void f2(ifstream& infs,string& str1) {
    getline(infs, str1);
}

int main() {
    ifstream infs;

    infs.open("test.txt");

    string str1;
    getline(infs, str1);
    
    Sotrudnik sotr;

    infs >> sotr;
    /*f1(infs,str1);
    cout << str1 << '\n';
    f2(infs, str1);
    cout << str1 << '\n';*/






    //for (int i = 0; i < 10; i++) {
    //    infs >> str1;
    //    cout << str1 << '_';
    //    
    //    getline(infs, str1);
    //    make_good_str(str1);
    //    //int k = stoi(str1);
    //    cout << str1 << '_' << '\n';
    //}

    
    return 0;
}