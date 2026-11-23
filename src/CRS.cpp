#include "CRS.h"
#include <sstream>

CRS::CRS()
{
    doc_type = DOC_CRS;
    title = "CRS - Component System Requirements";
    purpose = "Describe here the goal for which this document is being written.";
    scope = "Describe what will be done and what will not be done in this document.";
    referenced_docs = "List all documents referenced to the project. It can be other project documents, industry standards, textbooks, etc.";
    system_overview = "This is the CRS system overview";
    acronyms = "N/A";
    appendix = "N/A";
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
