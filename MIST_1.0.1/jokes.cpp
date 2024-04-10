#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;


void jokes();
void time_delay_A();
void jokes(){
    srand(time(NULL));
    std::ifstream file("/home/xero/Documents/c++/MIST_1.0.1/JOKES_FOLDER/jokes.txt");
    std::ifstream file2("/home/xero/Documents/c++/MIST_1.0.1/JOKES_FOLDER/punchlines.txt");
    if(file.is_open()){
        std::string jokes[7];
        std::string punchlines[7];
        for(int i=0; i<7; i++){
            file >> jokes[i];
            file2 >> punchlines[i]; 
        }

        int random = rand() % 7;
        int random_colors = rand() % 6;
        int color[] = {31, 32, 33, 34, 35, 36,};
        int c_r_c = color[random_colors];
        std::string jk_r = jokes[random];
        std::string pl_r = punchlines[random];


        if(jokes[random] == jokes[4]){
            std::string response;
            std:: cout << "\033[" << c_r_c << "m" << jk_r << "\033" << std::endl;
            printf("|------------------------\n");
            std::cin >> response;
            printf("------------------------\n");
            time_delay_A();
            std:: cout << "\033[" << c_r_c << "m" << pl_r << "\033" << std::endl;
            printf("|------------------------\n");
        }
        else{
            std::string response;
            std:: cout << "\033[" << c_r_c << "m" << jk_r << "\033" << std::endl;
            printf("|------------------------\n");
            std::cin >> response;
            printf("------------------------\n");
            std:: cout << "\033[" << c_r_c << "m" << pl_r << "\033" << std::endl;
            printf("|------------------------\n");
        }
    }
}
void time_delay_A(){
    sleep_for(3s);
    sleep_until(system_clock::now() + 3s);
}