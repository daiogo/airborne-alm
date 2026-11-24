#include "HLR.h"

HLR::HLR()//(std::string id, std::string b, std::string c, ReqType t, ReqLevel l, bool s, bool d)
{
    /*
    rid = id;
    body = b;
    comments = c;
    type = t;
    level = l;
    safety = s;
    derived = d;
    */
}

HLR::HLR(Requirement req)
{
    rid = req.get_rid();
    body = req.get_body();
    comments = req.get_comments();
    type = req.get_type();
    level = LEVEL_HLR;
    safety = req.get_safety();
    derived = req.get_derived();
}

std::list<std::string>* HLR::get_linked_srats()
{
    return &linked_srats;
}

std::list<std::string>* HLR::get_linked_llrs()
{
    return &linked_llrs;
}
