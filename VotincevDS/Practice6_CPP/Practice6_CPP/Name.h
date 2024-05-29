#pragma once
#include <string>

class Name {
private:
    std::string fullname;
    std::string F;
    std::string I;
    std::string O;

    void make_good_name();
public:
    Name();
    Name(const Name&);

    std::string get_F() const { return this->F; }
    std::string get_I() const { return this->I; }
    std::string get_O() const { return this->O; }


    std::string get_fullname() const { return this->fullname; }
    
    const Name& operator=(const Name&);
    friend std::ifstream& operator>>(std::ifstream& inf, Name& name);
    friend std::ostream& operator<<(std::ostream& out, Name& name);
    friend std::ostream& operator<<(std::ostream& out, Name name);
};

