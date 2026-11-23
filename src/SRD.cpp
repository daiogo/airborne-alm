#include "SRD.h"

SRD::SRD()
{
    doc_type = DOC_SRD;
    title = "SRD - Software Requirements Description";
    software_overview = "This is the SRD software overview";
}

std::string SRD::export_document()
{
    std::ostringstream doc;

    // Assemble the Markdown file structure
    doc << "# " << title << "\n\n"
        << "## Purpose\n" << purpose << "\n\n"
        << "## Scope\n" << scope << "\n\n"
        << "## Referenced Documents\n" << referenced_docs << "\n\n"
        << "## System Overview\n" << software_overview << "\n\n"
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
