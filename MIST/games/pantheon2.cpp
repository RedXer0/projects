#include <iostream>
#include <thread>
#include <chrono>

#define TIME  150
using namespace std::chrono;
using namespace std::this_thread;

void tasks(int color, std::string ansi);
void find_the_solution(int color, std::string ansi);

void middle(){
    int colors[12] = {31, 32, 33, 34, 35, 36, 96, 95, 94, 93, 92, 91};
    std::string ansi = "\033[";

    std::cout << ansi << colors[8] << "m" << "There has to be something in here that can help you." << std::endl;
    tasks(colors[2], ansi);
    find_the_solution(colors[8], ansi);
}

void find_the_solution(int color, std::string ansi){
    int clueA;
    int clueB;
    int clueC;
    std::string key = ";8m";
    int choice;
    int repeat = 1;
    int green = 32;


    while(repeat == 1){
        std::cout << ansi << green << "m" << "> ";
        std::cin >> choice;
        switch(choice){
            case 1:
                if(clueA != 1){
                    printf("You tried picking up the helmet...\n");
                    sleep_for(milliseconds(TIME));
                    printf("you got shocked and put it back down...\n");
                    sleep_for(milliseconds(TIME));
                    printf("maybe you should come back when you find more clues\n");
                    sleep_for(milliseconds(TIME));
                }
                else{
                    printf("you pulled the copper out of the helmets wires!\n");
                    sleep_for(milliseconds(TIME));
                    printf("you molded the copper wire into a conductable rope\n");
                    sleep_for(milliseconds(TIME));
                    clueB = 1;
                }
                break;
            case 2:
                if(clueB!= 1){
                    printf("you checked the drill and found nothing...\n");
                    sleep_for(milliseconds(TIME));
                    printf("The drill feels like it could hold an important clue\n");
                    sleep_for(milliseconds(TIME));
                }
                else{
                    printf("you looked around the drill and found a small button in the back.\n");
                    sleep_for(milliseconds(TIME));
                    printf("you press the button and a latch opens with what seems to be a plug in port\n");
                    sleep_for(milliseconds(TIME));
                    clueC = 1;
                }
                break;
            case 3:
                printf("you ripped the leather seating off of the chair\n");
                sleep_for(milliseconds(TIME));
                printf("you got the foam out of the seat and wrapped it around your hand\n");
                sleep_for(milliseconds(TIME));
                clueA = 1;
                break;
            case 4:
                if(clueC!= 1){
                    printf("you tried kicking down the door but got shocked somehow...\n");
                    sleep_for(milliseconds(TIME));
                    printf("looks like the door is powered by an electrical current\n");
                    sleep_for(milliseconds(TIME));
                    printf("maybe you can use something in this room to open it\n");
                }
                else{
                    printf("you pluged your copper rope into one of the servers in the room.\n");
                    sleep_for(milliseconds(TIME));
                    printf("the drill head opens up and sends out an electrical pulse jamming the doors signal and unlocking it.\n");
                    key = "m";
                    sleep_for(milliseconds(TIME));
                    repeat = 0;
                }
                break;
            default:
                printf("you chose an invalid option\n");
                printf("exiting...\n");
                exit(0);
                break;
        }
        sleep_for(milliseconds(TIME));
        std::cout << ansi << color << key << "you escaped the room\n" << "\033[28m" << std::endl;
    }
}



void tasks(int color, std::string ansi){

    std::string tasks[] = {
        "1. Check helmet for clue.", 
        "2. Check drill for clue.", 
        "3, check chair for clue.", 
        "4. open the door."
        };

    for (int i = 0; i < 4; i++){
        std::cout << ansi << color << "m" << tasks[i] << std::endl;
        sleep_for(milliseconds(TIME));
    }
}