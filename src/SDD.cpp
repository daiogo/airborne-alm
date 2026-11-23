#include "SDD.h"

SDD::SDD()
{
    doc_type = DOC_SDD;
    title = "SDD - Software Design Description";
    design_overview = "This is the SDD software overview";
}

std::string SDD::export_document()
{
    std::string doc;

    doc = title +
          "\n\n" +
          design_overview +
          "\n\n";// +
          //requirements

    return doc;
}

void SDD::set_design_overview(std::string value)
{
    design_overview = value;
}

std::string SDD::get_design_overview()
{
    return design_overview;
}
