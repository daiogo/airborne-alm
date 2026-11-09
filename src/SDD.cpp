#include "SDD.h"

SDD::SDD()
{
    title = "SDD - Software Design Description";
}

bool SDD::create_requirement(Requirement req)
{
    llr_list.push_back(LLR(req));
    return true;
}

Requirement* SDD::read_requirement(std::string id)
{
    Requirement *req_ptr = nullptr;

    for (auto& item : llr_list)
    {
        if (item.get_rid() == id)
        {
            req_ptr = &item;
            break;
        }
    }

    return req_ptr;
}

bool SDD::update_requirement(std::string id)
{
    bool success = false;

    return success;
}

bool SDD::delete_requirement(std::string id)
{
    bool success = false;

    return success;
}

void SDD::print_requirements_list()
{
    if (llr_list.size() > 0)
    {
        for (auto& item : llr_list)
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
