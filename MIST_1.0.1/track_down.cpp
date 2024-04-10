#include <iostream>


void accurate_file_search();
void search_by_extension();
void search_type();

// main function for mist.cpp
int file_hunter(){
    int choice;
    search_type(); // calls search_type function
    std::cin >> choice; // user input

    // loops through the switch loop based on which number is inputted
    switch(choice){
        case 1:
            accurate_file_search();
            break;
        case 2:
             search_by_extension();
             break;
        case 3:
            exit(0);
            break;
        default:
            std::cout << "Invalid choice" << std::endl; // basically exits the program.
            break;
    }
    return 0;
}

// search_type cunction.
void search_type(){
    int color = 31; // color

    // search list array
    std::string search_types[] = {
    "1. Accurate File Search.",
    "2. By Extension File Search. ",
    "3. Exit"
    };

    for (int i=0; i<3; i++){ // loops through array until the entire array is printed out.
        std::cout << "\033[" << color << "m" << search_types[i] << "\033" << std::endl;
        printf("||--------------------------\n"); // seperator lol
    }
}

// accurate file search function.
// this allows you to find any file within any directory by just the name and file extension.
void accurate_file_search(){
    std::string file_extension;
    std::string file_name;
    int user_input;
    printf(" insert file extension: \n");
    std::cin >> file_extension; // file extension user input
    printf("does the file have a name: 0=no 1=yes\n");
    std::cin >> user_input; // response protocol
    switch(user_input){ // switches through loop depending on which number you insert
        case 0:
            break; // breaks if you insert 0
        case 1:
            printf("enter file name: \n");
            std::cin >> file_name; // if you picked 1 you insert the name of the file
            break;
        default:
        std::cout << "Invalid choice" << std::endl; // otherwise it does nothing
        break;
    }

    // system file search command DONT CHANGE THIS OK THIS ALLOWS YOU TO SEARCH FOR FILES!!!
    std::string command = "find /  2>/dev/null ! -readable -prune -o -name \'" + file_name + "." + file_extension + "\' -print -quit";
    system(command.c_str()); // prints the string data into the system then runs it
    
}


// this searches for all files with the given extension type.
void search_by_extension(){
    std::string file_extension;
    printf("insert file extension: \n");
    std::cin >> file_extension; // user input.

    // DO NOT CHANGE!! this is the string file that allows you to search for files by extension.
    std::string command = "find / 2>/dev/null ! -readable -prune -o -name \"*." + file_extension + "\"" + " -print";

    system(command.c_str()); // inputs the command string into the system.
}
