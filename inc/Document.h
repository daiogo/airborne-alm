#pragma once

#include <string>
#include <list>
#include <iostream>
#include <cstdlib>

template <typename T>
class Document {
protected:
    std::string title;
    std::string purpose;
    std::string scope;
    std::string referenced_docs;
    //std::string overview;
    std::list<T> requirements;
    std::string acronyms;
    std::string appendix;

public:

    void export_document()
    {

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

    void print_requirements_list()
    {
        for (auto& item : requirements)
        {
            std::cout << "ID: " << item.get_rid() << std::endl;
            std::cout << "Safety: " << item.get_safety() << std::endl;
            std::cout << "Derived: " << item.get_derived() << std::endl;
            std::cout << "Type: " << (item.get_type() ? "functional" : "non-functional") << std::endl;
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

        system("pause");
    }

    void add_requirement(const T& req)
    {
        requirements.push_back(req);
    }
};
