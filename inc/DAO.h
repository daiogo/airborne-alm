#pragma once

#include <string>
#include <fstream>

class DAO {
protected:
    std::string filepath;
    std::fstream file;

public:
    virtual bool load();
    virtual bool save();
};

