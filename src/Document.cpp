#include "Document.h"

std::string Document::get_title()
{
    return title;
}

std::string Document::get_purpose()
{
    return purpose;
}

std::string Document::get_scope()
{
    return scope;
}

std::string Document::get_referenced_docs()
{
    return referenced_docs;
}

std::string Document::get_acronyms()
{
    return acronyms;
}

std::string Document::get_appendix()
{
    return appendix;
}

void Document::set_title(std::string value)
{
    title = value;
}

void Document::set_purpose(std::string value)
{
    purpose = value;
}

void Document::set_scope(std::string value)
{
    scope = value;
}

void Document::set_referenced_docs(std::string value)
{
    referenced_docs = value;
}

void Document::set_acronyms(std::string value)
{
    acronyms = value;
}

void Document::set_appendix(std::string value)
{
    appendix = value;
}

std::string Document::get_system_overview()
{
    return "ERROR GETTING THE RIGHT DATA";
}

void Document::set_system_overview(std::string value)
{

}

std::string Document::get_software_overview()
{
    return "ERROR GETTING THE RIGHT DATA";
}

void Document::set_software_overview(std::string value)
{

}

std::string Document::get_design_overview()
{
    return "ERROR GETTING THE RIGHT DATA";
}

void Document::set_design_overview(std::string value)
{

}
