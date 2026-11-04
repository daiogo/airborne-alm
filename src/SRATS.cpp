#include "SRATS.h"

SRATS::SRATS(std::string id, std::string b, std::string c, ReqType t, ReqLevel l, bool s, bool d)
{
    rid = id;
    body = b;
    comments = c;
    type = t;
    level = l;
    safety = s;
    derived = d;
}

SRATS::~SRATS()
{

}
