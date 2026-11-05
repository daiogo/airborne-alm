#pragma once

#include "Document.h"
#include "SRATS.h"
#include <string>

class CRS : public Document<SRATS> {
private:
    std::string system_overview;

public:
    CRS();
};
