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

    void add_requirement(const T& req)
    {
        requirements.push_back(req);
    }

    void print_list()
    {
        for (auto& item : requirements) {
            std::cout << "ID: " << item.get_rid() << std::endl;
            std::cout << "Body: " << item.get_body() << std::endl;
        }
        system("pause");
    }
};
