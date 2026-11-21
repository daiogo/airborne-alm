#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "App.h"
#include "Requirement.h"
#include "UI.h"

App::App()
{
    // Start selecting document context
    ui_state = SYS;

    // Init and load database
    //dao.init();
    //dao.load();

    //temp
    AirborneSystem as1("Landing Gear", "LG", 'B');
    AirborneSystem as2("Motor", "FADEC", 'A');

    as2.get_crs()->add_requirement(Requirement("FADEC-1","test1","meh",NON_FUNCTIONAL,false,false));
    as2.get_crs()->add_requirement(Requirement("FADEC-2","test2","meh",FUNCTIONAL,false,false));
    as2.get_crs()->add_requirement(Requirement("FADEC-3","test3","meh",NON_FUNCTIONAL,false,false));
    as2.get_srd()->add_requirement(Requirement("FADEC-4","test4","meh",FUNCTIONAL,false,false));
    as2.get_srd()->add_requirement(Requirement("FADEC-5","test5","meh",NON_FUNCTIONAL,false,false));
    as2.get_srd()->add_requirement(Requirement("FADEC-6","test6","meh",FUNCTIONAL,false,false));
    as2.get_sdd()->add_requirement(Requirement("FADEC-7","test7","meh",NON_FUNCTIONAL,false,false));
    as2.get_sdd()->add_requirement(Requirement("FADEC-8","test8","meh",FUNCTIONAL,false,false));
    as2.get_sdd()->add_requirement(Requirement("FADEC-9","test9","meh",NON_FUNCTIONAL,false,false));

    system_list.push_back(as1);
    system_list.push_back(as2);
}

void App::load_database()
{
    std::cout << "load database" << std::endl;
}

void App::run()
{
    do {
        switch (ui_state)
        {
        case SYS:
            std::cout << "---Select System---" << std::endl;
            ui_state = select_system();
            break;
        case DOC:
            std::cout << "---Select Document---" << std::endl;
            ui_state = select_document();
            break;
        case REQ:
            std::cout << "---Select ACTION---" << std::endl;
            ui_state = select_action();
            break;
        default:
            break;
        }
    } while(ui_state != EXIT);
}

UIState App::select_system()
{
    long long unsigned int option = 0;
    UIState return_state = EXIT;
    std::vector<std::string> system_names;

    // Print header
    system("cls");
    std::cout << "---Select System---" << std::endl;

    // Aggregate the system names
    for (long long unsigned int i = 0; i < system_list.size(); i++)
    {
        system_names.push_back(system_list.at(i).get_name());
    }
    system_names.push_back("Create new system");
    system_names.push_back("Exit");

    // Run dialog
    option = UI::options_dialog("Select a system context to work on: ",
                                system_names);

    // Decide action upon input
    if (option == system_list.size() + 1ULL)
    {
        // Create new AirborneSystem
        create_system();
        // load to db
        return_state = SYS;
    }
    else if (option == system_list.size() + 2ULL)
    {
        std::cout << "Exiting..." << std::endl;
        // run check to save?
        return_state = EXIT;
    }
    else
    {
        std::cout << "Adding pointer: " << option << std::endl;
        selected_context = &system_list.at(option - 1);
        return_state = DOC;
    }

    return return_state;
}

UIState App::select_document()
{
    int option = 0;
    UIState return_state = EXIT;

    // Print header
    system("cls");
    std::cout << "---Select Document---" << std::endl;
    std::cout << "System: " << selected_context->get_name() << std::endl;

    // Run dialog
    option = UI::options_dialog("Select a document to work on: ",
                                {"CRS", "SRD", "SDD", "Choose another context"});

    // Decide action upon input
    if (option == 4)
    {
        // Go back
        return_state = SYS;
    }
    else
    {
        switch ((DocType)option)
        {
        case DOC_CRS:
            selected_document = selected_context->get_crs();
            break;
        case DOC_SRD:
            selected_document = selected_context->get_srd();
            break;
        case DOC_SDD:
            selected_document = selected_context->get_sdd();
            break;
        }

        return_state = REQ;
    }

    return return_state;
}

