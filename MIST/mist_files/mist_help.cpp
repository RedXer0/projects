#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>


#define SIZE 90000
int main(){
std::string help = "MIST/help.txt";
std:: string line;
int i = 0;

std::string help_array[SIZE];

std::ifstream help_file(help);

if(help_file.is_open()){
    while(!help_file.eof()){
        getline(help_file,line);
        help_array[i] = line;
        i++;
    }
    help_file.close();
}

    for (int j = 0; j < 23; j++){
        int ansi_colors = 34;
        std::string colors = "\033[";
        std::cout << colors << ansi_colors << "m" << help_array[j] << "\033" << std::endl;
    }
    return 0;
}
