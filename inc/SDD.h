#pragma once

#include "Document.h"
#include "ReqDocument.h"
#include "LLR.h"
#include <string>

class SDD : public ReqDocument<LLR> {
private:
    std::string design_overview;

public:
    SDD();
    std::string export_document();
    std::string get_design_overview();
    void set_design_overview(std::string value);
};