UIState App::select_action()
{
    int option = 0;
    UIState return_state = REQ;

    // Print header
    system("cls");
    std::cout << "---Select Action---" << std::endl;
    std::cout << "System: " << selected_context->get_name() << std::endl;
    std::cout << "Document: " << selected_document->get_title() << std::endl;

    // Run dialog
    option = UI::options_dialog("Select a document to work on: ",
                                {"Create requirement",
                                 "Display requirement",
                                 "Edit requirement",
                                 "Delete requirement",
                                 "Link requirements",
                                 "Edit document",
                                 "Export document",
                                 "Choose another document"});

    // Decide action upon input
    switch (option)
    {
    case 1:
        create_requirement();
        break;
    case 2:
        read_requirement();
        break;
    case 3:
        update_requirement();
        break;
    case 4:
        delete_requirement();
        break;
    case 5:
        link_requirements();
        break;
    case 6:
        edit_document();
        break;
    case 7:
        export_document();
        break;
    case 8:
        return_state = DOC;
        break;
    default:
        std::cout << "Invalid option. Try again." << std::endl;
        break;
    }

    return return_state;
}

void App::create_requirement()
{
    int option = 0;
    std::string rid = selected_context->get_id_prefix() + "-" + selected_context->get_id_count();
    std::string body;
    std::string comments;
    ReqType type;
    bool safety;
    bool derived;

    system("cls");
    std::cout << "---Create Requirement---" << std::endl;

    body = UI::string_dialog("Write the requirement body below: ");

    comments = UI::string_dialog("Write any relevant comments (e.g. traceability, derived or safety justification): ");

    option = UI::options_dialog("Is it a safety requirement?", {"Yes", "No"});
    safety = (option == 1) ? true : false;

    option = UI::options_dialog("Is it a derived requirement?", {"Yes", "No"});
    derived = (option == 1) ? true : false;

    option = UI::options_dialog("What type of requirement is it?", {"Functional", "Non-functional"});
    type = (option == 1) ? FUNCTIONAL : NON_FUNCTIONAL;

    selected_document->add_requirement(Requirement(rid, body, comments, type, safety, derived));

    system("pause");
}

void App::read_requirement()
{
    int option = 0;
    std::string id;
    Requirement *req_ptr;
    std::list<Requirement*> requirements_ptr = selected_document->get_requirements();

    // Print header
    system("cls");
    std::cout << "---Display Requirement---" << std::endl;

    // Fetch from db
    // TBD

    // Run dialog
    option = UI::options_dialog("Select an option: ",
                                {"Search requirement by ID",
                                 "Print all requirements",
                                 "Exit"});

    // Decide action upon input
    if (option == 1)
    {
        id = UI::string_dialog("Type the requirement ID with no spaces: ");

        req_ptr = selected_document->get_requirement_ptr(id);

        if (req_ptr != nullptr)
        {
            print_requirement(req_ptr);
        }
        else
        {
            std::cout << "No requirements with this ID were found in this document." << std::endl;
        }

    }
    else if (option == 2)
    {
        if (requirements_ptr.size() > 0)
        {
            for (auto* req : requirements_ptr)
            {
                print_requirement(req);
                std::cout << std::endl << "------------------------------------" << std::endl;
            }
        }
        else
        {
            std::cout << "This document currently has no requirements" << std::endl;
        }
    }
    else
    {
        // Do nothing and exit
    }

    system("pause");
}

void App::update_requirement()
{
    std::string id;
    Requirement *req_ptr;

    // Print header
    system("cls");
    std::cout << "---Edit Requirement---" << std::endl;
    // search requirement
    // ask what needs to be edited
    // edit the selected field
    // update db

    id = UI::string_dialog("Type the requirement ID with no spaces: ");

    req_ptr = selected_document->get_requirement_ptr(id);

    if (req_ptr != nullptr)
    {
        system("cls");
        std::cout << "Your current requirement: " << std::endl;
        print_requirement(req_ptr);

        std::cout << std::endl << "-------------------" << std::endl << std::endl;

        present_req_edit_options(req_ptr);

        std::cout << std::endl << "-------------------" << std::endl << std::endl;

        std::cout << "Your new requirement: " << std::endl;
        print_requirement(req_ptr);
    }
    else
    {
        std::cout << "No requirements with this ID were found in this document." << std::endl;
    }

    system("pause");
}

void App::delete_requirement()
{
    std::string id;
    int option = 0;
    Requirement *req_ptr;
    bool success = false;

    // Print header
    system("cls");
    std::cout << "---Delete Requirement---" << std::endl;

    id = UI::string_dialog("Type the requirement ID with no spaces: ");

    req_ptr = selected_document->get_requirement_ptr(id);

    if (req_ptr != nullptr)
    {
        print_requirement(req_ptr);

        option = UI::options_dialog("Do you really wish to delete this requirement?", {"Yes", "No"});

        if (option == 1)
        {
            success = selected_document->delete_requirement(id);
            std::cout << (success ? "Requirement deleted sucessfully" : "Removal failed") << std::endl << std::endl;
        }
    }
    else
    {
        std::cout << "No requirements with this ID were found in this document." << std::endl;
    }

    system("pause");
}

