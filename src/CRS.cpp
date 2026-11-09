#include "CRS.h"

CRS::CRS()
{
    title = "CRS - Component System Requirements";
    system_overview = "This is the SDD design overview";
}

std::string export_document()
{
    std::string doc;

    doc = title +
          "\n\n" +
          system_overview +
          "\n\n";// +
          //requirements

    return doc;
}

/*
bool CRS::create_requirement(Requirement req)
{
    srats_list.push_back(SRATS(req));
    return true;
}

Requirement* CRS::read_requirement(std::string id)
{
    Requirement *req_ptr = nullptr;

    for (auto& item : srats_list)
    {
        if (item.get_rid() == id)
        {
            req_ptr = &item;
            break;
        }
    }

    return req_ptr;
}

bool CRS::update_requirement(std::string id)
{
    bool success = false;

    return success;
}

bool CRS::delete_requirement(std::string id)
{
    bool success = false;

    return success;
}

void CRS::print_requirements_list()
{
    if (srats_list.size() > 0)
    {
        for (auto& item : srats_list)
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
