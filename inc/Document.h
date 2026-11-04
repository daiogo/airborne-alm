#pragma once

#include <string>

class Document {
protected:
    std::string title;
    std::string purpose;
    std::string scope;
    std::string referenced_docs;
    std::string requirements;
    std::string acronyms;
    std::string appendix;

public:
    void export_document();
};
