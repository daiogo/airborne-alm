#pragma once

#include "Requirement.h"
#include "Document.h"
#include <sstream>
#include <string>
#include <list>

template <typename T>
class ReqDocument : public Document {
protected:
    std::list<T> requirements;
    std::list<std::string> all_ids;

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

    std::list<std::string>* get_requirement_ids()
    {
        all_ids.clear();

        for (auto& req : requirements)
        {
            all_ids.push_back(req.get_rid());
        }

        return &all_ids;
    }

    std::string export_reqs_to_markdown()
    {
        std::ostringstream req_section;

        // Transform requirements list into Markdown list
        for (auto& req : requirements)
        {
            req_section << "**ID:** " << req.get_rid() << "\\ \n";
            req_section << "**Safety:** " << (req.get_safety() ? "True" : "False") << "\\ \n";
            req_section << "**Derived:** " << (req.get_derived() ? "True" : "False") << "\\ \n";
            req_section << "**Type:** " << (req.get_type() ? "Functional" : "Non-functional") << "\n";
            req_section << "\n";
            req_section << "**Body:** " << "\n";
            req_section << req.get_body() << "\n";
            req_section << "\n";
            req_section << "**Comments:** " << "\n";
            req_section << req.get_comments() << "\n";
            req_section << "\n";

            switch(req.get_level())
            {
            case LEVEL_SRATS:
            case LEVEL_LLR:
                req_section << "**Linked HLRs:** " << "\n";
                for (auto& id : *(req.get_linked_hlrs()))
                {
                    req_section << id << " | ";
                }
                req_section << "\n";
                break;

            case LEVEL_HLR:
                req_section << "**Linked SRATS:** " << "\n";
                for (auto& id : *(req.get_linked_srats()))
                {
                    req_section << id << " | ";
                }
                req_section << "\n" << "\n";

                req_section << "**Linked LLRs:** " << "\n";
                for (auto& id : *(req.get_linked_llrs()))
                {
                    req_section << id << " | ";
                }
                req_section << "\n";
                break;
            default:
                req_section << "EXPORT ERROR" << "\n";
                break;
            }
            req_section << "\n---\n";
        }

        return req_section.str();
    }

};



