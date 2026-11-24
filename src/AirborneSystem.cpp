#include "AirborneSystem.h"
#include "Document.h"

AirborneSystem::AirborneSystem(std::string n, std::string i, char d)
{
    name = n;
    id_prefix = i;
    id_count = 0;   // Load from db
    dal = d;
}
void AirborneSystem::set_name(std::string n)
{
    name = n;
}

void AirborneSystem::set_id_prefix(std::string p)
{
    id_prefix = p;
}

void AirborneSystem::set_id_count(unsigned int c)
{
    id_count = c;
}

void AirborneSystem::set_dal(char d)
{
    dal = d;
}

char AirborneSystem::get_dal()
{
    return dal;
}

std::string AirborneSystem::get_name()
{
    return name;
}

std::string AirborneSystem::get_id_prefix()
{
    return id_prefix;
}

std::string AirborneSystem::get_and_increment_id_count()
{
    id_count++;
    return std::to_string(id_count);
}

unsigned int AirborneSystem::get_id_count()
{
    return id_count;
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

