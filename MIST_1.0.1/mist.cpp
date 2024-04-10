/*
Mist the terminal assistant.
*/

// current libraries
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <ctime>
#include <string>
#include <random>
#include <istream>
#include <unistd.h>
#include <cstdlib>
#include "games.cpp"
#include "tasks.cpp"
#include "calculator.cpp"
#include "jokes.cpp"
#include "greetings.cpp"
#include "track_down.cpp"
#include "make_files.cpp"


int main(){
    std::string username;
    greetings(); // grabs function from greetings.cpp
    sleep(2); // time delay (2 seconds)
    int choice;
    list(); // calls list function from tasks.cpp
    std::cin >> choice; // user input
    printf("enter your username: \n");
    std::cin >> username; // gets your username then converts it to a string.

    switch(choice){
        case 1:
            jokes(); // calls jokes function from jokes.cpp
            break;
        case 2:
            system("neofetch --stdout"); // activates system command neofetch
            break;
        case 3:
            system("date"); // activates date system command
            break;
        case 4:
            make_me(); // calls make_me function from make_files.cpp
            break;
        case 5:
            system("code"); // activates code system command(if vscode was installed)
            break;
        case 6:
            system("firefox"); // runs firefox
            break;
        case 7:
            system("xdg-open https://github.com/"); // opens github
            break;
        case 8:
            std::cout << "goodbye" << username << std::endl;
            sleep(3); // sleeps for 3 seconds
            system("shutdown now"); // sutsdown system
            break;
        case 9:
            calculator(); // activates calculator function from calculator.cpp
            break;
        case 10:
            games(); // activates game function from games.cpp
            break;
        case 11:
            system("sudo apt update && apt upgrade"); // activates update protocol
            break;
        case 12:
            file_hunter(); // activates file_hunter function from track_down.cpp
            break;
        case 13:
            int downloadble_content_name; 
            printf("enter downloadble content name: \n");
            std::cin >> downloadble_content_name; // takes user input
            system ("sudo apt install " + downloadble_content_name); // calls system install command along with user input
            break;
        case 14:
            system("sudo -s"); // activates super user
            break;
        case 15:
            break; // breaks out
    }

    // lets you repeat the switch commands or exit.
    printf("need to complete any other tasks? y/n\n");
    char choices;
    std::cin >> choices;
    if (choices == 'y' || choices == 'Y'){
        main();
    } else{exit(0);}
    
    return 0;
}
