#include "SRD.h"

SRD::SRD()
{
    title = "SRD - Software Requirements Description";
    software_overview = "This is the SRD software overview";
}

std::string SRD::export_document()
{
    std::string doc;

    doc = title +
          "\n\n" +
          software_overview +
          "\n\n";// +
          //requirements

    return doc;
}
/*
bool SRD::create_requirement(Requirement req)
{
    hlr_list.push_back(HLR(req));
    return true;
}

Requirement* SRD::read_requirement(std::string id)
{
    Requirement *req_ptr = nullptr;

    for (auto& item : hlr_list)
    {
        if (item.get_rid() == id)
        {
            req_ptr = &item;
            break;
        }
    }

    return req_ptr;
}

bool SRD::update_requirement(std::string id)
{
    bool success = false;

    return success;
}

bool SRD::delete_requirement(std::string id)
{
    bool success = false;

    return success;
}

void SRD::print_requirements_list()
{
    if (hlr_list.size() > 0)
    {
        for (auto& item : hlr_list)
        {
            std::cout << "ID: " << item.get_rid() << std::endl;
            std::cout << "Safety: " << (item.get_safety() ? "True" : "False") << std::endl;
            std::cout << "Derived: " << (item.get_derived() ? "True" : "False") << std::endl;
            std::cout << "Type: " << (item.get_type() ? "Functional" : "Non-functional") << std::endl;
            std::cout << std::endl;
            std::cout << "Description: " << std::endl;
            std::cout << item.get_body() << std::endl;
            std::cout << std::endl;
            std::cout << "Comments: " << std::endl;
            std::cout << item.get_comments() << std::endl;
            std::cout << std::endl;
            std::cout << "Linked requirements: " << std::endl;
            //std::cout << "Linked requirements here" << std::endl;
            std::cout << "----------------" << std::endl;
        }
    }
    else
    {
        std::cout << "This document currently has no requirements" << std::endl;
    }
}
*/
