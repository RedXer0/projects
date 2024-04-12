#include <iostream>
#include <thread>
#include <chrono>

#define TIME  150
using namespace std::chrono;
using namespace std::this_thread;

void text(int color, std::string ansi);

void end(){
    int colors[12] = {31, 32, 33, 34, 35, 36, 96, 95, 94, 93, 92, 91};
    std::string ansi = "\033[";
    text(colors[8], ansi);
}

void text(int color, std::string ansi){
    std::string text[] = {
        "So you completed the game huh?",
        "Don't worry thats not all i have to offer but for rn it'll have to do.",
        "more content coming soon.",
        "thanks for playing the beta.",
        "yk you could try the other 2 games too."
    };

    for (int i = 0; i < 5; i++){
        sleep_for(milliseconds(TIME));
        std::cout << ansi << color << "m" << text[i] << std::endl;
    }
}