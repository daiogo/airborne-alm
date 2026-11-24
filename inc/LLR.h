#pragma once

#include <list>
#include "HLR.h"
#include "Requirement.h"

class HLR;

class LLR : public Requirement {
private:
    std::list<std::string> linked_hlrs;

public:
    LLR();
    LLR(Requirement req);

    void set_linked_hlrs(std::list<std::string> value);
    std::list<std::string>* get_linked_hlrs();
};
