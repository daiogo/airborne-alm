#pragma once

#include "AirborneSystem.h"
#include <vector>

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
    Document *selected_document;
    UIState ui_state;

public:
    App();
    void load_database();
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
};
