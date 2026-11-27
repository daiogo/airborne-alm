#include "AirborneSystem.h"
#include "JSONdb.h"

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

bool JSONdb::save(App* app_ptr)
{
    bool success = false;
    json json_file = json::array();
    json json_as;

    file.open(filepath, std::ios::out);

    if (file.is_open())
    {
        for (auto& system : *(app_ptr->get_system_list()))
        {

            json_as["name"] = system.get_name();
            json_as["id_prefix"] = system.get_id_prefix();
            json_as["id_count"] = system.get_id_count();
            json_as["dal"] = system.get_dal();

            json_as["crs_doc"] = save_document<SRATS>(system.get_crs());
            json_as["srd_doc"] = save_document<HLR>(system.get_srd());
            json_as["sdd_doc"] = save_document<LLR>(system.get_sdd());

            json_file.push_back(json_as);
        }

        file << std::setw(4) << json_file;

        success = true;

        file.close();
    }

    return success;
}

template <typename T>
json JSONdb::save_document(Document* doc_ptr)
{
    T req;
    json json_doc;
    json json_req;

    // Populate the custom fields first
    if constexpr (std::is_same_v<T, SRATS>)
    {
        json_doc["system_overview"] = doc_ptr->get_system_overview();
    }
    else if constexpr (std::is_same_v<T, HLR>)
    {
        json_doc["software_overview"] = doc_ptr->get_software_overview();
    }
    else if constexpr (std::is_same_v<T, LLR>)
    {
        json_doc["design_overview"] = doc_ptr->get_design_overview();
    }

    // Populate common fields
    json_doc["title"] = doc_ptr->get_title();
    json_doc["purpose"] = doc_ptr->get_purpose();
    json_doc["scope"] = doc_ptr->get_scope();
    json_doc["referenced_docs"] = doc_ptr->get_referenced_docs();
    json_doc["acronyms"] = doc_ptr->get_acronyms();
    json_doc["appendix"] = doc_ptr->get_appendix();


    for (auto& requirement : *((std::list<T>*)doc_ptr->get_requirements_list_ptr()))
    {
        json_req["rid"] = requirement.get_rid();
        json_req["body"] = requirement.get_body();
        json_req["comments"] = requirement.get_comments();
        json_req["type"] = requirement.get_type();
        json_req["level"] = requirement.get_level();
        json_req["safety"] = requirement.get_safety();
        json_req["derived"] = requirement.get_derived();

        // Populate the linked requirements
        if constexpr (std::is_same_v<T, SRATS> || std::is_same_v<T, LLR>)
        {
            json_req["linked_hlrs"].clear();
            for (auto& id : *(requirement.get_linked_hlrs()))
            {
                json_req["linked_hlrs"].push_back(id);
            }
        }
        else if constexpr (std::is_same_v<T, HLR>)
        {
            json_req["linked_srats"].clear();
            json_req["linked_llrs"].clear();
            for (auto& id : *(requirement.get_linked_srats()))
            {
                json_req["linked_srats"].push_back(id);
            }
            for (auto& id : *(requirement.get_linked_llrs()))
            {
                json_req["linked_llrs"].push_back(id);
            }
        }

        json_doc["requirements"].push_back(json_req);
    }

    return json_doc;
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

            // Clear requirements list of the helper variable as
            as.get_crs()->get_requirements_list_ptr()->clear();
            as.get_srd()->get_requirements_list_ptr()->clear();
            as.get_sdd()->get_requirements_list_ptr()->clear();
        }

        success = true;

        file.close();
    }

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

        ((std::list<T>*)doc_ptr->get_requirements_list_ptr())->push_back(req);
    }
}

