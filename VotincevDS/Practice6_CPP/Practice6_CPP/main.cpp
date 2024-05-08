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
        std::cout << "�������� ���-�� ���������� ��������� ������\n";
        return -1;
    }
    infs.open(filename);
    int size = atoi(argv[1]);
    SotrLibr sl(size);
    
    infs >> sl;

    SotrLibr slold(sl, 1);
    // ������ �������� 1 
    // ��������,��� ����� �������� �� sl
    // ����������� ����������� ��������
       
    
    while (1) {
        std::cin.clear();
        int k;
        std::cout << "\t� ���� �������� ���������� � "
            << sl.get_size() << " �����������:\n";

        

        // ����� ����
        for (int i = 0; i < sl.get_size();i++) {
                    
            std::cout << i + 1 << ": " << 
                sl.get_sotr()[i].get_name().get_fullname() << '\n';
        }

        std::cout << "\t� ����� ���������� ���������� "
            << "����������?\n���� ����� ������ "
            << "����������� ����������� �������� ������� 0\n"
            << "(��� ���������� ��������� ������� -1)\n";
        std::cin >> k;
        
        if (1 <= k && k <= sl.get_size()) {
            k--;
            
            
            // ����������� ��� ������ ����������
            // � ������� �� �������
            std::cout << sl.get_sotr()[k];
            
            continue;
        }

        if (k == 0) {
            std::cout << "\t� ���� �������� ���������� � "
                << sl.get_size() << " �����������-�����������:\n";
            for (int i = 0; i < slold.get_size();i++) {

                std::cout << i + 1 << ": " <<
                    slold.get_sotr()[i].get_name().get_fullname() << '\n';
            }


            std::cout << "\t� ����� ���������� ���������� "
                << "����������?\n���� ����� ������ "
                << "����������� ����������� �������� ������� 0\n"
                << "(��� ���������� ��������� ������� -1)\n";
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