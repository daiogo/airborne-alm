#pragma once

#include "Document.h"
#include <list>
#include <string>
#include "SRATS.h"

class CRS : public Document {
private:
    std::list<SRATS> srats_list;
    std::string system_overview;

public:
    CRS();
};
