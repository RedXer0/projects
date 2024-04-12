#include <iostream>
#include <thread>
#include <chrono>

#define TIME  1050
using namespace std::chrono;
using namespace std::this_thread;


void accurate_file_search();
void search_by_extension();
void search_type();
int main(){
    int choice;
    search_type();
    std::cin >> choice;

    switch(choice){
        case 1:
            accurate_file_search();
            break;
        case 2:
             search_by_extension();
             break;
        case 3:
            exit(0);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
    return 0;
}

void search_type(){
    int ansi_colors = 34;
    std::string colors = "\033[";
    std::string search_types[] = {
    "1. Accurate File Search.",
    "2. By Extension File Search. ",
    "3. Exit"
    };

    for (int i=0; i<3; i++){
        std::cout << colors << ansi_colors << "m" << search_types[i] << "\033" << std::endl;
        printf("||--------------------------\n");
    }
}

void accurate_file_search(){
    std::string file_extension;
    std::string file_name;
    char user_input;
    printf(" insert file extension: \n");
    std::cin >> file_extension;
    printf("does the file have a name: (y/n)\n");
    std::cin >> user_input;
    switch(user_input){
        case 'n':
            break;
        case 'y':
            printf("enter file name: \n");
            std::cin >> file_name;
            break;
        default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\033[;33;1m\n");
    sleep_for(milliseconds(TIME));
    std::string command = "find /  2>/dev/null ! -readable -prune -o -name \'" + file_name + "." + file_extension + "\' -print -quit";
    system(command.c_str());
    
}

void search_by_extension(){
    std::string file_extension;
    printf("insert file extension: \n");
    std::cin >> file_extension;
    std::string command = "find / 2>/dev/null ! -readable -prune -o -name \"*." + file_extension + "\"" + " -print";

    system(command.c_str());
}