void App::link_requirements()
{
    bool is_possible = false;
    std::string primary_id;
    std::string secondary_id;
    Requirement *primary_req_ptr = nullptr;
    Requirement *secondary_req_ptr = nullptr;
    std::list<std::string> *generic_id_list_ptr = nullptr;
    std::list<std::string> all_linked_reqs = {};
    std::list<std::string> all_linkable_reqs = {};
    std::list<std::string> all_possible_links = {};
    ReqLevel secondary_req_level = LEVEL_UNDEF;

    // Print header
    system("cls");
    std::cout << "---Link Requirements---" << std::endl;

    primary_id = UI::string_dialog("Type the ID of the requirement you wish to link to others: ");

    primary_req_ptr = selected_document->get_requirement_ptr(primary_id);

    if (primary_req_ptr != nullptr)
    {
        system("cls");
        std::cout << "Your current requirement: " << std::endl;
        print_requirement(primary_req_ptr);

        std::cout << std::endl << "-------------------" << std::endl << std::endl;

        // Fetch all requirements possible to link with this one
        switch (selected_document->doc_type)
        {
        case DOC_CRS:
        case DOC_SDD:
            // SRATS and LLRs can only be linked to HLRs, so they reuse this function

            // Find all linked HLRs
            generic_id_list_ptr = primary_req_ptr->get_linked_hlrs();
            all_linked_reqs.insert(all_linked_reqs.end(), generic_id_list_ptr->begin(), generic_id_list_ptr->end());

            // Find all linkable HLRs
            generic_id_list_ptr = selected_context->get_srd()->get_requirement_ids();
            all_linkable_reqs.insert(all_linkable_reqs.end(), generic_id_list_ptr->begin(), generic_id_list_ptr->end());
            break;
        case DOC_SRD:
            // Find all linked LLRs
            generic_id_list_ptr = primary_req_ptr->get_linked_llrs();
            all_linked_reqs.insert(all_linked_reqs.end(), generic_id_list_ptr->begin(), generic_id_list_ptr->end());\

            // Find all linked SRATS
            generic_id_list_ptr = primary_req_ptr->get_linked_srats();
            all_linked_reqs.insert(all_linked_reqs.end(), generic_id_list_ptr->begin(), generic_id_list_ptr->end());

            // Find all linkable LLRs
            generic_id_list_ptr = selected_context->get_sdd()->get_requirement_ids();
            all_linkable_reqs.insert(all_linkable_reqs.end(), generic_id_list_ptr->begin(), generic_id_list_ptr->end());

            // Find all linkable SRATS
            generic_id_list_ptr = selected_context->get_crs()->get_requirement_ids();
            all_linkable_reqs.insert(all_linkable_reqs.end(), generic_id_list_ptr->begin(), generic_id_list_ptr->end());
            break;
        }

        // Only add to all_possible_links the IDs that are not already linked
        if (!all_linked_reqs.empty())
        {
            // set_difference only works if lists are sorted
            all_linkable_reqs.sort();
            all_linked_reqs.sort();
            std::set_difference(
                all_linkable_reqs.begin(), all_linkable_reqs.end(),
                all_linked_reqs.begin(), all_linked_reqs.end(),
                std::inserter(all_possible_links, all_possible_links.begin())
            );
        }
        else
        {
            all_possible_links = all_linkable_reqs;
        }

        std::cout << "Here is the possible requirements you can link to: " << std::endl;
        for (auto& possible_id : all_possible_links)
        {
            std::cout << possible_id << " | ";
        }
        std::cout << std::endl;

        secondary_id = UI::string_dialog("Type the ID you wish to link to " + primary_id + ": ");

        // Check if decomposition is valid
        is_possible = (std::ranges::find(all_possible_links, secondary_id) != all_possible_links.end());
        if (is_possible)
        {
            secondary_req_ptr = selected_context->get_crs()->get_requirement_ptr(secondary_id);
            if (secondary_req_ptr == nullptr)
            {
                secondary_req_ptr = selected_context->get_srd()->get_requirement_ptr(secondary_id);
                if (secondary_req_ptr == nullptr)
                {
                    secondary_req_ptr = selected_context->get_sdd()->get_requirement_ptr(secondary_id);
                }
            }

            // Link requirements both ways
            switch (selected_document->doc_type)
            {
            case DOC_CRS:
                primary_req_ptr->get_linked_hlrs()->push_back(secondary_id);
                secondary_req_ptr->get_linked_srats()->push_back(primary_id);
                break;
            case DOC_SRD:
                if (secondary_req_ptr->get_level() == LEVEL_SRATS)
                {
                    primary_req_ptr->get_linked_srats()->push_back(secondary_id);
                }
                else if (secondary_req_ptr->get_level() == LEVEL_LLR)
                {
                    primary_req_ptr->get_linked_llrs()->push_back(secondary_id);
                }
                secondary_req_ptr->get_linked_hlrs()->push_back(primary_id);
                break;
            case DOC_SDD:
                primary_req_ptr->get_linked_hlrs()->push_back(secondary_id);
                secondary_req_ptr->get_linked_llrs()->push_back(primary_id);
                break;
            }
        }
        else
        {
            std::cout << "It was not possible to link " << primary_id << " with " << secondary_id << std::endl;
            std::cout << "Please check if:" << std::endl;
            std::cout << "- this requirement duo has a valid decomposition link (e.g. cannot link SRATS with LLRs)" << std::endl;
            std::cout << "- this requirement ID has a typo or invalid character such as space" << std::endl;
            std::cout << "- this requirement is already linked" << std::endl;
            std::cout << "- this requirement does not exist" << std::endl;
        }
    }
    else
    {
        std::cout << "No requirements with this ID were found in this document." << std::endl;
    }

    system("pause");
}

