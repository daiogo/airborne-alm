#include "Requirement.h"

Requirement::Requirement()
{

}

Requirement::Requirement(std::string id, std::string b, std::string c, ReqType t, bool s, bool d)
{
    rid = id;
    body = b;
    comments = c;
    type = t;
    safety = s;
    derived = d;
    //level = LEVEL_UNDEF;
}

std::string Requirement::get_rid()
{
    return rid;
}

std::string Requirement::get_body()
{
    return body;
}

std::string Requirement::get_comments()
{
    return comments;
}

ReqType Requirement::get_type()
{
    return type;
}

ReqLevel Requirement::get_level()
{
    return level;
}

bool Requirement::get_safety()
{
    return safety;
}

bool Requirement::get_derived()
{
    return derived;
}

void Requirement::set_rid(std::string id)
{
    rid = id;
}

void Requirement::set_body(std::string b)
{
    body = b;
}

void Requirement::set_comments(std::string c)
{
    comments = c;
}

void Requirement::set_type(ReqType t)
{
    type = t;
}

void Requirement::set_level(ReqLevel l)
{
    level = l;
}

void Requirement::set_safety(bool s)
{
    safety = s;
}

void Requirement::set_derived(bool d)
{
    derived = d;
}

std::list<std::string>* Requirement::get_linked_srats()
{

}

std::list<std::string>* Requirement::get_linked_hlrs()
{

}

std::list<std::string>* Requirement::get_linked_llrs()
{

}
