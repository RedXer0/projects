#include <iostream>

int main(){
    std::string file_name;
    std::string file_extension;
    std::string folder;
    int input;

    printf("wanna make a file or folder? (1=folder/2=file\n");
    std::cin >> input;

    switch(input){
        case 1:
            printf("what's the name of the folder?\n");
            std::cin >> folder;
            system(("mkdir " + folder).c_str());
            printf("folder created.\n");
            break;
        case 2:
            printf("what's the name of the file?\n");
            std::cin >> file_name;
            printf("what's the extension of the file?\n");
            std::cin >> file_extension;
            system(("touch " + file_name + "." + file_extension).c_str());
            printf("file has ben created!\n");
            break;
        default:
            printf("invalid input\n");
            break;
    }
    return 0;
}