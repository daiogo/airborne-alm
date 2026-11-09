#pragma once

#include <string>

typedef enum {
    LEVEL_SRATS = 0,
    LEVEL_HLR = 1,
    LEVEL_LLR = 2,
    LEVEL_UNDEF = 3,
} ReqLevel;

typedef enum {
    FUNCTIONAL = 0,
    NON_FUNCTIONAL = 1,
} ReqType;

class Requirement {
protected:
    std::string rid;
    std::string body;
    std::string comments;
    //int version;
    ReqType type;
    ReqLevel level;
    bool safety;
    bool derived;

public:
    Requirement();
    Requirement(std::string id, std::string b, std::string c, ReqType t, ReqLevel l, bool s, bool d);
    std::string get_rid();
    std::string get_body();
    std::string get_comments();
    ReqType get_type();
    ReqLevel get_level();
    bool get_safety();
    bool get_derived();
    void set_body(std::string b);
    void set_comments(std::string c);
    void set_type(ReqType t);
    void set_level(ReqLevel l);
    void set_safety(bool s);
    void set_derived(bool d);
};
