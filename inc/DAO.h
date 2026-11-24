#pragma once

#include <string>
#include <fstream>

class DAO {
protected:
    std::string filepath;
    std::fstream file;

public:
    virtual bool init() = 0;
    virtual bool load() = 0;
    virtual bool save() = 0;
};

