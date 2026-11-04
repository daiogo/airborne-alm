#pragma once

#include <list>
#include "HLR.h"
#include "Requirement.h"

class HLR;

class SRATS : public Requirement {
private:
    std::list<HLR> linked_hlrs;

public:
    SRATS(std::string id, std::string b, std::string c, ReqType t, ReqLevel l, bool s, bool d);
    ~SRATS();
};
