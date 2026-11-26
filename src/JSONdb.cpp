#include "AirborneSystem.h"
#include "JSONdb.h"
#include <iostream>
#include <cstdlib>

//int Class::var = 0;
std::string JSONdb::filepath;
std::fstream JSONdb::file;
json JSONdb::j;

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
    AirborneSystem as;

    file.open(filepath, std::ios::in);

    if (file.is_open())
    {
        // Load the file to memory
        j << file;

        // Parse and populate each system in the JSON array
        for (int i = 0; i < j.size(); i++)
        {
            // Load system fields
            as.set_name(j[i]["name"]);
            as.set_id_prefix(j[i]["id_prefix"]);
            as.set_id_count(j[i]["id_count"]);
            as.set_dal(j[i]["dal"]);

            // Load documents
            load_document(&as, DOC_CRS, i);
            //load_document(&as, DOC_SRD, i);
            //load_document(&as, DOC_SDD, i);

            // Load system into list
            app_ptr->get_system_list()->push_back(as);

            //std::cout << as.get_name() << std::endl;
            //std::cout << as.get_id_prefix() << std::endl;
            //std::cout << as.get_id_count() << std::endl;
            //std::cout << as.get_dal() << std::endl;
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

void JSONdb::load_document(AirborneSystem* as, DocType doc_type, int idx)
{
    Document *doc_ptr;
    Requirement *req_ptr;
    std::string doc_field;
    SRATS srats;
    HLR hlr;
    LLR llr;

    switch (doc_type)
    {
    case DOC_CRS:
        // Assign custom helpers
        doc_ptr = as->get_crs();
        //doc_ptr = dynamic_cast<CRS*>(as->get_crs());
        doc_field = "crs_doc";
        req_ptr = &srats;

        // Populate custom fields
        doc_ptr->set_system_overview(j[idx][doc_field]["system_overview"]);
        break;
    case DOC_SRD:
        // Assign custom helpers
        doc_ptr = as->get_srd();
        doc_field = "srd_doc";
        req_ptr = &hlr;

        // Populate custom fields
        doc_ptr->set_software_overview(j[idx][doc_field]["software_overview"]);
        break;
    case DOC_SDD:
        // Assign custom helpers
        doc_ptr = as->get_sdd();
        doc_field = "sdd_doc";
        req_ptr = &llr;

        // Populate custom fields
        doc_ptr->set_design_overview(j[idx][doc_field]["design_overview"]);
        break;
    }

    doc_ptr->set_title(j[idx][doc_field]["title"]);
    doc_ptr->set_purpose(j[idx][doc_field]["purpose"]);
    doc_ptr->set_scope(j[idx][doc_field]["scope"]);
    doc_ptr->set_referenced_docs(j[idx][doc_field]["referenced_docs"]);
    doc_ptr->set_acronyms(j[idx][doc_field]["acronyms"]);
    doc_ptr->set_appendix(j[idx][doc_field]["appendix"]);

    for (auto& req : j[idx][doc_field]["requirements"])
    {
        std::cout << "Entered" << std::endl;
        req_ptr->set_rid(req["rid"]);
        req_ptr->set_body(req["body"]);
        req_ptr->set_comments(req["comments"]);
        req_ptr->set_type(req["type"]);
        req_ptr->set_level(req["level"]);
        req_ptr->set_safety(req["safety"]);
        req_ptr->set_derived(req["derived"]);
        //req_ptr->get_linked_hlrs()->push_back(...);


        ((std::list<SRATS>*)doc_ptr->get_requirements_list_ptr())->push_back(*req_ptr);
        //std::cout << "Loaded ID: " << doc_ptr->get_requirements_list_ptr()->back().get_rid() << std::endl;
    }
}

