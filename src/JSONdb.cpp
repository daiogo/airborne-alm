#include "AirborneSystem.h"
#include "JSONdb.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include <cstdlib>

using nlohmann::json;

//int Class::var = 0;
std::string JSONdb::filepath;
std::fstream JSONdb::file;

/*
JSONdb::JSONdb()
{
    filepath = "./db/airborne-alm-data.json";
}
*/

void JSONdb::init()
{
    filepath = "./db/airborne-alm-data.json";
}

bool JSONdb::load(App* app_ptr)
{
    bool success = false;
    json j;
    AirborneSystem as;
    SRATS srats;
    HLR hlr;
    LLR llr;

    file.open(filepath, std::ios::in);

    if (file.is_open())
    {
        // Load the file to memory
        j << file;

        // Parse and populate each system in the JSON array
        for (int i = 0; i < j.size(); i++)
        {
            //std::cout << i << std::endl;
            //std::cout << j[i]["name"].get<std::string>() << std::endl;
            // Set fixed fields
            as.set_name(j[i]["name"]);
            as.set_id_prefix(j[i]["id_prefix"]);
            as.set_id_count(j[i]["id_count"]);
            as.set_dal(j[i]["dal"]);
            //std::cout << "done first" << std::endl;

            std::cout << as.get_name() << std::endl;
            //std::cout << as.get_id_prefix() << std::endl;
            //std::cout << as.get_id_count() << std::endl;
            //std::cout << as.get_dal() << std::endl;

            // Set documents
            as.get_crs()->set_title(j[i]["crs_doc"]["title"]);
            as.get_crs()->set_purpose(j[i]["crs_doc"]["purpose"]);
            as.get_crs()->set_scope(j[i]["crs_doc"]["scope"]);
            as.get_crs()->set_referenced_docs(j[i]["crs_doc"]["referenced_docs"]);
            as.get_crs()->set_acronyms(j[i]["crs_doc"]["acronyms"]);
            as.get_crs()->set_appendix(j[i]["crs_doc"]["appendix"]);
            as.get_crs()->set_system_overview(j[i]["crs_doc"]["system_overview"]);

            for (auto& req : j[i]["crs_doc"]["requirements"])
            {
                // Not entering here. CHEKC TIS!!
                std::cout << "Entered" << std::endl;
                srats.set_rid(req["rid"]);
                srats.set_body(req["body"]);
                srats.set_comments(req["comments"]);
                srats.set_type(req["type"]);
                srats.set_level(req["level"]);
                srats.set_safety(req["safety"]);
                srats.set_derived(req["derived"]);
                //srats.get_linked_hlrs()->push_back(...);

                std::cout << req["rid"].get<std::string>() << std::endl;
                std::cout << req["body"].get<std::string>() << std::endl;


                as.get_crs()->get_requirements_list_ptr()->push_back(srats);
                //std::cout << "Loaded ID: " << as.get_crs()->get_requirements_list_ptr()->size() << std::endl;
                std::cout << "Loaded ID: " << as.get_crs()->get_requirements_list_ptr()->back().get_rid() << std::endl;
            }

            //as.get_crs()->get_requirements_list_ptr()->push (j[i][""]));
            //std::cout << "done crs" << std::endl;

            app_ptr->get_system_list()->push_back(as);
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