void App::edit_document()
{
    int option = 0;
    bool done = false;
    std::string new_value;
    std::string overview_section_name;
    std::vector<std::string> options = {"Title",
                                        "Purpose",
                                        "Scope",
                                        "Referenced Documents",
                                        "CUSTOM",
                                        "Acronyms",
                                        "Appendix",
                                        "Exit"};

    // Print header
    system("cls");
    std::cout << "---Edit Document---" << std::endl;

    // Define custom sections by doc type
    switch (selected_document->doc_type)
    {
    case DOC_CRS:
        overview_section_name = "System Overview";
        options[4] = overview_section_name;
        break;
    case DOC_SRD:
        overview_section_name = "Software Overview";
        options[4] = overview_section_name;
        break;
    case DOC_SDD:
        overview_section_name = "Design Overview";
        options[4] = overview_section_name;
        break;
    }

    while(!done)
    {
        // Run dialog
        option = UI::options_dialog("What section do you wish to edit?", options);

        // Decide action upon input
        switch (option)
        {
        case 1:
            std::cout << "Your current " << options[option+1] << " is: " << std::endl;
            std::cout << selected_document->get_title() << std::endl;
            std::cout << std::endl;

            new_value = UI::string_dialog("Type the new " + options[option+1] + ": ");
            selected_document->set_title(new_value);
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Your current " << options[option+1] << " is: " << std::endl;
            std::cout << selected_document->get_purpose() << std::endl;
            std::cout << std::endl;

            new_value = UI::string_dialog("Type the new " + options[option+1] + ": ");
            selected_document->set_purpose(new_value);
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Your current " << options[option+1] << " is: " << std::endl;
            std::cout << selected_document->get_scope() << std::endl;
            std::cout << std::endl;

            new_value = UI::string_dialog("Type the new " + options[option+1] + ": ");
            selected_document->set_scope(new_value);
            std::cout << std::endl;
            break;
        case 4:
            std::cout << "Your current " << options[option+1] << " is: " << std::endl;
            std::cout << selected_document->get_referenced_docs() << std::endl;
            std::cout << std::endl;

            new_value = UI::string_dialog("Type the new " + options[option+1] + ": ");
            selected_document->set_referenced_docs(new_value);
            std::cout << std::endl;
            break;
        case 5:
            //present_doc_edit_options(&selected_document->get, &selected_document->set_);
            break;
        case 6:
            std::cout << "Your current " << options[option+1] << " is: " << std::endl;
            std::cout << selected_document->get_acronyms() << std::endl;
            std::cout << std::endl;

            new_value = UI::string_dialog("Type the new " + options[option+1] + ": ");
            selected_document->set_acronyms(new_value);
            std::cout << std::endl;
            break;
        case 7:
            std::cout << "Your current " << options[option+1] << " is: " << std::endl;
            std::cout << selected_document->get_appendix() << std::endl;
            std::cout << std::endl;

            new_value = UI::string_dialog("Type the new " + options[option+1] + ": ");
            selected_document->set_appendix(new_value);
            std::cout << std::endl;
            break;
        case 8:
            done = true;
            break;
        default:
            std::cout << "Invalid option. Try again." << std::endl;
            break;
        }
    }

    std::cout << std::endl;
    system("pause");
}

