#pragma once

#include <list>
#include "SRATS.h"
#include "LLR.h"
#include "Requirement.h"

class SRATS;
class LLR;

class HLR : public Requirement {
private:
    std::list<SRATS> linked_srats;
    std::list<LLR> linked_llrs;

public:
    HLR();//(std::string id, std::string b, std::string c, ReqType t, ReqLevel l, bool s, bool d);
    HLR(Requirement req);
    ~HLR();
};
