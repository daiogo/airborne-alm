#pragma once

#include "Requirement.h"
#include <string>
#include <list>
#include <iostream>

typedef enum {
    DOC_CRS = 1,
    DOC_SRD = 2,
    DOC_SDD = 3,
} DocType;

//template <typename T>
class Document {
protected:
    std::string title;
    std::string purpose;
    std::string scope;
    std::string referenced_docs;
    //std::string overview;
    //std::list<T> requirements;
    std::string acronyms;
    std::string appendix;

public:
    virtual bool create_requirement(Requirement req);
    virtual Requirement* read_requirement(std::string id);
    virtual bool update_requirement(std::string id);
    virtual bool delete_requirement(std::string id);
    virtual void print_requirements_list();
    std::string get_title();
    void export_document();

/*
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

    bool update_requirement(Requirement req)
    {
        bool success = false;

        for (auto& item : requirements)
        {
            if (item.get_rid() == req.get_rid())
            {
                item.set_body();
                item.set_comments();
                item.set_type();
                item.set_level();
                item.set_safety();
                item.set_derived();
                success = true;
                break;
            }
        }

        return success;
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

    std::string get_title()
    {
        return title;
    }


    void export_document()
    {

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


/*
    void add_requirement(const T& req)
    {
        requirements.push_back(req);
    }

    bool delete_requirement(std::string id)
    {
        bool success = false;

        for (auto it = requirements.begin(); it != requirements.end(); it++)
        {
            if (it->rid == id)
            {
                requirements.erase(it);
                success = true;
                break;
            }
        }
        return success;
    }

    std::list<T>* get_requirements_list()
    {
        return &requirements;
    }


    T* get_requirement(std::string id)
    {
        T *req_ptr = nullptr;
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
*/

};


