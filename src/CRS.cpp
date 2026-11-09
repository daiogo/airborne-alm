#include "CRS.h"

CRS::CRS()
{
    title = "CRS - Component System Requirements";
    system_overview = "This is the CRS design overview";
}

std::string CRS::export_document()
{
    std::string doc;

    doc = title +
          "\n\n" +
          system_overview +
          "\n\n";// +
          //requirements

    return doc;
}

