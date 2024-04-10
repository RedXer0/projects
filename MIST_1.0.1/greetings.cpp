#include <iostream>

int greetings(){
    int colors = 36;
    std::cout << "\033[" << colors << "m" << "HIII XERO" << "\033" << std::endl; 
     std::cout << "\033[" << colors << "m" << "While you were gone I got your memory and storage data." << "\033" << std::endl;
     printf("||-----------------------------------------\n");
    system("grep MemTotal /proc/meminfo");
    printf("|-------------------------------------------\n");
    system("df -H");
    printf("|-------------------------------------------\n");
    return 0;
}