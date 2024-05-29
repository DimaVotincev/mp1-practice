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


void print_names(SotrLibr& sl) {
    // ����� ����
    for (int i = 0; i < sl.get_size(); i++) {

        std::cout << i + 1 << ": " <<
            sl.get_sotr()[i].get_name().get_fullname() << '\n';
    }
    // �� ����������� �������� << ��� �����
    // �� �� ������� � ������������ �������� 
    // ( �������: ... \n ���: ... \n ��������:  ... \n)
}

int ask_print_sotr(int k, SotrLibr sl, SotrLibr slold) {
    if (1 <= k && k <= sl.get_size()) {
        k--; // ������ �� 1 ������

        // �������� ����������� ��� ������ ����������
        // � ������� �� �������
        std::cout << sl.get_sotr()[k];
        return 1;
    }

    if (k == 0) {
        std::cout << "\t� ���� �������� ���������� � "
            << slold.get_size() << " �����������-�����������:\n";

        print_names(slold);
        // ����� ���� �����������-�����������

        std::cout << "\t� ����� ���������� ���������� "
            << "����������?\n";

        std::cin >> k;

        if (1 <= k && k <= slold.get_size()) {
            k--;
            std::cout << slold.get_sotr()[k];
            // �������� ����������� ��� ������ ����������
            // � ������� �� ������� ���������� � ����������
        }
    }
    if (k == -1) {
        return 0;
    }
}