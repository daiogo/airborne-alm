#pragma once

#include "DAO.h"
#include "App.h"
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>

class App;

using nlohmann::json;

class JSONdb {
private:
    static std::string filepath;
    static std::fstream file;
    static json j;

public:
    //JSONdb();
    static void init();
    static bool load(App* app_ptr);
    static void load_document(AirborneSystem* as, DocType doc_type, int idx);
    static bool save();
};


