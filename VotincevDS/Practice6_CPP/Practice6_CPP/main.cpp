#include <iostream>
#include <fstream>
#include <string>
#include "general.h"
#include "Date.h"
#include "Passport.h"
#include "Name.h"
#include "Sotrudnik.h"
#include "SotrLibr.h"

#include <cctype>
using namespace std;



int main() {
    ifstream infs;

    infs.open("test.txt"); 
    
    SotrLibr sl;

    infs >> sl;

    // —делать вывод на консоль
    // библиотеки сотрудников
    //  (и соответсвующие операторы перегрузить)
    //


    /*int k = 0;
    while (k != -1) {
        std::cout << "¬ базе хранитс€ информаци€ о "
            << sl.get_size() << " сотрудниках:\n";
        for (int i = 1; i < sl.get_size() + 1;i++) {
            std::cout << i << ": " << sl.sot
        }

    }*/
    
    return 0;
}