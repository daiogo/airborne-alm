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
    HLR();//(std::string id, std::string b, std::string c, ReqType t, ReqLevel l, bool s, bool d);
    HLR(Requirement req);
    ~HLR();
    std::list<std::string>* get_linked_srats();
    std::list<std::string>* get_linked_llrs();
};
