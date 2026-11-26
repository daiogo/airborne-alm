#pragma once

#include "CRS.h"
#include "SRD.h"
#include "SDD.h"
#include "Document.h"
#include <string>

class AirborneSystem {
private:
    std::string name;
    std::string id_prefix;
    unsigned int id_count;
    std::string dal;
    CRS crs_doc;
    SRD srd_doc;
    SDD sdd_doc;

public:
    AirborneSystem();
    AirborneSystem(std::string n, std::string i, char d);

    void set_name(std::string n);
    void set_id_prefix(std::string p);
    void set_id_count(unsigned int c);
    void set_dal(std::string d);
    std::string get_name();
    std::string get_id_prefix();
    unsigned int get_id_count();
    std::string get_dal();
    std::string get_and_increment_id_count();
    CRS* get_crs();
    SRD* get_srd();
    SDD* get_sdd();
};