void App::export_document()
{
    // Print header
    system("cls");
    std::cout << "---Export Document---" << std::endl;

    std::cout << selected_document->export_document() << std::endl;

    system("pause");
}

void App::create_system()
{
    std::string name;
    std::string id_prefix;
    char dal;

    system("cls");
    std::cout << "---Create system---" << std::endl;
    std::cout << "What is the name of this system?" << std::endl;
    std::getline(std::cin, name);
    std::cout << std::endl;

    std::cout << "What prefix the requirements of this system will use?" << std::endl;
    std::getline(std::cin, id_prefix);
    std::cout << std::endl;

    std::cout << "What is the DAL of this system?" << std::endl;
    std::cin >> dal;
    std::cin.ignore();
    std::cout << std::endl;

    AirborneSystem as(name, id_prefix, dal);
    system_list.push_back(as);
}

void App::present_req_edit_options(Requirement *req_ptr)
{
    bool done = false;
    int option = 0;
    std::string body;
    std::string comments;
    ReqType type;
    bool safety;
    bool derived;

    while(!done)
    {

        option = UI::options_dialog("What field do you wish to edit?",
                                    {"Body",
                                     "Comments",
                                     "Type",
                                     "Safety",
                                     "Derived",
                                     "Exit"});

        // Decide action upon input
        switch (option)
        {
        case 1:
            body = UI::string_dialog("New body: ");
            req_ptr->set_body(body);
            break;
        case 2:
            comments = UI::string_dialog("New comments: ");
            req_ptr->set_comments(comments);
            break;
        case 3:
            option = UI::options_dialog("New requirement type: ", {"Functional", "Non-functional"});
            type = (option == 1) ? FUNCTIONAL : NON_FUNCTIONAL;
            req_ptr->set_type(type);
            break;
        case 4:
            option = UI::options_dialog("New safety flag: ", {"True", "False"});
            safety = (option == 1) ? true : false;
            req_ptr->set_safety(safety);
            break;
        case 5:
            option = UI::options_dialog("New derived flag: ", {"True", "False"});
            derived = (option == 1) ? true : false;
            req_ptr->set_derived(derived);
            break;
        case 6:
            done = true;
            break;
        default:
            std::cout << "Invalid option. Try again." << std::endl;
            break;
        }
    }

    std::cout << std::endl;
}

void App::print_requirement(Requirement *req_ptr)
{
    std::cout << "ID: " << req_ptr->get_rid() << std::endl;
    std::cout << "Safety: " << (req_ptr->get_safety() ? "True" : "False") << std::endl;
    std::cout << "Derived: " << (req_ptr->get_derived() ? "True" : "False") << std::endl;
    std::cout << "Type: " << (req_ptr->get_type() ? "Functional" : "Non-functional") << std::endl;
    std::cout << std::endl;
    std::cout << "Body: " << std::endl;
    std::cout << req_ptr->get_body() << std::endl;
    std::cout << std::endl;
    std::cout << "Comments: " << std::endl;
    std::cout << req_ptr->get_comments() << std::endl;
    std::cout << std::endl;

    switch(req_ptr->get_level())
    {
    case LEVEL_SRATS:
    case LEVEL_LLR:
        std::cout << "Linked HLRs: " << std::endl;
        for (auto& id : *(req_ptr->get_linked_hlrs()))
        {
            std::cout << id << " | ";
        }
        std::cout << std::endl;
        break;
    case LEVEL_HLR:
        std::cout << "Linked LLRs: " << std::endl;
        for (auto& id : *(req_ptr->get_linked_llrs()))
        {
            std::cout << id << " | ";
        }
        std::cout << std::endl << std::endl;

        std::cout << "Linked SRATS: " << std::endl;
        for (auto& id : *(req_ptr->get_linked_srats()))
        {
            std::cout << id << " | ";
        }
        std::cout << std::endl;
        break;
    }
    //std::cout << std::endl;
}

