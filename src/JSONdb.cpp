#include "JSONdb.h"
#include "JSONSerialization.h"
#include "nlohmann/json.hpp"

using nlohmann::json;

JSONdb::JSONdb()
{
    filepath = "../db/airborne-alm-data.json";
}

bool JSONdb::load()
{
    bool success = false;


    return success;
}

bool JSONdb::save(App& app)
{
    bool success = false;


    return success;
}


