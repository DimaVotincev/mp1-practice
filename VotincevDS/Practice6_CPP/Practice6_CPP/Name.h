#pragma once
#include <string>

class Name {
private:
    std::string fullname;
    std::string F;
    std::string I;
    std::string O;
public:
    Name();

    void make_good_name();
    friend std::ifstream& operator>>(std::ifstream& inf, Name& name);
};

