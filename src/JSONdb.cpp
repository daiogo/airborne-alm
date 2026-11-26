#include "AirborneSystem.h"
#include "JSONdb.h"
#include <iostream>
#include <cstdlib>

std::string JSONdb::filepath = "./db/airborne-alm-data.json";
std::fstream JSONdb::file;

/*
JSONdb::JSONdb()
{
    filepath = "./db/airborne-alm-data.json";
}
*/

void JSONdb::init()
{
    //filepath = "./db/airborne-alm-data.json";
}

bool JSONdb::load(App* app_ptr)
{
    bool success = false;
    AirborneSystem as;
    json json_file;

    file.open(filepath, std::ios::in);

    if (file.is_open())
    {
        // Load the file to memory
        json_file << file;

        // Parse and populate each system in the JSON array
        for (int i = 0; i < json_file.size(); i++)
        {
            // Load system fields
            as.set_name(json_file[i]["name"]);
            as.set_id_prefix(json_file[i]["id_prefix"]);
            as.set_id_count(json_file[i]["id_count"]);
            as.set_dal(json_file[i]["dal"]);

            // Load each document
            load_document<SRATS>(as.get_crs(), json_file[i]["crs_doc"]);
            load_document<HLR>(as.get_srd(), json_file[i]["srd_doc"]);
            load_document<LLR>(as.get_sdd(), json_file[i]["sdd_doc"]);

            // Load system into list
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

template <typename T>
void JSONdb::load_document(Document* doc_ptr, json json_doc)
{
    T req;

    // Populate the custom fields first
    if constexpr (std::is_same_v<T, SRATS>)
    {
        doc_ptr->set_system_overview(json_doc["system_overview"]);
    }
    else if constexpr (std::is_same_v<T, HLR>)
    {
        doc_ptr->set_software_overview(json_doc["software_overview"]);
    }
    else if constexpr (std::is_same_v<T, LLR>)
    {
        doc_ptr->set_design_overview(json_doc["design_overview"]);
    }

    // Populate common fields
    doc_ptr->set_title(json_doc["title"]);
    doc_ptr->set_purpose(json_doc["purpose"]);
    doc_ptr->set_scope(json_doc["scope"]);
    doc_ptr->set_referenced_docs(json_doc["referenced_docs"]);
    doc_ptr->set_acronyms(json_doc["acronyms"]);
    doc_ptr->set_appendix(json_doc["appendix"]);

    // Populate the requirements list
    for (auto& requirement : json_doc["requirements"])
    {
        std::cout << "Entered" << std::endl;
        req.set_rid(requirement["rid"]);
        req.set_body(requirement["body"]);
        req.set_comments(requirement["comments"]);
        req.set_type(requirement["type"]);
        req.set_level(requirement["level"]);
        req.set_safety(requirement["safety"]);
        req.set_derived(requirement["derived"]);

        // Populate the linked requirements
        if constexpr (std::is_same_v<T, SRATS> || std::is_same_v<T, LLR>)
        {
            req.get_linked_hlrs()->clear();
            for (auto& id : requirement["linked_hlrs"])
            {
                req.get_linked_hlrs()->push_back(id);
            }
        }
        else if constexpr (std::is_same_v<T, HLR>)
        {
            req.get_linked_srats()->clear();
            req.get_linked_llrs()->clear();
            for (auto& id : requirement["linked_srats"])
            {
                req.get_linked_srats()->push_back(id);
            }
            for (auto& id : requirement["linked_llrs"])
            {
                req.get_linked_llrs()->push_back(id);
            }
        }

        std::cout << "Created" << std::endl;

        ((std::list<T>*)doc_ptr->get_requirements_list_ptr())->push_back(req);
        //std::cout << "Loaded ID: " << ((std::list<T>*)doc_ptr->get_requirements_list_ptr())->back().get_rid() << std::endl;
    }
}

