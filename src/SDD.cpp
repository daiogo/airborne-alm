#include "SDD.h"
#include <sstream>

SDD::SDD()
{
    doc_type = DOC_SDD;
    title = "SDD - Software Design Description";
    purpose = "Describe here the goal for which this document is being written.";
    scope = "Describe what will be done and what will not be done in this document.";
    referenced_docs = "List all documents referenced to the project. It can be other project documents, industry standards, textbooks, etc.";
    design_overview = "This is the SDD design overview.";
    acronyms = "N/A";
    appendix = "N/A";
}

std::string SDD::export_document()
{
    std::ostringstream doc;

    // Assemble the Markdown file structure
    doc << "# " << title << "\n\n"
        << "## Purpose\n" << purpose << "\n\n"
        << "## Scope\n" << scope << "\n\n"
        << "## Referenced Documents\n" << referenced_docs << "\n\n"
        << "## Design Overview\n" << design_overview << "\n\n"
        << "## Requirements\n" << export_reqs_to_markdown() << "\n\n"
        << "## Acronyms\n" << acronyms << "\n\n"
        << "## Appendix\n" << appendix << "\n\n";

    return doc.str();
}

void SDD::set_design_overview(std::string value)
{
    design_overview = value;
}

std::string SDD::get_design_overview()
{
    return design_overview;
}
