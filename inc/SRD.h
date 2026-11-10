#pragma once

#include "Document.h"
#include "ReqDocument.h"
#include "HLR.h"
#include <string>

class SRD : public ReqDocument<HLR> {
private:
    //std::list<HLR> hlr_list;
    std::string software_overview;

public:
    SRD();
    std::string export_document();
    /*
    bool create_requirement(Requirement req);
    Requirement* get_requirement_ptr(std::string id);
    bool update_requirement(std::string id);
    bool delete_requirement(std::string id);
    void print_requirements_list();
    */
};
