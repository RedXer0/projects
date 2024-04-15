#include <iostream>
#include <unistd.h>

int main(){
    printf("\033[32m booting into gui...");
    sleep(2);
    system("sudo systemctl set-default graphical.target");
    sleep(2);
    printf("rebooting...");
    sleep(2);
    system("sudo reboot");
}