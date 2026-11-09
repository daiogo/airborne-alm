#pragma once

#include "Requirement.h"
#include "Document.h"
#include <string>
#include <list>
#include <iostream>

template <typename T>
class RequirementsList : public Document {
protected:
    std::list<T> requirements;

public:

    void create_requirement(Requirement req)
    {
        requirements.push_back(T(req));
    }

    Requirement* read_requirement(std::string id)
    {
        Requirement *req_ptr = nullptr;

        for (auto& item : requirements)
        {
            if (item.get_rid() == id)
            {
                req_ptr = &item;
                break;
            }
        }

        return req_ptr;
    }

    bool delete_requirement(std::string id)
    {
        bool success = false;

        for (auto it = requirements.begin(); it != requirements.end(); it++)
        {
            if (it->get_rid() == id)
            {
                requirements.erase(it);
                success = true;
                break;
            }
        }

        return success;
    }

    void print_requirements_list()
    {
        if (requirements.size() > 0)
        {
            for (auto& item : requirements)
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
};



