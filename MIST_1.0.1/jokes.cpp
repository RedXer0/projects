#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <thread>
#include <chrono>


// it tells corny jokes lol.
void jokes(){
    srand(time(NULL));
    std::ifstream file("/path/to/MIST_1.0.1/JOKES_FOLDER/jokes.txt");
    std::ifstream file2("/path/to/MIST_1.0.1/JOKES_FOLDER/punchlines.txt");
    if(file.is_open()){ // opens the joke files
        std::string jokes[7];
        std::string punchlines[7];
        for(int i=0; i<7; i++){
            // puts the joke files into a string aka jokes[7] punchlines[7]
            file >> jokes[i];
            file2 >> punchlines[i]; 
        }

        // random number generator within a range.
        int random = rand() % 7; 
        int random_colors = rand() % 6;

        //colors
        int color[] = {31, 32, 33, 34, 35, 36,};
        //randomizes jokes and colors
        int c_r_c = color[random_colors];
        std::string jk_r = jokes[random];
        std::string pl_r = punchlines[random];


        // if there is a specific gag you want to add to a joke this is where I've put it
        //it singles out a single joke then causes a time delay as a funny gag.
        if(jokes[random] == jokes[4]){
            std::string response;
            std:: cout << "\033[" << c_r_c << "m" << jk_r << "\033" << std::endl;
            printf("|------------------------\n");
            std::cin >> response;
            printf("------------------------\n");
            sleep(3);
            std:: cout << "\033[" << c_r_c << "m" << pl_r << "\033" << std::endl;
            printf("|------------------------\n");
        }
        else{
            // otherwise it just prints the joke normally
            std::string response;
            std:: cout << "\033[" << c_r_c << "m" << jk_r << "\033" << std::endl;
            printf("|------------------------\n");
            std::cin >> response; // input does nothing it just makes it feel interactive.
            printf("------------------------\n");
            std:: cout << "\033[" << c_r_c << "m" << pl_r << "\033" << std::endl;
            printf("|------------------------\n");
        }
    }
}
