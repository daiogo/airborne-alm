#include "UI.h"
#include <iostream>

namespace UI
{

    int options_dialog(std::string question, const std::vector<std::string>& options)
    {
        int option = 0;

        // Present options
        std::cout << question << std::endl;
        for (int i = 0; i < options.size(); i++)
        {
            std::cout << i+1 << ". " << options[i] << std::endl;
        }

        // Validate input
        while (!(std::cin >> option) || ((option < 1) || (option > options.size())))
        {
            std::cout << std::endl;
            std::cout << "Invalid option. Select from the numbers above." << std::endl;
            std::cin.clear(); // Reset the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
        }

        // Discard bad input
        std::cin.ignore();

        return option;
    }

    std::string string_dialog(std::string question)
    {
        std::string answer;

        // Present question
        std::cout << question << std::endl;

        // Get answer
        std::getline(std::cin, answer);
        std::cout << std::endl;

        return answer;
    }

}
