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




int main(int argc, char** argv) {
    system("chcp 1251");
    std::ifstream infs;
    std::string filename;
    if (argc == 3) {
        filename = argv[2];
        
    }
    else {
        std::cout << "Неверное кол-во аргументов командной строки\n";
        return -1;
    }
    infs.open(filename);
    int size = atoi(argv[1]);
    SotrLibr sl(size);
    
    infs >> sl;

    SotrLibr slold(sl, 1);
    // второй параметр 1 
    // означает,что нужно отобрать из sl
    // сотрудников пенсионного возраста
       
    
    while (1) {
        std::cin.clear();
        int k;
        std::cout << "\tВ базе хранится информация о "
            << sl.get_size() << " сотрудниках:\n";

        

        // вывод имен
        for (int i = 0; i < sl.get_size();i++) {
                    
            std::cout << i + 1 << ": " << 
                sl.get_sotr()[i].get_name().get_fullname() << '\n';
        }

        std::cout << "\tО каком сотруднике необходима "
            << "информация?\nЕсли нужен список "
            << "сотрудников пенсионного возраста введите 0\n"
            << "(для завершения программы введите -1)\n";
        std::cin >> k;
        
        if (1 <= k && k <= sl.get_size()) {
            k--;
            
            
            // запрашивает тип нужной информации
            // и выводит на консоль
            std::cout << sl.get_sotr()[k];
            
            continue;
        }

        if (k == 0) {
            std::cout << "\tВ базе хранится информация о "
                << sl.get_size() << " сотрудниках-пенсионерах:\n";
            for (int i = 0; i < slold.get_size();i++) {

                std::cout << i + 1 << ": " <<
                    slold.get_sotr()[i].get_name().get_fullname() << '\n';
            }


            std::cout << "\tО каком сотруднике необходима "
                << "информация?\nЕсли нужен список "
                << "сотрудников пенсионного возраста введите 0\n"
                << "(для завершения программы введите -1)\n";
            std::cin >> k;
            
            if (1 <= k && k <= slold.get_size()) {
                k--;
                std::cout << slold.get_sotr()[k];
            }
            
            
        }

        if (k == -1) {
            return 0;
        }        
        
    }
    
   
    return 0;
}