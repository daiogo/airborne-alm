#pragma once

#include "Document.h"
#include "LLR.h"
#include <string>

class SDD : public Document<LLR> {
private:
    //std::list<LLR> llr_list;
    std::string design_overview;

public:
    SDD();
    /*
    bool create_requirement(Requirement req);
    Requirement* read_requirement(std::string id);
    bool update_requirement(std::string id);
    bool delete_requirement(std::string id);
    */
};
