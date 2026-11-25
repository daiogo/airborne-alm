#include "JSONdb.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include <cstdlib>

using nlohmann::json;

JSONdb::JSONdb()
{
    filepath = "./db/airborne-alm-data.json";
}

bool JSONdb::load()
{
    bool success = false;
    json j;
    AirborneSystem as;

    file.open(filepath, std::ios::in);

    if (file.is_open())
    {
        // Load the file to memory
        j << file;

        // Parse and populate each system in the JSON array
        for (int i = 0; i < j.size(); i++)
        {
            //std::cout << j[i]["name"].get<std::string>() << std::endl;
            as.set_name(j[i]["name"]);
            as.set_id_prefix(j[i]["id_prefix"]);

            system_list->push_back(as);
        }

        success = true;
    }

    system("pause");

    return success;
}

bool JSONdb::save()
{
    bool success = false;


    return success;
}


