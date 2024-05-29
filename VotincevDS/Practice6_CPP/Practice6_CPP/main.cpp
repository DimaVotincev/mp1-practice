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
    std::string filename;
    
    if (argc == 3) {
        filename = argv[2];       
    }
    else {
        std::cout << "Неверное кол-во аргументов командной строки\n";
        return -1;
    }
    std::ifstream infs;
    infs.open(filename);

    int size = atoi(argv[1]);
    SotrLibr sl(size);
    
    infs >> sl;
    // заполнение с файла
    
    SotrLibr slold(sl, 1);
    // второй параметр 1 
    // означает,что нужно отобрать из sl
    // сотрудников пенсионного возраста
       
    // TODO: split
    while (1) { 
        std::cin.clear();
        int k;
        std::cout << "\tВ базе хранится информация о "
            << sl.get_size() << " сотрудниках:\n";

        print_names(sl);
        // вывод имен

        std::cout << "\tО каком сотруднике необходима "
            <<                            "информация?\n" 
            << "\tЕсли нужен список сотрудников "
            << "пенсионного возраста введите 0\n"
            << "\t(для завершения программы введите -1)\n";
        std::cin >> k;
        
        // запрашивает и выводит 
        // нужную информацию о сотруднике
        if (ask_print_sotr(k, sl, slold) == 0) {
            return 0;
        }
        // если был запрос на завершение программы
        //то возвращает 0              
    }  
    return 0;
}