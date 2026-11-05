#pragma once

#include "Document.h"
#include "LLR.h"
#include <string>

class SDD : public Document<LLR> {
private:
    std::string design_overview;

public:
    SDD();
};
