#include "Requirement.h"

Requirement::Requirement()
{

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
