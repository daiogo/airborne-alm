#pragma once

#include "Document.h"
#include "ReqDocument.h"
#include "LLR.h"
#include <string>

class SDD : public ReqDocument<LLR> {
private:
    //std::list<LLR> llr_list;
    std::string design_overview;

public:
    SDD();
    std::string export_document();
    /*
    bool create_requirement(Requirement req);
    Requirement* get_requirement_ptr(std::string id);
    bool update_requirement(std::string id);
    bool delete_requirement(std::string id);
    void print_requirements_list();
    */
};
