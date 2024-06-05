#include <iostream>
#include <string>

// This is the start of a password Manager project.
// Version 1.0.0
// Created by OmegaLeWolf 
// Github: https://github.com/OmegaLeWolf

// Lists available commands
int help() {
    std::cout << "Available Commands:\n"
                 "help | h\n"
                 "\tLists available commands\n"
                 "new | n\n"
                 "\tCreate new password\n"
                 "delete | d\n"
                 "\tDelete a specific password\n"
                 "edit | e\n"
                 "\tEdit a specific password\n"
                 "quit | q\n"
                 "\tQuit program"<<std::endl;

    return 0;

}

//Verifies user input / Command selection
int verifyUserInput(string userInput) {
    enum Options {
        Invalid,
        Help,
        New,
        Delete,
        Edit,
        Quit
    }

    switch (resolveOption(userInput)) {
        case Help:
            return 0;
            break;
        
        case New:
            return 1;
            break;
        
        case Delete:
            return 2;
            break;

        case Edit:
            return 3;
            break;

        case Quit:
            return 4;
            break;

        case Invalid:
            return -1;
            break;

        default:
            return -2;
            break;
    }
}

//Resolves Option
Options resolveOption(string input) {

    // Creates a map of all the options, with string as the user's 
    // input and Option as the option to return
    static const std::map<std::string, Option> optionStrings {
        { "help", Help },
        { "h", Help },
        { "new", New },
        { "n", New },
        { "delete", Delete },
        { "d", Delete },
        { "edit", Edit },
        { "e", Edit },
        { "quit", Quit },
        { "q", Quit }
    };


    // Searches the map for the string stored in input
    auto itr = optionStrings.find(input);
    
    // Iterates through options until the value is equal to the option selected
    if( itr != optionStrings.end() ) {
        // Returns selected option
        return itr->second;
    }
    // If is not found, return invalid
    return Invalid; 
}

//Main function executed by default
int main() {
    
    string userInput;

    //Welcomes user, initialization
    std::cout << "\nWelcome to Omega's password manager!\n";
    help();

    std::cin >> userInput;

    switch(verifyUserInput()) {
        //Help
        case 0:
            break;

        // New
        case 1:
            break;

        // Delete
        case 2:
            break;

        // Edit
        case 3:
            break;

        case 4:
            break;

        //Invalid input
        case -1:
            break;

        // Unknown Error
        case -2:
            break;

    }

} 