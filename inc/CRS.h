#pragma once

#include "Document.h"
#include "SRATS.h"
#include <string>

class CRS : public Document {
private:
    std::list<SRATS> srats_list;
    std::string system_overview;

public:
    CRS();
    bool create_requirement(Requirement req);
    bool read_requirement(std::string id);
    bool update_requirement(std::string id);
    bool delete_requirement(std::string id);
};
