#pragma once

#include "AirborneSystem.h"
#include "DAO.h"
#include <vector>
#include <variant>

using DocumentPtr = std::variant<CRS*, SRD*, SDD*>;

typedef enum {
    SYS = 1,
    DOC = 2,
    REQ = 3,
    EXIT = 4,
} UIState;

class App {
private:
    std::vector<AirborneSystem> system_list;
    AirborneSystem *selected_context;
    DocumentPtr selected_document;
    UIState ui_state;
    //DAO dao;

public:
    App();
    void load_database();
    void save_database();
    void run();
    UIState select_system();
    UIState select_document();
    UIState select_action();
    void create_requirement();
    void display_requirement();
    void edit_requirement();
    void delete_requirement();
    void link_requirements();
    void edit_document();
    void export_document();
    void create_system();
    void present_edit_options(Requirement *req_ptr);
    void print_requirement(Requirement *req_ptr);
};
