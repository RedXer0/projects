#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include "mist_installation.cpp"
#include <thread>
#include <chrono>


#define TIME  150
using namespace std::chrono;
using namespace std::this_thread;


void mist_ascii_art();
void what_is_mist();

int main(){
    int color = 36;
    mist_ascii_art();
    std::string name;
    std::string m = "m";
    std::string num = "\033";
    std::string ansi = "\033[";
    std::cout << ansi << color << m << "I know what you're thinking... WTF IS A MIST" << num << std::endl;
    sleep_for(milliseconds(TIME));
    what_is_mist();
    installation();

    return 0;
}







void mist_ascii_art(){
  std::string mist[] = {
  " ███▄ ▄███▓ ██▓  ██████ ▄▄▄█████▓",
"▓██▒▀█▀ ██▒▓██▒▒██    ▒ ▓  ██▒ ▓▒",
"▓██    ▓██░▒██▒░ ▓██▄   ▒ ▓██░ ▒░",
"▒██    ▒██ ░██░  ▒   ██▒░ ▓██▓ ░ ",
"▒██▒   ░██▒░██░▒██████▒▒  ▒██▒ ░ ",
"░ ▒░   ░  ░░▓  ▒ ▒▓▒ ▒ ░  ▒ ░░   ",
"░  ░      ░ ▒ ░░ ░▒  ░ ░    ░    ",
"░      ░    ▒ ░░  ░  ░    ░      ",
"       ░    ░        ░           "
};
  for (int i = 0; i < 7; i++){
    int color = 36;
    std::string m = "m";
    std::string num = "\033";
    std::string ansi = "\033[";
    sleep_for(milliseconds(TIME));
    std:: cout << ansi << color << m << mist[i] << num << std::endl;
  }
}

void what_is_mist(){
    std::string mist_is[] = {
        "Mist is a personal terminal assistant that is written in c++.",
        "The idea of mist is to make it easier for you to complete tasks in the terminal.",
        "mist has basic functions like a file search system and a built in calculator.",
        "mist was made by the user RedXer0 and was inspired by the character Mist from Pantheon.",
        "Mist is open sourced and free and can be found at https://github.com/RedXer0/Mist",
        "if you have any questions aabout the mist terminal assistant just type in --help_me.",
        "You'll get a list of all the commands you can use with mist.",
        "That is all for now and welcome to mist Terminal Assistant."
    };

    for (int i = 0; i < 8; i++){
         int color = 36;
        std::string m = "m";
        std::string num = "\033";
        std::string ansi = "\033[";
        sleep_for(milliseconds(TIME));
        std:: cout << ansi << color << m << mist_is[i] << num << std::endl;
    }
}