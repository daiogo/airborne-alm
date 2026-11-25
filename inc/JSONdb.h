#pragma once

#include "DAO.h"

class JSONdb : public DAO {
private:

public:
    JSONdb();
    bool load();
    bool save();
};


