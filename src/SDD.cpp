#include "SDD.h"

SDD::SDD()
{
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
