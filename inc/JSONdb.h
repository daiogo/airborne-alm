#pragma once

#include "DAO.h"
#include "App.h"
#include <string>
#include <fstream>

class App;

class JSONdb {
private:
    static std::string filepath;
    static std::fstream file;

public:
    //JSONdb();
    static void init();
    static bool load(App* app_ptr);
    static bool save();
};


