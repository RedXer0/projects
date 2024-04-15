#include <iostream>
#include <thread>
#include <chrono>
#include "tic-tac-toe.cpp"
#include "games.cpp"
#include "slot_machine.cpp"
#include "number_game.cpp"

#define TIME  150
using namespace std::chrono;
using namespace std::this_thread;

int main(){
    int green = 32;
    int choice;
    int repeat = 1;
    prompt();
    sleep_for(milliseconds(TIME));
    std::cout << "\033[" << green << "m" << "> ";
    

    while(repeat == 1){
        std::cin >> choice;
        switch(choice){
            case 1:
                slot_machine();
                break;
            case 2:
                number_game();
                break;
            case 3:
                main1();
                break;
            default:
                printf("exiting now\n");
                exit(0);
                break;
        }
        printf("wanna play another game? (y/n)\n");
        char x;
        std::cin >> x;
        if(x == 'y' || x == 'Y'){
            main();
        }
        else{
            printf("exiting now\n");
            exit(0);
        }
    }
    return 0;
}