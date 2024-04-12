#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "mist_music_player.cpp"

#define SIZE 100000

int main(){
    int ansi_colors = 36;
    std::string colors = "\033[";
    std::string your_input;
    std::cout << colors << ansi_colors << "m" << "Hey how are you?" << std::endl;
    std::cin >> your_input;
    printf("thats nice\n");
    sleep(1);

    srand(time(NULL));
    std::string chat = "MIST/mist_responses/mist_chat.txt";
    std::string response = "MIST/mist_responses/mist_responses.txt";
    std::string lines_of_text1;
    std::string lines_of_text2;

    int i = 0;

    std::string chat_array[SIZE];
    std::string response_array[SIZE];

    std::ifstream chat_file(chat);
    std::ifstream response_file(response);
    if ((chat_file, response_file).is_open()){
        while(!(chat_file, response_file).eof()){
            getline(chat_file, lines_of_text1);
            getline(response_file, lines_of_text2);
            chat_array[i] = lines_of_text1;
            response_array[i] = lines_of_text2;
            i++;
    }
    chat_file.close();
    response_file.close();
    }
    else{
        std::cout << "Error opening files" << std::endl;
    }
    int random_number = rand() % 16;

    if(chat_array[random_number]== chat_array[5]){
        std::cout << chat_array[random_number] << std::endl;
        std::cin >> your_input;
        std::cout << response_array[random_number] << std::endl;
        std::cin >> your_input;
        sleep(3);
        printf("THE DOOR!!\n");
    }
    else if(chat_array[random_number]== chat_array[7]){
        std::cout << chat_array[random_number] << std::endl;
        std::cin >> your_input;
        std::cout << response_array[random_number] << std::endl;
        sleep(3);
        system("neofetch");
    }
    else if(chat_array[random_number]== chat_array[12]){
        std::cout << chat_array[random_number] << std::endl;
        std::cin >> your_input;
        std::cout << response_array[random_number] << std::endl;
        sleep(3);
         system("mpv MIST/mist_media/Video.mp4");

    }
    else if(chat_array[random_number]== chat_array[14]){
        std::cout << chat_array[random_number] << std::endl;
        std::cin >> your_input;
        if (your_input == "yes"){
            std::cout << response_array[random_number] << std::endl;
            sleep(3);
            system("mpv MIST/Mists_Music/Music/27_Kids.mp3");
            
        }
        else if (your_input != "yes"){
            printf("ok thats cool.\n");
        }
    }
    else{
        std::cout << chat_array[random_number] << std::endl;
        std::cin >> your_input;
        std::cout << response_array[random_number] << std::endl;
    }
    return 0;
    
}
