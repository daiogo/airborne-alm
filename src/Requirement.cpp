#include "Requirement.h"

Requirement::Requirement()
{

}

Requirement::Requirement(std::string id, std::string b, std::string c, ReqType t, ReqLevel l, bool s, bool d)
{
    rid = id;
    body = b;
    comments = c;
    type = t;
    level = l;
    safety = s;
    derived = d;
}

void Requirement::fetch()
{

}

void Requirement::edit()
{

}

void Requirement::drop()
{

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
