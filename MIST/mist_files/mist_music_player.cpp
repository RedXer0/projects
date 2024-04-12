#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <algorithm>
#include <cctype>

#define SIZE 100000

void Mists_Playlist();
int main(){
    
    Mists_Playlist();
    return 0;
}

void Mists_Playlist(){
    int ansi_colors = 34;
    std::string colors = "\033[";
    std::string Mists_Music_Playlist = "/home/xero/MIST/Mists_Music/music_playlist.txt";
    std::string Playlist_Pics = "/home/xero/MIST/mist_media/mists_music_pics.txt";
    std::cout << colors << ansi_colors << "m" << "Mists_Music_Playlist" << std::endl;
    sleep(2);
    std::cout << colors << ansi_colors << "m" << "Hope you like My music taste lol!" << std::endl;
    sleep(2);

    int i = 0;

    std::string Mists_Music_array[SIZE];
    std::string Playlist_Pics_array[SIZE];

    std::ifstream Mists_Music_File(Mists_Music_Playlist);
    std::ifstream Playlist_Pics_File(Playlist_Pics);
    if ((Mists_Music_File, Playlist_Pics_File).is_open()){
        while(!(Mists_Music_File, Playlist_Pics_File).eof()){
            std::string lines_of_text;
            std::string lines_of_text2;
            getline(Mists_Music_File, lines_of_text);
            getline(Playlist_Pics_File, lines_of_text2);
            Mists_Music_array[i] = lines_of_text;
            Playlist_Pics_array[i] = lines_of_text2;
            i++;
        }
        Mists_Music_File.close();
        Playlist_Pics_File.close();
    }
    else{
        std::cout << "Error opening files" << std::endl;
    }

    int random;
    srand(time(NULL));
    while(true){
        random = rand() % 13;
        system(Playlist_Pics_array[random].c_str());
        system(Mists_Music_array[random].c_str());
        printf("\nlike it?\n");
    }
}