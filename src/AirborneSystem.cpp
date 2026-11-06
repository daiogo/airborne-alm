#include "AirborneSystem.h"
#include "Document.h"

AirborneSystem::AirborneSystem(std::string n, std::string i, char d)
{
    name = n;
    id_prefix = i;
    id_count = 0;   // Load from db
    dal = d;
}

std::string AirborneSystem::get_name()
{
    return name;
}

std::string AirborneSystem::get_id_prefix()
{
    return id_prefix;
}

std::string AirborneSystem::get_id_count()
{
    id_count++;
    return std::to_string(id_count);
}

std::any AirborneSystem::get_document_ptr(DocType doc)
{
    std::any doc_ptr;

    switch (doc)
    {
    case DOC_CRS:
        doc_ptr = &crs_doc;
        break;
    case DOC_SRD:
        doc_ptr = &srd_doc;
        break;
    case DOC_SDD:
        doc_ptr = &sdd_doc;
        break;
    }

    return doc_ptr;
}

CRS* AirborneSystem::get_crs()
{
    return &crs_doc;
}

SRD* AirborneSystem::get_srd()
{
    return &srd_doc;
}

SDD* AirborneSystem::get_sdd()
{
    return &sdd_doc;
}

