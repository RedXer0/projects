#include <iostream>


// main function for mist.cpp
// allows you to make and write to files, it coesn't have to me the cat file editor though.
int make_me(){
    std::string file_name;
    std::string file_extension;
    printf("enter your file name: \n");
    std::cin >> file_name; // file name input.
    printf("enter your file extension: \n");
    std::cin >> file_extension; // file extension input.
    system(("touch " + file_name + "." + file_extension).c_str()); // command to make desired file.
    printf("file has ben created!\n");
    printf("would you like to write to the file? (1=y/0=n)\n");
    int your_input;
    std::cin >> your_input;
    switch(your_input){
        case 1:
            system(("cat > " + file_name + "." + file_extension).c_str()); // allows you to edit the file with the cat command.
            break;
        case 0:
            break; // breaks if you don't want to write to the file.
        default:
            break;
    }
    return 0;
}
