#include <iostream>

int make_me(){
    std::string file_name;
    std::string file_extension;
    printf("enter your file name: \n");
    std::cin >> file_name;
    printf("enter your file extension: \n");
    std::cin >> file_extension;
    system(("touch " + file_name + "." + file_extension).c_str());
    printf("file has ben created!\n");
    printf("would you like to write to the file? (1=y/0=n)\n");
    int your_input;
    std::cin >> your_input;
    switch(your_input){
        case 1:
            system(("cat > " + file_name + "." + file_extension).c_str());
            break;
        case 0:
            break;
        default:
            break;
    }
    return 0;
}