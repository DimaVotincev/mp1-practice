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
        std::cout << "�������� ���-�� ���������� ��������� ������\n";
        return -1;
    }
    std::ifstream infs;
    infs.open(filename);

    int size = atoi(argv[1]);
    SotrLibr sl(size);
    
    infs >> sl;
    // ���������� � �����
    
    SotrLibr slold(sl, 1);
    // ������ �������� 1 
    // ��������,��� ����� �������� �� sl
    // ����������� ����������� ��������
       
    // TODO: split
    while (1) { 
        std::cin.clear();
        int k;
        std::cout << "\t� ���� �������� ���������� � "
            << sl.get_size() << " �����������:\n";

        print_names(sl);
        // ����� ����

        std::cout << "\t� ����� ���������� ���������� "
            <<                            "����������?\n" 
            << "\t���� ����� ������ ����������� "
            << "����������� �������� ������� 0\n"
            << "\t(��� ���������� ��������� ������� -1)\n";
        std::cin >> k;
        
        // ����������� � ������� 
        // ������ ���������� � ����������
        if (ask_print_sotr(k, sl, slold) == 0) {
            return 0;
        }
        // ���� ��� ������ �� ���������� ���������
        //�� ���������� 0              
    }  
    return 0;
}