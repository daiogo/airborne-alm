#pragma once

#include "Document.h"
#include "HLR.h"
#include <string>

class SRD : public Document {
private:
    std::list<HLR> hlr_list;
    std::string software_overview;

public:
    SRD();
    bool create_requirement(Requirement req);
    bool read_requirement(std::string id);
    bool update_requirement(std::string id);
    bool delete_requirement(std::string id);
};
