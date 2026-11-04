#pragma once

#include "Document.h"
#include <list>
#include <string>
#include "LLR.h"

class SDD : public Document {
private:
    std::list<LLR> llr_list;
    std::string design_overview;

public:
    SDD();
};
