#pragma once

#include "Document.h"
#include "ReqDocument.h"
#include "SRATS.h"
#include <string>

class CRS : public ReqDocument<SRATS> {
private:
    //std::list<SRATS> srats_list;
    std::string system_overview;

public:
    CRS();
    std::string export_document();
    /*
    bool create_requirement(Requirement req);
    Requirement* get_requirement_ptr(std::string id);
    bool update_requirement(std::string id);
    bool delete_requirement(std::string id);
    void print_requirements_list();
    */
};
