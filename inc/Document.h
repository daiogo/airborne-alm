#pragma once

#include "Requirement.h"
#include "SRATS.h"
#include "HLR.h"
#include "LLR.h"
#include <string>
#include <list>

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
    DocType doc_type;   // Public DocType attribute to facilitate the identification of each context for custom actions

    std::string get_title();
    std::string get_purpose();
    std::string get_scope();
    std::string get_referenced_docs();
    std::string get_acronyms();
    std::string get_appendix();
    void set_title(std::string value);
    void set_purpose(std::string value);
    void set_scope(std::string value);
    void set_referenced_docs(std::string value);
    void set_acronyms(std::string value);
    void set_appendix(std::string value);

    // From ReqDocument
    virtual std::string export_document() = 0;
    virtual void add_requirement(Requirement req) = 0;
    virtual Requirement* get_requirement_ptr(std::string id) = 0;
    virtual bool delete_requirement(std::string id) = 0;
    virtual std::list<Requirement*> fetch_requirements() = 0;
    virtual std::list<std::string>* get_requirement_ids() = 0;
    virtual std::string export_reqs_to_markdown() = 0;  // Put here to avoid function duplication

    // From CRS, SRD and SDD
    virtual std::string get_system_overview();
    virtual void set_system_overview(std::string value);
    virtual std::string get_software_overview();
    virtual void set_software_overview(std::string value);
    virtual std::string get_design_overview();
    virtual void set_design_overview(std::string value);
    virtual void* get_requirements_list_ptr();
};

