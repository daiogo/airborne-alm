#pragma once

#include "CRS.h"
#include "SRD.h"
#include "SDD.h"
#include <string>

class AirborneSystem {
private:
    std::string name;
    std::string id_prefix;
    unsigned int id_count;
    char dal;
    CRS crs_doc;
    SRD srd_doc;
    SDD sdd_doc;

public:
    AirborneSystem(std::string n, std::string i, char d);
    std::string get_name();
    std::string get_id_prefix();
    std::string get_id_count();
    CRS* get_crs();
    SRD* get_srd();
    SDD* get_sdd();

};
