#include <iostream>
#include <thread>
#include <chrono>

#define TIME  150
using namespace std::chrono;
using namespace std::this_thread;

int alphahex(){
    std::string alphabets = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

    for(int i = 0; i < alphabets.size(); i++){
        sleep_for(milliseconds(TIME));
        printf(" %c\n", alphabets[i]);
        printf(" %d\n", alphabets[i]);
    }

    return 0;
}