#include <iostream>
#include <string>
#include <map>
#include "newPassword.h"

int newPassword(); 
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

enum class Options {
        Invalid,
        Help,
        New,
        Delete,
        Edit,
        Quit
};

//Resolves Option
Options resolveOption(std::string input) {

    // Creates a map of all the options, with string as the user's 
    // input and Option as the option to return
    static const std::map<std::string, Options> optionStrings {
        { "help", Options::Help },
        { "h", Options::Help },
        { "new",Options::New },
        { "n", Options::New },
        { "delete", Options::Delete },
        { "d", Options::Delete },
        { "edit", Options::Edit },
        { "e", Options::Edit },
        { "quit", Options::Quit },
        { "q", Options::Quit }
    };


    // Searches the map for the string stored in input
    auto itr = optionStrings.find(input);
    
    // Iterates through options until the value is equal to the option selected
    if( itr != optionStrings.end() ) {
        // Returns selected option
        return itr->second;
    }
    // If is not found, return invalid
    return Options::Invalid; 
}

//Verifies user input / Command selection
int verifyUserInput(std::string userInput) {

    switch (resolveOption(userInput)) {
        case Options::Help:
            return 0;
            break;
        
        case Options::New:
            return 1;
            break;
        
        case Options::Delete:
            return 2;
            break;

        case Options::Edit:
            return 3;
            break;

        case Options::Quit:
            return 4;
            break;

        case Options::Invalid:
            return -1;
            break;

        default:
            return -2;
            break;
    }
}

//Main function executed by default
int main() {
    //Inititialization
    std::string userInput;

    //Welcomes user, initialization
    std::cout << "\nWelcome to Omega's password manager!\n";
    help();

    std::cin >> userInput;

    switch(verifyUserInput(userInput)) {
        //Help
        case 0:
            help();
            break;

        // New
        case 1:
            newPassword();
            break;

        // Delete
        case 2:
            std::cout << "Delete";
            break;

        // Edit
        case 3:
            std::cout << "Edit";
            break;

        //Quit
        case 4:
            std::cout << "Quit";
            return 0;
            break;

        //Invalid input
        case -1:
            std::cout << "Invalid Input";
            break;

        // Unknown Error
        case -2:
            std::cout << "Unknown error";
            break;

        default:
            std::cout << "Oops! Something went wrong.";
            break;
    }

    return 0;

} 