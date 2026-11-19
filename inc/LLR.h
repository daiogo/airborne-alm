#pragma once

#include <list>
#include "HLR.h"
#include "Requirement.h"

class HLR;

class LLR : public Requirement {
private:
    std::list<std::string> linked_hlrs;

public:
    LLR();//(std::string id, std::string b, std::string c, ReqType t, ReqLevel l, bool s, bool d);
    LLR(Requirement req);
    ~LLR();
    std::list<std::string>* get_linked_hlrs();
};
