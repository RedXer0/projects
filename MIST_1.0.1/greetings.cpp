#include <iostream>


// basic friendly greeting that gives you basic system info. 
int greetings(){
    std::string username;
    printf("what would you like to be called?\n");
    std::cin >> username; // gets user name input
    int colors = 36; // colors
    std::cout << "\033[" << colors << "m" << "HIII" << username << "\033" << std::endl; 
     std::cout << "\033[" << colors << "m" << "While you were gone I got your memory and storage data." << "\033" << std::endl;
     printf("||-----------------------------------------\n");
    system("grep MemTotal /proc/meminfo"); // runs system command that prints out your ram to the terminal.
    printf("|-------------------------------------------\n");
    system("df -H"); // runs system command that prints your storage to the terminal.
    printf("|-------------------------------------------\n");
    return 0;
}
