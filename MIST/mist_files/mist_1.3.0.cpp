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

int main(){
    int color = 36;
    mist_ascii_art();
    std::string name;
    std::string m = "m";
    std::string num = "\033";
    std::string ansi = "\033[";
    std::cout << ansi << color << m << "Welcome to MIST 1.3.0" << num << std::endl;
    sleep_for(milliseconds(TIME));
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