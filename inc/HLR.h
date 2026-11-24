#pragma once

#include <list>
#include "SRATS.h"
#include "LLR.h"
#include "Requirement.h"

class SRATS;
class LLR;

class HLR : public Requirement {
private:
    std::list<std::string> linked_srats;
    std::list<std::string> linked_llrs;

public:
    HLR();
    HLR(Requirement req);

    void set_linked_srats(std::list<std::string> value);
    void set_linked_llrs(std::list<std::string> value);
    std::list<std::string>* get_linked_srats();
    std::list<std::string>* get_linked_llrs();
};
