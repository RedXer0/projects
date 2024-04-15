#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define SIZE 100000
int main(){
    int ansi_colors = 34;
    std::string colors = "\033[";
    std::cout << colors << ansi_colors << "m" << "im a little stinker lol" << "\033" << std::endl;
    sleep(3);
    srand(time(NULL));
    std::string jokes = "/home/xero/MIST/JOKES_FOLDER/jokes.txt";
    std::string punchlines = "/home/xero/MIST/JOKES_FOLDER/punchlines.txt";
    std::string lines_of_text1;
    std::string lines_of_text2;

    int i = 0;

    std::string jokes_array[SIZE];
    std::string punchlines_array[SIZE];

    std::ifstream jokes_file(jokes);
    std::ifstream punchlines_file(punchlines);
    if ((jokes_file, punchlines_file).is_open()){
        while(!(jokes_file, punchlines_file).eof()){
            getline(jokes_file, lines_of_text1);
            getline(punchlines_file, lines_of_text2);
            jokes_array[i] = lines_of_text1;
            punchlines_array[i] = lines_of_text2;
            i++;
    }
    jokes_file.close();
    punchlines_file.close();
    }
    else{
        std::cout << "Error opening files" << std::endl;
    }
    int random = rand() % 9;
    std::string response_that_does_nothing;

    if (jokes_array[random] == jokes_array[2]){
        std::cout << jokes_array[random] << std::endl;
        std::cin >> response_that_does_nothing;
        sleep(5);
        std::cout << punchlines_array[random] << std::endl;
        printf(" ");
    }
    else if (jokes_array[random] == jokes_array[8]){
        std::cout << jokes_array[random] << std::endl;
            sleep(5);
            printf("loading...\n");
            sleep(5);
        std::cout << punchlines_array[random] << std::endl;
    }
    else{
        std::cout << jokes_array[random] << std::endl;
        std::cin >> response_that_does_nothing;
        std::cout << punchlines_array[random] << std::endl;
    }
    return 0;
}
