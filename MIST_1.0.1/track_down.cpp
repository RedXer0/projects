#include <iostream>


void accurate_file_search();
void search_by_extension();
void search_type();
int file_hunter(){
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
    int color = 31;
    std::string search_types[] = {
    "1. Accurate File Search.",
    "2. By Extension File Search. ",
    "3. Exit"
    };

    for (int i=0; i<3; i++){
        std::cout << "\033[" << color << "m" << search_types[i] << "\033" << std::endl;
        printf("||--------------------------\n");
    }
}

void accurate_file_search(){
    std::string file_extension;
    std::string file_name;
    int user_input;
    printf(" insert file extension: \n");
    std::cin >> file_extension;
    printf("does the file have a name: 0=no =yes\n");
    std::cin >> user_input;
    switch(user_input){
        case 0:
            break;
        case 1:
            printf("enter file name: \n");
            std::cin >> file_name;
            break;
        default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }

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