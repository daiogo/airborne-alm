#pragma once

#include <string>
#include <fstream>

class DAO {
protected:
    static std::string filepath;
    static std::fstream file;

public:
    static void init();
    static bool load();
    static bool save();
};

