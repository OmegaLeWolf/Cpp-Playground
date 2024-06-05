#include <iostream>     // std::cin / std::cout
#include <cstdlib>      // Random
#include <string>       // String type
#include <chrono>       // Timers and stuff
#include <thread>       // Multithreading, sleep

// Creates a welcome function to be executed when verification is complete
int welcome() {

    // Outputting text to terminal
    // Note the usage of \n, which is used to create a new line
    std::cout << "\nWelcome to this hello world program\n";

    return 0;

}

//                                          ---------------------------------
//                                          |     std:cout/cin Breakdown    | 
//                                          ---------------------------------
//      
//                                                        std
//                                  Standard - Represents the standard C++ Library
//      
//                            cout                                                        cin
//       C Out - (C) Standard Output Stream, shows the               C In - (C) Standard Input Stream, receives the
//       data given on the screen via the console                    data given on the screen via the console
//      
//                            <<                                                          ::
//       Insertion operator. Sends the given input to                Namespace connector - Used to identify the 
//       cout to be outputted to the console                         namespace where the function is located, 
//                                                                   namely the std namespace of the C++ library


//Creates a userVerfication function to verify the user
int userVerification() {

    // Initialization of variables
    double result;
    double total;
    int num1;
    int num2;

    // Creation of an array (a variable with more than one value stored within) 
    // of the type string (only string variables can be stored within)
    std::string operands[] = {"+", "-", "*", "/"}; 

    // Creation of an integer value that stores a random value from 0 to 3
    int operandIndex = rand() % (3);

    // Storing a random value from 0 to 20 in the two previously defined variables
    num1 = rand() % 20;
    num2 = rand() % 20;
    
    // Checking if the previously generated randomized value is either 2 OR (||) 3 
    // (used to represent multiplication and division)
    if (operandIndex == 2 || operandIndex == 3) {

        // Storing a random value from 0 to 9 in the two previously defined variables
        // Note: This overwrites the previously stored values
        num1 = rand() % 9;
        num2 = rand() % 9;

    }

    
    // Outputting text to terminal
    // Note the usage of \n, which is used to create a new line
    std::cout << "Before we proceed, we'll start with a verification.\nPlease complete the following exercise:\n\n";

    // Using variables, this outputs the math equation to be solved by the user
    // As an example, let's say num1 = 1, num2 = 2, and the operand is +
    // This would output the following:
    // 1+2 = 
    std::cout << num1 << operands[operandIndex] << num2 << " = ";

    // Receives user inserted value
    std::cin >> total;

    // A switch clause is basically just a gigantic if statement.
    // This reads the value stored in operandIndex
    switch(operandIndex) {
        //If it's 0 then do:
        case 0:
            result = num1 + num2;
            //Exits the switch structure
            break;

        //If it's 1 then do:
        case 1:
            result = num1 - num2;
            break;

        //And so on
        case 2:
            result = num1 * num2;
            break;

        case 3:
            result = num1 / num2;
            break;
        
        //If it's not any of the above values, do the following:
        default:
            result = 0;
            return 2;
            break;
    }

    // Checking if the user's inputted value is equal to the actual result
    if (total == result) {
        std::cout << "Verification complete!\n";
        // Exits the verification function
        return 0;
    }
    else {
        std::cout << "Verfication failed!\n";
        // Exits the verification function with error code 1
        return 1;
    }

    return 0;
}

// Main function, always executed first
int main() {
    std::cout << "Hello world!\n";

    // Another switch, works the same
    // It reads the output of the userVerification function (remember the returns? That's what it reads)
    switch(userVerification()) {
        // If nothing went wrng
        case 0:
            break;
        
        // Following error codes
        case 1:
            std::cout << "Verification failed. Please try again later.\nExiting...";
            // Exits the main function, in turn closing the application
            return 0;
            break;
        case 2:
            std::cout << "Calculation error. Please try again later.\nExiting...";
            return 0;
            break;
        default:
            std::cout << "Something went wrong. Please try again later.\nExiting...";
            return 0;
            break;
    }

    // If all went well it will execute this welcome function
    welcome();

    // Sleeps for 10 seconds
    std::this_thread::sleep(10);


    // Closes the app
    return 0;
}

