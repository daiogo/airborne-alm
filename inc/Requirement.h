#pragma once

#include <string>

typedef enum {
    LEVEL_SRATS = 0,
    LEVEL_HLR = 1,
    LEVEL_LLR = 2,
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
    void fetch();
    void edit();
    void drop();
    std::string get_rid();
    std::string get_body();
};
