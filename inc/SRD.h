#pragma once

#include "Document.h"
#include "HLR.h"
#include <string>

class SRD : public Document<HLR> {
private:
    //std::list<HLR> hlr_list;
    std::string software_overview;

public:
    SRD();
    /*
    bool create_requirement(Requirement req);
    Requirement* read_requirement(std::string id);
    bool update_requirement(std::string id);
    bool delete_requirement(std::string id);
    void print_requirements_list();
    */
};
