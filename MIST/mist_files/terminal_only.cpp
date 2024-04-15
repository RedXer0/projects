#include <iostream>
#include <stdio.h>
#include <unistd.h>

int main(){
    printf("\033[32m Switching to terminal only mode!");
    sleep(2);
    system("sudo systemctl set-default multi-user.target");
    sleep(2);
    printf("\033[32m Rebooting!");
    system("sudo reboot");
    return 0;
}