#pragma once

#include "Requirement.h"
#include "Document.h"
#include <string>
#include <list>

template <typename T>
class ReqDocument : public Document {
protected:
    std::list<T> requirements;

public:

    void add_requirement(Requirement req)
    {
        requirements.push_back(T(req));
    }

    Requirement* get_requirement_ptr(std::string id)
    {
        Requirement *req_ptr = nullptr;

        for (auto& item : requirements)
        {
            if (item.get_rid() == id)
            {
                req_ptr = &item;
                break;
            }
        }

        return req_ptr;
    }

    bool delete_requirement(std::string id)
    {
        bool success = false;

        for (auto it = requirements.begin(); it != requirements.end(); it++)
        {
            if (it->get_rid() == id)
            {
                requirements.erase(it);
                success = true;
                break;
            }
        }

        return success;
    }

    std::list<Requirement*> get_requirements()
    {
        std::list<Requirement*> req_ptrs;

        for (auto& req : requirements)
        {
            req_ptrs.push_back(&req);
        }

        return req_ptrs;
    }
};



