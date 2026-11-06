#include <iostream>
#include <cstdlib>
#include "App.h"
#include "Requirement.h"
#include "UI.h"
#include "CRS.h"

App::App()
{
    // Start selecting document context
    ui_state = SYS;

    //load_database();

    //temp
    AirborneSystem as1("Landing Gear", "LG", 'B');
    AirborneSystem as2("Motor", "FADEC", 'A');
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
    int option = 0;
    UIState return_state = EXIT;
    std::vector<std::string> system_names;

    // Print header
    system("cls");
    std::cout << "---Select System---" << std::endl;

    // Aggregate the system names
    for (int i = 0; i < system_list.size(); i++)
    {
        system_names.push_back(system_list.at(i).get_name());
    }
    system_names.push_back("Create new system");
    system_names.push_back("Exit");

    // Run dialog
    option = UI::options_dialog("Select a system context to work on: ",
                                system_names);

    // Decide action upon input
    if (option == system_list.size() + 1)
    {
        // Create new AirborneSystem
        create_system();
        // load to db
        return_state = SYS;
    }
    else if (option == system_list.size() + 2)
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
            selected_document = selected_context->get_srd();//std::any_cast<SRD*>(selected_context->get_document_ptr(DOC_SRD));
            break;
        case DOC_SDD:
            selected_document = selected_context->get_sdd();//std::any_cast<SDD*>(selected_context->get_document_ptr(DOC_SDD));
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
    std::string title = std::visit([](const auto& doc) -> std::string { return doc->get_title(); }, selected_document);
    std::cout << "Document: " << title << std::endl;

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
        display_requirement();
        break;
    case 3:
        edit_requirement();
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
    ReqLevel level;
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

    //selected_document->create_requirement(Requirement(rid, body, comments, type, LEVEL_UNDEF, safety, derived));
    std::visit([=](const auto& doc) { return doc->create_requirement(Requirement(rid, body, comments, type, LEVEL_UNDEF, safety, derived)); }, selected_document);

    system("pause");

    /*
    switch (selected_document)
    {
    case DOC_CRS:
        selected_context->get_crs()->add_requirement(SRATS(rid, body, comments, type, LEVEL_SRATS, safety, derived));
        break;
    case DOC_SRD:
        selected_context->get_srd()->add_requirement(HLR(rid, body, comments, type, LEVEL_HLR, safety, derived));
        break;
    case DOC_SDD:
        selected_context->get_sdd()->add_requirement(LLR(rid, body, comments, type, LEVEL_LLR, safety, derived));
        break;
    }
    */
}

void App::display_requirement()
{
    int option = 0;
    std::string id;
    Requirement *req_ptr;

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

        //req_ptr = selected_document->read_requirement(id);
        req_ptr = std::visit([=](const auto& doc) -> Requirement* { return doc->read_requirement(id); }, selected_document);

        if (req_ptr != nullptr)
        {
            std::cout << "ID: " << req_ptr->get_rid() << std::endl;
            std::cout << "Safety: " << req_ptr->get_safety() << std::endl;
            std::cout << "Derived: " << req_ptr->get_derived() << std::endl;
            std::cout << "Type: " << (req_ptr->get_type() ? "functional" : "non-functional") << std::endl;
            std::cout << std::endl;
            std::cout << "Description: " << std::endl;
            std::cout << req_ptr->get_body() << std::endl;
            std::cout << std::endl;
            std::cout << "Comments: " << std::endl;
            std::cout << req_ptr->get_comments() << std::endl;
            std::cout << std::endl;
            std::cout << "Linked requirements: " << std::endl;
            std::cout << "TBD" << std::endl;
        }
        else
        {
            std::cout << "No requirements with this ID were found in this document." << std::endl;
        }

        system("pause");

    }
    else if (option == 2)
    {
        //selected_context->get_crs()->print_requirements_list();
        //selected_document->get
    }
    else
    {
        // Do nothing and exit
    }
}

void App::edit_requirement()
{
    system("cls");
    std::cout << "---Edit Requirement---" << std::endl;
    // search requirement
    // ask what needs to be edited
    // edit the selected field
    // update db
}

void App::delete_requirement()
{
    std::string id;

    // Print header
    system("cls");
    std::cout << "---Delete Requirement---" << std::endl;

    id = UI::string_dialog("Type the requirement ID with no spaces: ");

//    selected_document->delete_requirement(id);

    system("pause");
}

void App::link_requirements()
{
    system("cls");
    std::cout << "---Link Requirements---" << std::endl;
    // find requirement
    // prompt what requirements will be linked
    // update db
}

void App::edit_document()
{
    system("cls");
    std::cout << "---Edit Document---" << std::endl;


}

void App::export_document()
{
    system("cls");
    std::cout << "---Export Document---" << std::endl;

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

    //as = new AirborneSystem(name, id_prefix, dal);
    AirborneSystem as(name, id_prefix, dal);
    system_list.push_back(as);
}

