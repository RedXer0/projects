/*
Mist the terminal assistant.
*/
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


using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

void time_delay();


int main(){
    greetings();
    time_delay();
    int choice;
    list();
    std::cin >> choice;

    switch(choice){
        case 1:
            jokes();
            break;
        case 2:
            system("neofetch --stdout");
            break;
        case 3:
            system("date");
            break;
        case 4:
            make_me();
            break;
        case 5:
            system("code");
            break;
        case 6:
            system("firefox");
            break;
        case 7:
            system("xdg-open https://github.com/");
            break;
        case 8:
            std::cout << "goodbye xero" << std::endl;
            time_delay();
            system("shutdown now");
            break;
        case 9:
            calculator();
            break;
        case 10:
            games();
            break;
        case 11:
            system("sudo apt update && apt upgrade");
            break;
        case 12:
            file_hunter();
            break;
        case 13:
            int extension_name;
            printf("enter extension name: \n");
            std::cin >> extension_name;
            system ("sudo apt install " + extension_name);
            break;
        case 14:
            system("sudo -s");
            break;
        case 15:
            system("exit");
            break;
    }
    printf("need to complete any other tasks? y/n\n");
    char choices;
    std::cin >> choices;
    if (choices == 'y' || choices == 'Y'){
        main();
    } else{exit(0);}
}

void time_delay(){
    sleep_for(2s);
    sleep_until(system_clock::now() + 2s);
}
