#include "CRS.h"
#include <sstream>

CRS::CRS()
{
    doc_type = DOC_CRS;
    title = "CRS - Component System Requirements";
    system_overview = "This is the CRS design overview";
}

std::string CRS::export_document()
{
    std::ostringstream doc;

    // Assemble the Markdown file structure
    doc << "# " << title << "\n\n"
        << "## Purpose\n" << purpose << "\n\n"
        << "## Scope\n" << scope << "\n\n"
        << "## Referenced Documents\n" << referenced_docs << "\n\n"
        << "## System Overview\n" << system_overview << "\n\n"
        << "## Requirements\n" << export_reqs_to_markdown() << "\n\n"
        << "## Acronyms\n" << acronyms << "\n\n"
        << "## Appendix\n" << appendix << "\n\n";

    return doc.str();
}

void CRS::set_system_overview(std::string value)
{
    system_overview = value;
}

std::string CRS::get_system_overview()
{
    return system_overview;
}
