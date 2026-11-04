#pragma once

#include "Document.h"
#include <list>
#include <string>
#include "HLR.h"

class SRD : public Document {
private:
    std::list<HLR> hlr_list;
    std::string software_overview;

public:
    SRD();
};
