#pragma once

#include "Document.h"
#include "ReqDocument.h"
#include "SRATS.h"
#include <string>

class CRS : public ReqDocument<SRATS> {
private:
    std::string system_overview;

public:
    CRS();
    std::string export_document();
    std::string get_system_overview();
    void set_system_overview(std::string value);
};
