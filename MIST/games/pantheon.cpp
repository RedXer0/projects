#include <iostream>
#include <thread>
#include <chrono>
#include "pantheon1.cpp"
#include "pantheon2.cpp"
#include "pantheon3.cpp"

#define TIME  150
using namespace std::chrono;
using namespace std::this_thread;


void ascii_title(int color, std::string ansi);
void dialouge(std::string ansi, int blue);

void pantheon(){
    int colors[12] = {31, 32, 33, 34, 35, 36, 96, 95, 94, 93, 92, 91};
    std::string ansi = "\033[";
    ascii_title(colors[2], ansi);
    dialouge(ansi, colors[8]);
    beginning();
    middle();
    end();
}

void ascii_title(int color, std::string ansi){

    std::string ascii_art[] = {
    "██████   █████  ███    ██ ████████ ██   ██ ███████  ██████  ███    ██ ",
    "██   ██ ██   ██ ████   ██    ██    ██   ██ ██      ██    ██ ████   ██ ",
    "██████  ███████ ██ ██  ██    ██    ███████ █████   ██    ██ ██ ██  ██ ",
    "██      ██   ██ ██  ██ ██    ██    ██   ██ ██      ██    ██ ██  ██ ██ ",
    "██      ██   ██ ██   ████    ██    ██   ██ ███████  ██████  ██   ████ "
    };

    for (int i = 0; i < 5; i++){
        std::cout << ansi << color << "m" << ascii_art[i] << std::endl;
        sleep_for(milliseconds(TIME));
    }
}

void dialouge(std::string ansi, int blue){
    std::string start[] = {
        "Hey kiddo looks like you got yourself into another predicament huh?",
        "Don't worry i'll get you out of here, you just gotta promise to show me your skill in the future."
    };

    for (int i = 0; i < 2; i++){
        sleep_for(milliseconds(TIME));
        std::cout << ansi << blue << "m" << start[i] << std::endl;
    }
}