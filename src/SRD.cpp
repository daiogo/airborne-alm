#include "SRD.h"
#include <sstream>

SRD::SRD()
{
    doc_type = DOC_SRD;
    title = "SRD - Software Requirements Description";
    purpose = "Describe here the goal for which this document is being written.";
    scope = "Describe what will be done and what will not be done in this document.";
    referenced_docs = "List all documents referenced to the project. It can be other project documents, industry standards, textbooks, etc.";
    software_overview = "This is the SRD software overview";
    acronyms = "N/A";
    appendix = "N/A";
}

std::string SRD::export_document()
{
    std::ostringstream doc;

    // Assemble the Markdown file structure
    doc << "# " << title << "\n\n"
        << "## Purpose\n" << purpose << "\n\n"
        << "## Scope\n" << scope << "\n\n"
        << "## Referenced Documents\n" << referenced_docs << "\n\n"
        << "## Software Overview\n" << software_overview << "\n\n"
        << "## Requirements\n" << export_reqs_to_markdown() << "\n\n"
        << "## Acronyms\n" << acronyms << "\n\n"
        << "## Appendix\n" << appendix << "\n\n";

    return doc.str();
}

void SRD::set_software_overview(std::string value)
{
    software_overview = value;
}


std::string SRD::get_software_overview()
{
    return software_overview;
}
