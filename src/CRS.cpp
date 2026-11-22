#include "CRS.h"

CRS::CRS()
{
    title = "CRS - Component System Requirements";
    doc_type = DOC_CRS;
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

void CRS::set_system_overview(std::string value)
{
    system_overview = value;
}

std::string CRS::get_system_overview()
{
    return system_overview;
}
