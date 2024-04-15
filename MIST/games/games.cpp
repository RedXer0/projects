#include <iostream>
#include <thread>
#include <chrono>

#define TIME  150
using namespace std::chrono;
using namespace std::this_thread;

void games_list(int colors, std::string ansi);

void prompt(){
     int colors[12] = {31, 32, 33, 34, 35, 36, 96, 95, 94, 93, 92, 91};
    std::string ansi = "\033[";

    std::cout << ansi << colors[5] << "m" << "WELCOME TO MISTS GAMES LOUNGE" << std::endl;
    sleep_for(milliseconds(TIME+100));
    printf("which game would you like to play?\n");
    sleep_for(milliseconds(TIME));
    games_list(colors[2], ansi);
}

void games_list(int colors, std::string ansi){
    std::string games_list[] = {
        "1. slot machine",
        "2. number guessing game",
        "3. tic-tac-toe",
    };

    for (int i = 0; i < 3; i++){
        std::cout << ansi << colors << "m" << games_list[i] << std::endl;
        sleep_for(milliseconds(TIME));
    }
}