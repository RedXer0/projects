#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

void mist();
void tasks();

int list(){
  mist();
  tasks();
  return 0;
}

void tasks(){
  int colors[] = {31,32,33,34,35,36};
  srand(time(NULL));

  std::string tasks[1000] = {
    " 1.Tell a random joke!", 
    " 2.Check system specs!", 
    " 3.give time & date!", 
    " 4. Write/Make a File", 
    " 5.Open Visual Studio Code!", 
    " 6.Open Firefox!", 
    " 7.Open Github!", 
    " 8.Shutdown!", 
    " 9.calculator!", 
    " 10.Games!", 
    " 11.Update!",
    " 12.File Search!",
    " 13. Download linux extensions!",
    " 14. Root access!",
    " 15. Exit"
    };

  for (int i = 0; i < 15; i++){
    int random = rand() % 6;
    std::cout << "\033[" << colors[random] << "m" << tasks[i] << "\033" << std::endl;
    std::cout << "|--------------------" << std::endl;
  }
}

void mist(){
  srand(time(NULL));
  std::string mist[] = {
  "|-------------------------------|",
  "|███    ███ ██ ███████ ████████ |",
  "|████  ████ ██ ██         ██    |",
  "|██ ████ ██ ██ ███████    ██    |",
  "|██  ██  ██ ██      ██    ██    |",
  "|██      ██ ██ ███████    ██    |",
  "|-------------------------------|\n"
  };
  for (int i = 0; i < 7; i++){
    int color = 94;
    std:: cout << "\033[" << color << "m" << mist[i] << "\033" << std::endl;
  }
}