#pragma once

#include <string>
#include <vector>

namespace UI
{
    int options_dialog(std::string question, const std::vector<std::string>& options);
    std::string string_dialog(std::string question);
}
