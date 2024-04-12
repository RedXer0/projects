#include <iostream>
#include <thread>
#include <chrono>

#define TIME  150
using namespace std::chrono;
using namespace std::this_thread;

void choices(int color, std::string ansi);
void the_start(int color, std::string ansi);

void beginning(){

    int colors[12] = {31, 32, 33, 34, 35, 36, 96, 95, 94, 93, 92, 91};
    // red / yellow / green / blue / magenta / cyan / bright cyan / pink / light blue / bright yellow / bright red  
    std::string ansi = "\033[";
    the_start(colors[8], ansi);
    choices(colors[2], ansi);
}

void the_start(int color, std::string ansi){
    std::string dialog[] = {
        "You wake up in what seems to be a server room.",
        "Theres a helmet on the floor with wires going into one of the server boxes.",
        "when you turn around you see a table which seems to have what looks to be a giant drill over it."
    };

    for (int i = 0; i < 3; i++){
        sleep_for(milliseconds(TIME));
        std::cout << ansi << color << "m" << dialog[i] << std::endl;
    }
}

void choices(int color, std::string ansi){
    std::string choices[] = {
        "1. Examine drill.",
        "2. Examine helmet.",
        "3. Look for Door.",
        "4. Sit in chair."
    };

    for (int i = 0; i < 4; i++){
        sleep_for(milliseconds(TIME));
        std::cout << ansi << color << "m" << choices[i] << std::endl;
    }

    int choice;
    int repeat = 1;
    int green = 32;

    while (repeat == 1){
        std::cout << ansi << green << "m" << "> ";
        std::cin >> choice;
        switch(choice){
            case 1:
                printf("you examine the drill.\n");
                sleep_for(milliseconds(TIME));
                printf("It's sharp...\n");
                break;
            case 2:
                printf("you examine the helmet.\n");
                sleep_for(milliseconds(TIME));
                printf("The cord seems to have been tampered with.\n");
                break;
            case 3:
                printf("You look for a door.\n");
                sleep_for(milliseconds(TIME));
                printf("The door you found is locked from the outside.\n");
                sleep_for(milliseconds(90));
                printf("maybe you can use something in the room to open the door.\n");
                repeat = 0;
                break;
            case 4:
                printf("You sit in the chair.\n");
                sleep_for(milliseconds(TIME));
                printf("the chair is oddly comftorble.\n");
                break;
            default:
                printf("invalid choice.\n");
                printf("now exiting...\n");
                exit(0);
                break;
        }
    }
    
}