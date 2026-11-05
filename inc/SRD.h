#pragma once

#include "Document.h"
#include "HLR.h"
#include <string>

class SRD : public Document<HLR> {
private:
    std::string software_overview;

public:
    SRD();
};
