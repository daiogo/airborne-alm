#include "AirborneSystem.h"

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

