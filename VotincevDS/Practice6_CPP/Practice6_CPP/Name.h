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

    std::string get_F() { return this->F; }
    std::string get_I() { return this->I; }
    std::string get_O() { return this->O; }


    std::string get_fullname() { return this->fullname; }

    void make_good_name();
    Name& operator=(Name&);
    friend std::ifstream& operator>>(std::ifstream& inf, Name& name);
    friend std::ostream& operator<<(std::ostream& out, Name& name);
};

