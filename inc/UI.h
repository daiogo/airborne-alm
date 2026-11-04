#include <iostream>
#include <vector>

class UI {
private:
    // No need

public:
    static int options_dialog(std::string question, const std::vector<std::string>& options);
    static std::string string_dialog(std::string question);
};
