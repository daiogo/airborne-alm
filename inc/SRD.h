#pragma once

#include "Document.h"
#include "ReqDocument.h"
#include "HLR.h"
#include <string>

class SRD : public ReqDocument<HLR> {
private:
    std::string software_overview;

public:
    SRD();
    std::string export_document();
    std::string get_software_overview();
    void set_software_overview(std::string value);
};
