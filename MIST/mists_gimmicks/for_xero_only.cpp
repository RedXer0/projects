#include <iostream>
#include <thread>
#include <chrono>

#define TIME  150
using namespace std::chrono;
using namespace std::this_thread;

int for_xero_only(){
    std::string ansi = "\033[35m";
    std::string heatr[] = {
"              ******       ******",
"            **********   **********",
"          ************* *************",
"         *****************************",
"         *****************************",
"         *****************************",
"          ***************************",
"            ***********************",
"              *******************",
"                ***************",
"                  ***********",
"                    *******",
"                      ***",
"                       *",
};

    for(int i = 0; i < 14; i++){
        sleep_for(milliseconds(TIME));
        std::cout << ansi << heatr[i] << std::endl;
    }

    printf("thanks xero\n");
    return 0;
}