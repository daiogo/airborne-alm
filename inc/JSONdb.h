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
    static std::string filepath1;
    static std::fstream file;

public:
    //JSONdb();
    static void init();
    static bool save(App* app_ptr);
    static bool load(App* app_ptr);
    template <typename T>
    static json save_document(Document* doc_ptr);
    template <typename T>
    static void load_document(Document* doc_ptr, json json_doc);
};


