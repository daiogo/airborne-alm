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

class Document {
protected:
    std::string title;
    std::string purpose;
    std::string scope;
    std::string referenced_docs;
    std::string acronyms;
    std::string appendix;

public:
    std::string get_title();
    virtual std::string export_document() = 0;
    virtual void add_requirement(Requirement req) = 0;
    virtual Requirement* get_requirement_ptr(std::string id) = 0;
    virtual bool delete_requirement(std::string id) = 0;
    virtual void print_requirements_list() = 0;
};

