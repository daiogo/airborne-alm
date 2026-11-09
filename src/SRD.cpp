#include "SRD.h"

SRD::SRD()
{
    title = "SRD - Software Requirements Description";
    software_overview = "This is the SRD software overview";
}

std::string SRD::export_document()
{
    std::string doc;

    doc = title +
          "\n\n" +
          software_overview +
          "\n\n";// +
          //requirements

    return doc;
}
