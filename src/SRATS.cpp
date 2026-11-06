#include "SRATS.h"

SRATS::SRATS()//(std::string id, std::string b, std::string c, ReqType t, ReqLevel l, bool s, bool d)
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

SRATS::SRATS(Requirement req)
{
    rid = req.get_rid();
    body = req.get_body();
    comments = req.get_comments();
    type = req.get_type();
    level = req.get_level();
    safety = req.get_safety();
    derived = req.get_derived();
}

SRATS::~SRATS()
{

}
